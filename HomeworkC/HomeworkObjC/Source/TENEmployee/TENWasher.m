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
#pragma mark Public Methods

- (void)washCar:(TENCar *)car {
    car.clean = YES;
}

- (void)performWorkWithObject:(id<TENMoneyProtocol>)object {
    [super performWorkWithObject:object];
}

#pragma mark -
#pragma mark TENCarDelegate

- (void)car:(TENCar *)car didChangeClean:(BOOL)clean {
    if (clean) {
        [self performWorkWithObject:car];
    }
}

@end