//
//  TENWasher.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENWasher.h"

#import "TENCar.h"

@implementation TENWasher

#pragma mark -
#pragma mark Public

- (void)washCar:(TENCar *)car {
    car.state = TENCarCleanAndReady;
}

#pragma mark -
#pragma mark Overload

- (void)performWorkWithObject:(id<TENMoneyProtocol>)object {
    self.state = TENEmployeePerformWork;
    [self washCar:object];
    
    [super performWorkWithObject:object];
    self.state = TENEmployeeReadyGiveMoney;
    self.state = TENEmployeeFree;
}

@end
