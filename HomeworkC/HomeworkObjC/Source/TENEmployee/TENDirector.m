//
//  TENDirector.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENDirector.h"

@implementation TENDirector

#pragma mark -
#pragma mark Public Methods

- (void)takeProfit {
    NSLog(@"Director %@ took profit: %lu", self.name, self.money);
}

#pragma mark -
#pragma mark Overload

- (void)processObject:(id<TENMoneyProtocol>)object {
    [self takeMoneyFromPayer:object];
    [self takeProfit];
}

@end
