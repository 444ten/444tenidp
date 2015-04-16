//
//  TENEmployeeWasher.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEmployeeWasher.h"

#import "TENCar.h"

@interface TENEmployeeWasher ()

- (BOOL)washCar:(TENCar *)car;
- (BOOL)takeMoney:(NSUInteger)money fromCar:(TENCar *)car;

@end

@implementation TENEmployeeWasher

#pragma mark -
#pragma mark Public Methods

- (BOOL)workWithCar:(TENCar *)car {
    if ([self washCar:car]) {
        if ([self takeMoney:20 fromCar:car]) {
            return true;
        }
    }
    
    return false;
}

#pragma mark -
#pragma mark Private Methods

- (BOOL)washCar:(TENCar *)car {
    if (false == car.isClean) {
        car.clean = true;
        
        return true;
    }
    
    return false;
}
- (BOOL)takeMoney:(NSUInteger)money fromCar:(TENCar *)car {
    if (money <= car.money) {
        self.money += money;
        car.money -= money;
        
        return true;
    }
    
    return false;
}

@end
