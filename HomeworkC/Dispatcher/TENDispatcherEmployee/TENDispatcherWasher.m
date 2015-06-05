//
//  TENDispatcherWasher.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENDispatcherWasher.h"

#import "TENCar.h"

@implementation TENDispatcherWasher

#pragma mark -
#pragma mark Public

- (void)washCar:(TENCar *)car {
    usleep(1000 * arc4random_uniform(1000));
    
    NSLog(@"%@ clear %@", self.name, car.model);
}

#pragma mark -
#pragma mark Overload

- (void)finalizeWorkWithObject:(id)object {
    
}

- (void)processObject:(id)object {
    [self washCar:object];
    [self takeMoney:[object giveMoney]];
}

@end
