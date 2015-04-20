//
//  TENEmployeeWasher.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEmployeeWasher.h"

#import "TENCar.h"

@implementation TENEmployeeWasher

#pragma mark -
#pragma mark Public Methods

- (void)washCar:(TENCar *)car {
    car.clean = true;
}

- (void)takeMoney:(NSUInteger)money fromCar:(TENCar *)car {
    if (money <= car.money) {
        self.money += money;
        car.money -= money;
    }
}

@end