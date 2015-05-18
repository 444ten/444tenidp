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
@property (nonatomic, retain)   TENDirector     *director;
@property (nonatomic, retain)   TENAccountant   *accountant;
@property (nonatomic, retain)   NSMutableArray  *mutableWashers;
@property (nonatomic, retain)   NSMutableArray  *queueWashers;

- (void)hireStaff;

@end

@implementation TENEnterprise

@dynamic employees;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.director = nil;
    self.accountant = nil;
    self.mutableWashers = nil;
    self.queueWashers = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)employees {
    NSMutableArray *employees = [NSMutableArray arrayWithArray:self.mutableWashers];
    [employees addObject:self.accountant];
    [employees addObject:self.director];
    
    return [[employees copy] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)workWithCar:(TENCar *)car {
    TENWasher *washer = self.queueWashers[0];
    [self.queueWashers removeObjectAtIndex:0];
    [washer performWorkWithObject:car];
}

#pragma mark -
#pragma mark Private

- (void)hireStaff {
    self.director = [TENDirector employeeWithName:kTENDirectorName];
    self.accountant = [TENAccountant employeeWithName:kTENAccountantName];
    self.mutableWashers = [NSMutableArray arrayWithCapacity:TENWasherCount];
    
    TENDirector *director = self.director;
    TENAccountant *accountant = self.accountant;
    NSMutableArray *washers = self.mutableWashers;
    
    
    for (NSUInteger iterator = 0; iterator < TENWasherCount; iterator++) {
        NSMutableString *nameWasher = [NSMutableString stringWithString:kTENWasherName];
        [nameWasher appendString:[NSString stringWithFormat:@"_%lu", iterator]];

        TENWasher *washer = [TENWasher employeeWithName:nameWasher];
//        washer.delegate = accountant;
        [washers addObject:washer];
    }
    
    self.queueWashers = [NSMutableArray arrayWithArray:washers];
    
//    accountant.delegate = director;
}

@end
