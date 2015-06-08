//
//  TENGCDAccountant.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENGCDAccountant.h"

@implementation TENGCDAccountant

#pragma mark -
#pragma mark Public

- (void)calculateMoney {
    NSLog(@"%@ calculated money: %lu", self.name, (unsigned long)self.money);
}

#pragma mark -
#pragma mark Overload

- (void)processObject:(id)object {
    [self takeMoney:[object giveMoney]];
    [self calculateMoney];
}

@end
