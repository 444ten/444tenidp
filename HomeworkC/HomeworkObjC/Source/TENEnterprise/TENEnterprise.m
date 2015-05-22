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
#import "TENWasher.h"

static const NSUInteger TENWasherCount      = 5;

static  NSString * const kTENDirectorName   = @"Director";
static  NSString * const kTENAccountantName = @"Accountant";
static  NSString * const kTENWasherName     = @"Washer";

@interface TENEnterprise()
@property (nonatomic, retain)   NSMutableSet    *mutableEmployeeSet;
@property (nonatomic, retain)   NSMutableArray  *mutableCars;

- (void)removeObservers;
- (void)hireStaff;

- (void)work;

- (NSSet *)employeesWithClass:(Class)class;
- (id)freeEmployeeWithClass:(Class)class;

- (TENCar *)nextCarFromQueue;

@end

@implementation TENEnterprise

@dynamic employeeSet;
@dynamic cars;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self removeObservers];
    
    self.mutableEmployeeSet = nil;
    self.mutableCars = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployeeSet = [NSMutableSet set];
        self.mutableCars = [NSMutableArray array];
        
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)employeeSet {
    return [[self.mutableEmployeeSet copy] autorelease];
}

- (NSArray *)cars {
    return [[self.mutableCars copy] autorelease];
}
#pragma mark -
#pragma mark Public

- (void)addCar:(TENCar *)car {
    if (car) {
        [self.mutableCars addObject:car];
        [self work];
    }
}

- (void)removeCar:(TENCar *)car {
    [self.mutableCars removeObject:car];
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
    
    for (NSUInteger iterator = 0; iterator < TENWasherCount; iterator++) {
        NSMutableString *nameWasher = [NSMutableString stringWithString:kTENWasherName];
        [nameWasher appendString:[NSString stringWithFormat:@"_%lu", iterator]];

        TENWasher *washer = [TENWasher employeeWithName:nameWasher];
        [washer addObserver:accountant];
        [washer addObserver:self];
        [employees addObject:washer];
    }
}

- (void)work {
    TENWasher *washer = [self freeEmployeeWithClass:[TENWasher class]];
    if (washer) {
        [washer performWorkWithObject:[self nextCarFromQueue]];
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
//    NSSet *employees = [self employeesWithClass:class];
//    
//    for (TENEmployee *employee in employees) {
//        if (TENEmployeeFree == employee.state) {
//            return employee;
//        }
//    }
//    
//    return nil;
    
    NSSet *employees = [self employeesWithClass:class];
    NSMutableArray *mutableEmployees = [NSMutableArray array];
    
    for (TENEmployee *employee in employees) {
        if (TENEmployeeFree == employee.state) {
            [mutableEmployees addObject:employee];
        }
    }
    
    uint32_t randomIndex = arc4random_uniform((uint32_t)[mutableEmployees count]);
    return mutableEmployees[randomIndex];
}


- (TENCar *)nextCarFromQueue {
    TENCar *result = [[[self.mutableCars firstObject] retain] autorelease];
    [self removeCar:result];
    
    return result;
}

#pragma mark -
#pragma mark TENEmployeeObserver

- (void)employeeDidBecomeFree:(TENEmployee *)employee {
    [employee performWorkWithObject:[self nextCarFromQueue]];
}

@end
