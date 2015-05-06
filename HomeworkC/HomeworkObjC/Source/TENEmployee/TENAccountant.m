//
//  TENAccountant.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENAccountant.h"

@implementation TENAccountant

- (void)calculateMoney {
    NSLog(@"Accountant %@ calculated money: %lu", self.name, self.money);
}

- (void)performWorkWithObject:(id<TENMoneyProtocol>)object {
    [super performWorkWithObject:object];

    [self calculateMoney];
}

@end
