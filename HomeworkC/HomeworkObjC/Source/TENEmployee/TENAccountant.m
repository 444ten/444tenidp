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
    NSLog(@"Accountant %@ calculated money: %lu", self.name, (unsigned long)self.money);
}

#pragma mark -
#pragma mark Overload

- (void)processObject:(id<TENMoneyProtocol>)object {
    [self takeMoneyFromPayer:object];
    [self calculateMoney];
    
    [super processObject:object];
}

@end
