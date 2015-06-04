//
//  TENDispatcherDirector.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENDispatcherDirector.h"

@implementation TENDispatcherDirector

#pragma mark -
#pragma mark Public Methods

- (void)takeProfit {
    sleep(1);
    NSLog(@"%@ took profit: %lu", self.name, self.money);
}

#pragma mark -
#pragma mark Overload

- (void)processObject:(id)object {
    [self takeMoney:[object giveMoney]];
    [self takeProfit];
}

@end
