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

- (void)performNotification;

@end

@implementation TENEmployee

@synthesize money = _money;

#pragma mark -
#pragma mark Class

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
        [self ready];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setState:(TENEmployeeState)state {
    if (_state != state) {
        _state = state;
        [self performNotification];
    }
    
}

#pragma mark -
#pragma mark Public

- (void)performWorkWithObject:(id<TENMoneyProtocol>)object {
    [self takeMoneyFromPayer:object];
}

- (void)ready {
    self.state = TENEmployeeReady;
}

- (void)busy {
    self.state = TENEmployeeBusy;
}

#pragma mark -
#pragma mark Private

- (void)performNotification {
    [self.delegate employeeDidChange:self];
}

#pragma mark -
#pragma mark TENMoneyProtocol

- (void)takeMoneyFromPayer:(id<TENMoneyProtocol>)payer {
    self.money += payer.money;
    payer.money = 0;
}

#pragma mark -
#pragma mark TENEmployeeDelegate

- (void)employeeDidChange:(TENEmployee *)employee {
    if ([self respondsToSelector:@selector(employeeShouldChange:)]) {
        if ([self employeeShouldChange:employee]) {
            [self performWorkWithObject:employee];
        }
    }
    
}

- (BOOL)employeeShouldChange:(TENEmployee *)employee {
    return TENEmployeeReady == employee.state;
}

@end
