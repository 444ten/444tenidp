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
    NSLog(@"%@ took profit: %lu", self.name, self.money);
}

#pragma mark -
#pragma mark Overload

- (void)finalizeWorkWithObject:(id)object {
    [super finalizeWorkWithObject:object];

    self.state = TENEmployeeFree;
}

- (void)processObject:(id)object {
    [self takeMoneyFromPayer:object];
    [self takeProfit];
}

@end
