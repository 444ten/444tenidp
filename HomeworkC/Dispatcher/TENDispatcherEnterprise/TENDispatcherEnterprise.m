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

static const NSUInteger TENDirectorCount        = 1;
static const NSUInteger TENAccountantCount      = 2;
static const NSUInteger TENWasherCount          = 3;

static const NSUInteger TENNumberOfCarsInSeries = 5;
static const NSUInteger TENTotalCars            = TENNumberOfCarsInSeries * 100;

@interface TENDispatcherEnterprise()
@property (nonatomic, retain)   NSMutableSet    *mutableEmployeeSet;

@property (nonatomic, retain)   TENDispatcher   *directorsDispatcher;
@property (nonatomic, retain)   TENDispatcher   *accountantsDispatcher;
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
    
    self.directorsDispatcher = nil;
    self.accountantsDispatcher = nil;
    self.washersDispatcher = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployeeSet = [NSMutableSet set];
        
        self.directorsDispatcher  = [[[TENDispatcher alloc] init] autorelease];;
        self.accountantsDispatcher  = [TENDispatcher object];
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
            TENCar *car = [TENCar carWithIndex:carsCount];
            car.money = carsCount;
            
            [self performSelectorInBackground:@selector(workWithCarInBackground:) withObject:car];
        }
        NSLog(@"%lu car enqueued", carsCount);
        
        usleep(1000 * 100);
    }
}

- (void)workWithCarInBackground:(TENCar *)car {
    if (nil == car) {
        return;
    }
    
    [self.washersDispatcher processObject:car];
}

- (void)removeObservers {
    NSSet *employees = self.employeeSet;
    for (TENDispatcherEmployee *employee in employees) {
        [employee removeObserver:self];
    }
}

- (void)hireStaff {
    NSMutableSet *employees = self.mutableEmployeeSet;
    
    
    for (NSUInteger iterator = 0; iterator < TENDirectorCount; iterator++) {
        
        TENDispatcherDirector *director = [TENDispatcherDirector employeeWithIndex:iterator];
        [director addObserver:self];
        [self.directorsDispatcher addHandler:director];
        [employees addObject:director];
    }

    for (NSUInteger iterator = 0; iterator < TENAccountantCount; iterator++) {
        
        TENDispatcherAccountant *accountant = [TENDispatcherAccountant employeeWithIndex:iterator];
        [accountant addObserver:self];
        [self.accountantsDispatcher addHandler:accountant];
        [employees addObject:accountant];
    }
    
    for (NSUInteger iterator = 0; iterator < TENWasherCount; iterator++) {

        TENDispatcherWasher *washer = [TENDispatcherWasher employeeWithIndex:iterator];
        [washer addObserver:self];
        [self.washersDispatcher addHandler:washer];
        [employees addObject:washer];
    }
}

#pragma mark -
#pragma mark TENEmployeeObserver

- (void)employeeDidBecomeReadyForMoneyOperation:(TENDispatcherEmployee *)employee {
    if ([employee isMemberOfClass:[TENDispatcherWasher class]]) {
        [self.accountantsDispatcher processObject:employee];
    } else if ([employee isMemberOfClass:[TENDispatcherAccountant class]]) {
        [self.directorsDispatcher processObject:employee];
    } else {
        employee.state = TENEmployeeFree;
    }
}

@end
