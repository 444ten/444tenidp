//
//  TENEmployee.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEmployee.h"

@implementation TENEmployee

#pragma mark -
#pragma mark Class Methods

+ (instancetype)employee {
    return [self employeeWithName:@"noname" salary:0];
}

+ (instancetype)employeeWithName:(NSString *)name salary:(NSUInteger)salary{
    return [[[self alloc] initWithName:name salary:salary] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithName:(NSString *)name salary:(NSUInteger)salary {
    self = [super init];
    
    if (self) {
        self.name = name;
        self.salary = salary;
        self.experience = 0;
        self.money = 0;
    }
    
    return self;
}

- (void)dealloc {
    self.name = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors Methods

#pragma mark -
#pragma mark Public Methods

- (BOOL)money:(NSUInteger)money toEmployee:(TENEmployee *)employee {
    if (money <= self.money) {
        self.money -= money;
        employee.money += money;
        
        return true;
    }
        
    return false;
}

@end




