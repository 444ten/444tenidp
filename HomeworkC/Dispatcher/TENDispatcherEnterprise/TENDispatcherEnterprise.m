//
//  TENDispatcherEnterprise.m
//  HomeworkC
//
//  Created by 444ten on 4/22/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENDispatcherEnterprise.h"

#import "NSObject+TENExtensions.h"
#import "TENCar.h"
#import "TENDispatcher.h"
#import "TENDispatcherAccountant.h"
#import "TENDispatcherDirector.h"
#import "TENDispatcherWasher.h"
#import "TENQueue.h"

static const NSUInteger TENWasherCount          = 4;
static const NSUInteger TENNumberOfCarsInSeries  = 5;
static const NSUInteger TENTotalCars            = TENNumberOfCarsInSeries * 4;

static  NSString * const kTENDirectorName   = @"  Director";
static  NSString * const kTENAccountantName = @" Accountant";
static  NSString * const kTENWasherName     = @"Washer";

@interface TENDispatcherEnterprise()
@property (nonatomic, retain)   NSMutableSet    *mutableEmployeeSet;

@property (nonatomic, retain)   TENDispatcher   *washersDispatcher;

- (void)addCarInBackground;
- (void)workWithCarInBackground:(TENCar *)car;

- (void)removeObservers;
- (void)hireStaff;

@end

@implementation TENDispatcherEnterprise

@dynamic employeeSet;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self removeObservers];
    
    self.mutableEmployeeSet = nil;
    self.washersDispatcher = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployeeSet = [NSMutableSet set];
        self.washersDispatcher = [TENDispatcher object];

        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)employeeSet {
    return [[self.mutableEmployeeSet copy] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)start {
    [self performSelectorInBackground:@selector(addCarInBackground) withObject:nil];
}

#pragma mark -
#pragma mark Private

- (void)addCarInBackground {
    NSUInteger carsCount = 0;
    
    while (carsCount < TENTotalCars) {
        for (NSUInteger iterator = 0; iterator < TENNumberOfCarsInSeries; iterator++) {
            carsCount += 1;
            
            NSMutableString *model = [NSMutableString stringWithString:@"car_"];
            [model appendString:[NSString stringWithFormat:@"_%lu", carsCount]];
            
            TENCar *car = [TENCar carWithModel:model];
            car.money = carsCount;
            
            [self performSelectorInBackground:@selector(workWithCarInBackground:) withObject:car];
        }
        NSLog(@"%lu car enqueued", carsCount);
        sleep(1);
    }
}

- (void)workWithCarInBackground:(TENCar *)car {
    if (nil == car) {
        return;
    }
    
    @synchronized (self) {
        [self.washersDispatcher addObjectToProcess:car];
    }
}

- (void)removeObservers {
    NSSet *employees = self.employeeSet;
    for (TENDispatcherEmployee *employee in employees) {
        [employee removeObserver:self];
    }
}

- (void)hireStaff {
    NSMutableSet *employees = self.mutableEmployeeSet;
    TENDispatcherDirector *director = [TENDispatcherDirector employeeWithName:kTENDirectorName];
    TENDispatcherAccountant *accountant = [TENDispatcherAccountant employeeWithName:kTENAccountantName];
    
    [employees addObject:director];
    [employees addObject:accountant];
//    [accountant addObserver:director];
//    [accountant addObserver:accountant];
    
    for (NSUInteger iterator = 0; iterator < TENWasherCount; iterator++) {
        NSMutableString *nameWasher = [NSMutableString stringWithString:kTENWasherName];
        [nameWasher appendString:[NSString stringWithFormat:@"_%lu", iterator]];

        TENDispatcherWasher *washer = [TENDispatcherWasher employeeWithName:nameWasher];
        [washer addObserver:self];
        [self.washersDispatcher addHandler:washer];
        [employees addObject:washer];
    }
}


#pragma mark -
#pragma mark TENEmployeeObserver

- (void)employeeDidBecomeReadyForMoneyOperation:(TENDispatcherEmployee *)employee {
    @synchronized (self) {
        employee.state = TENEmployeeFree;
    }
}

//- (void)employeeDidBecomeFree:(TENDispatcherEmployee *)employee {
//    @synchronized (self) {
//        if (TENEmployeeFree == employee.state) {
//            NSLog(@"(s)%@ -> %@", employee.name, NSStringFromSelector(_cmd));
////            [employee performWorkWithObject:[self.carQueue dequeueObject]];
//        }
//    }    
//}

@end
