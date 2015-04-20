//
//  TENEmployee.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEmployee.h"

@interface TENEmployee()
@property (nonatomic, copy, readwrite)  NSString    *name;

@end

@implementation TENEmployee

#pragma mark -
#pragma mark Class Methods

+ (instancetype)employeeWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    
    if (self) {
        self.name = name;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors Methods

- (NSString *)name {
    return [NSString stringWithString:_name];
}

#pragma mark -
#pragma mark Public Methods

- (void)transferMoney:(NSUInteger)money toEmployee:(TENEmployee *)employee {
    if (money <= self.money) {
        self.money -= money;
        employee.money += money;
    }
}

@end




