//
//  TENWasher.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENWasher.h"

#import "TENCar.h"

@interface TENWasher ()

- (void)notifyOfStateChangeWithSelector:(SEL)selector;

@end


@implementation TENWasher

#pragma mark -
#pragma mark Public

- (void)washCar:(TENCar *)car {
    car.state = TENCarCleanAndReady;
    NSLog(@"washer %@ clear car %@", self.name, car.model);
}

- (SEL)selectorForState:(TENEmployeeState)state {
    switch (state) {
        case TENEmployeeFree:
            return @selector(washerDidBecomeFree:);
            
        case TENEmployeePerformWork:
            return @selector(washerDidBecomePerformWork:);
            
        case TENEmployeeReadyMoneyOperation:
            return @selector(washerDidBecomeReadyMoneyOperation:);
    }

    return nil;
}

#pragma mark -
#pragma mark Private

- (void)notifyOfStateChangeWithSelector:(SEL)selector {
    [self.delegate performSelector:selector withObject:self];
}

#pragma mark -
#pragma mark Overload

- (void)performSpecificOperationWithObject:(id<TENMoneyProtocol>)object {
    [self washCar:object];
    [self takeMoneyFromPayer:object];
}

@end
