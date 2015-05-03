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
    car.clean = true;
}

- (void)takeMoney:(NSUInteger)money fromPayer:(id<TENMoneyProtocol>)payer {
    if (money <= payer.money) {
        self.money += money;
        payer.money -= money;
    }
}


@end