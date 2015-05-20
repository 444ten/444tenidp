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
@property (nonatomic, retain)   TENCar          *processedCar;

- (void)hireStaff;
- (id)freeEmployeeWithClass:(Class)class;
- (void)removeObservers;

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

- (void)workWithCar:(TENCar *)car {
    TENWasher *washer = [self freeEmployeeWithClass:[TENWasher class]];
    if (washer) {
        [car retain];
        
        [self removeCar:car];
        [washer performWorkWithObject:car];
        
        [car release];
    }
}

- (void)addCar:(TENCar *)car {
    if (car) {
        [self.mutableCars addObject:car];
        [self workWithCar:car];
    }
}

- (void)removeCar:(TENCar *)car {
    [self.mutableCars removeObject:car];
}

#pragma mark -
#pragma mark Private

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

- (id)freeEmployeeWithClass:(Class)class {
//    NSSet *employees = self.mutableEmployeeSet;
//    
//    for (TENEmployee *employee in employees) {
//        if (class == [employee class] && TENEmployeeFree == employee.state) {
//            return employee;
//        }
//    }
//    
//    return nil;
    
    NSSet *employees = self.mutableEmployeeSet;
    NSMutableArray *mutableEmployees = [NSMutableArray array];
    
    for (TENEmployee *employee in employees) {
        if (class == [employee class] && TENEmployeeFree == employee.state) {
            [mutableEmployees addObject:employee];
        }
    }
    
    uint32_t randomIndex = arc4random_uniform((uint32_t)[mutableEmployees count]);
    return mutableEmployees[randomIndex];
}

- (void)removeObservers {
    NSSet *employees = self.mutableEmployeeSet;
    
    TENDirector *director = nil;
    TENAccountant *accountant = nil;
    NSMutableArray *washers = [NSMutableArray arrayWithCapacity:[employees count] - 2];
    
    for (id employee in employees) {
        if ([employee isMemberOfClass:[TENWasher class]]) {
            [washers addObject:employee];
        } else if ([employee isMemberOfClass:[TENDirector class]]) {
            director = employee;
        } else if ([employee isMemberOfClass:[TENAccountant class]]) {
            accountant = employee;
        }
    }
    
    [accountant removeObserver:director];
    
    for (TENWasher *washer in washers) {
        [washer removeObserver:accountant];
        [washer removeObserver:self];
    }
}


#pragma mark -
#pragma mark TENEmployeeObserver

- (void)employeeDidBecomeFree:(TENEmployee *)employee {
    self.processedCar = [self.mutableCars firstObject];
    
    TENCar *car = [self.mutableCars firstObject];
    
    if (car) {
        [self workWithCar:car];
    }
}

@end
