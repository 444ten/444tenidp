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
    NSLog(@"washer %@ clear car %@", self.name, car.model);
}

#pragma mark -
#pragma mark Overload

- (void)performWorkWithObject:(id<TENMoneyProtocol>)object {
    if (object) {
//        @synchronized (self) {
            self.state = TENEmployeePerformWork;

            [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                                   withObject:object];
//        }
    }
}


- (void)processObject:(id<TENMoneyProtocol>)object {
    [self washCar:object];
    [self takeMoneyFromPayer:object];
}

@end
