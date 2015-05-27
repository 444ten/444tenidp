//
//  TENAccountant.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENAccountant.h"

@implementation TENAccountant

#pragma mark -
#pragma mark Public

- (void)calculateMoney {
    usleep(1000 * arc4random_uniform(10));

    NSLog(@"%@ calculated money: %lu", self.name, (unsigned long)self.money);
}

#pragma mark -
#pragma mark Overload

- (void)processObject:(id)object {
    [self takeMoneyFromPayer:object];
    [self calculateMoney];
}

@end
