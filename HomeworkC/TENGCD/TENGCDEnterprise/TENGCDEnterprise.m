//
//  TENGCDEnterprise.m
//  HomeworkC
//
//  Created by 444ten on 4/22/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENGCDEnterprise.h"

#import "NSObject+TENExtensions.h"
#import "TENCar.h"
#import "TENGCDDispatcher.h"
#import "TENGCDAccountant.h"
#import "TENGCDDirector.h"
#import "TENGCDWasher.h"
#import "TENQueue.h"

static const NSUInteger TENDirectorCount        = 1;
static const NSUInteger TENAccountantCount      = 2;
static const NSUInteger TENWasherCount          = 3;

static const NSUInteger TENNumberOfCarsInSeries = 5;
static const NSUInteger TENTotalCars            = TENNumberOfCarsInSeries * 10;

@interface TENGCDEnterprise()
@property (nonatomic, retain)   NSMutableSet    *mutableEmployeeSet;

@property (nonatomic, retain)   TENGCDDispatcher   *directorsDispatcher;
@property (nonatomic, retain)   TENGCDDispatcher   *accountantsDispatcher;
@property (nonatomic, retain)   TENGCDDispatcher   *washersDispatcher;

- (void)addCarInBackground;
- (void)workWithCarInBackground:(TENCar *)car;

- (void)removeObservers;
- (void)hireStaff;

@end

@implementation TENGCDEnterprise

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
        
        self.directorsDispatcher  = [TENGCDDispatcher object];;
        self.accountantsDispatcher  = [TENGCDDispatcher object];
        self.washersDispatcher = [TENGCDDispatcher object];

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
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        [self addCarInBackground];
    });
    
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

            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
                [self workWithCarInBackground:car];
            });
        }
        NSLog(@"%lu car enqueued", carsCount);
        
        usleep(1000 * 1000);
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
    for (TENGCDEmployee *employee in employees) {
        [employee removeObserver:self];
    }
}

- (void)hireStaff {
    NSMutableSet *employees = self.mutableEmployeeSet;
    
    for (NSUInteger iterator = 0; iterator < TENDirectorCount; iterator++) {
        TENGCDDirector *director = [TENGCDDirector employeeWithIndex:iterator];
        [director addObserver:self];
        [self.directorsDispatcher addHandler:director];
        [employees addObject:director];
    }

    for (NSUInteger iterator = 0; iterator < TENAccountantCount; iterator++) {
        TENGCDAccountant *accountant = [TENGCDAccountant employeeWithIndex:iterator];
        [accountant addObserver:self];
        [self.accountantsDispatcher addHandler:accountant];
        [employees addObject:accountant];
    }
    
    for (NSUInteger iterator = 0; iterator < TENWasherCount; iterator++) {
        TENGCDWasher *washer = [TENGCDWasher employeeWithIndex:iterator];
        [washer addObserver:self];
        [self.washersDispatcher addHandler:washer];
        [employees addObject:washer];
    }
}

#pragma mark -
#pragma mark TENEmployeeObserver

- (void)employeeDidBecomeReadyForMoneyOperation:(TENGCDEmployee *)employee {
    if ([employee isMemberOfClass:[TENGCDDirector class]]) {
        employee.state = TENEmployeeFree;

        return;
    }
    
    TENGCDDispatcher *dispatcher   = [employee isMemberOfClass:[TENGCDWasher class]]
                                ? self.accountantsDispatcher
                                : self.directorsDispatcher;

    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        [dispatcher processObject:employee];
    });
}

@end
