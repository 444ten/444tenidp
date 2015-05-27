//
//  TENEnterprise.m
//  HomeworkC
//
//  Created by 444ten on 4/22/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEnterprise.h"

#import "NSObject+TENExtensions.h"
#import "TENAccountant.h"
#import "TENCar.h"
#import "TENDirector.h"
#import "TENQueue.h"
#import "TENWasher.h"
#import "TENDispatcher.h"

static const NSUInteger TENWasherCount      = 3;

static  NSString * const kTENDirectorName   = @"  Director";
static  NSString * const kTENAccountantName = @" Accountant";
static  NSString * const kTENWasherName     = @"Washer";

@interface TENEnterprise()
@property (nonatomic, retain)   NSMutableSet    *mutableEmployeeSet;
@property (nonatomic, retain)   TENQueue        *queueCars;

- (void)removeObservers;
- (void)hireStaff;


- (NSSet *)employeesWithClass:(Class)class;
- (id)freeEmployeeWithClass:(Class)class;

@end

@implementation TENEnterprise

@dynamic employeeSet;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self removeObservers];
    
    self.mutableEmployeeSet = nil;
    self.queueCars = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployeeSet = [NSMutableSet set];
        self.queueCars = [[TENQueue new] autorelease];
        
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

- (void)work {
    TENDispatcher *dispatcher = [TENDispatcher dispatcherWithQueueCars:self.queueCars];
    [dispatcher work];
    sleep(3);
    
    @synchronized (self) {
        TENWasher *washer = [self freeEmployeeWithClass:[TENWasher class]];
        if (washer) {
            [washer performWorkWithObject:[self.queueCars dequeueObject]];
        }
    }
}

#pragma mark -
#pragma mark Private

- (void)removeObservers {
    TENDirector *director = [[self employeesWithClass:[TENDirector class]] anyObject];
    TENAccountant *accountant = [[self employeesWithClass:[TENAccountant class]] anyObject];
    [accountant removeObserver:director];
    
    NSSet *washers = [self employeesWithClass:[TENWasher class]];
    for (TENWasher *washer in washers) {
        [washer removeObserver:accountant];
        [washer removeObserver:self];
    }
}

- (void)hireStaff {
    NSMutableSet *employees = self.mutableEmployeeSet;
    TENDirector *director = [TENDirector employeeWithName:kTENDirectorName];
    TENAccountant *accountant = [TENAccountant employeeWithName:kTENAccountantName];
    
    [employees addObject:director];
    [employees addObject:accountant];
    [accountant addObserver:director];
    [accountant addObserver:accountant];
    
    for (NSUInteger iterator = 0; iterator < TENWasherCount; iterator++) {
        NSMutableString *nameWasher = [NSMutableString stringWithString:kTENWasherName];
        [nameWasher appendString:[NSString stringWithFormat:@"_%lu", iterator]];

        TENWasher *washer = [TENWasher employeeWithName:nameWasher];
        [washer addObserver:accountant];
        [washer addObserver:self];
        [employees addObject:washer];
    }
}

- (NSSet *)employeesWithClass:(Class)class {
    NSSet *employees = self.employeeSet;
    NSMutableSet *result = [NSMutableSet setWithCapacity:[employees count]];
    for (id employee in employees) {
        if ([employee isMemberOfClass:class]) {
            [result addObject:employee];
        }
    }
    
    return [[result copy] autorelease];
}

- (id)freeEmployeeWithClass:(Class)class {
    NSSet *employees = [self employeesWithClass:class];
    
    for (TENEmployee *employee in employees) {
        if (TENEmployeeFree == employee.state) {
            return employee;
        }
    }
    
    return nil;    
}

#pragma mark -
#pragma mark TENEmployeeObserver

- (void)employeeDidBecomeFree:(TENEmployee *)employee {
    @synchronized (self) {
        if (TENEmployeeFree == employee.state) {
            NSLog(@"(s)%@ -> %@", employee.name, NSStringFromSelector(_cmd));
            [employee performWorkWithObject:[self.queueCars dequeueObject]];
        }
    }    
}

@end
