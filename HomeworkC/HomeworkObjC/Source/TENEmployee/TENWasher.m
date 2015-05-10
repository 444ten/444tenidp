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
    self.state = TENEmployeeBusy;
    [super performWorkWithObject:object];
    self.state = TENEmployeeFree;
}

#pragma mark -
#pragma mark TENCarDelegate

- (void)carDidChange:(TENCar *)car {
    if ([self carShouldChange:car]) {
        [self performWorkWithObject:car];
    }
}

- (BOOL)carShouldChange:(TENCar *)car {
    return car.isClean;
}

@end