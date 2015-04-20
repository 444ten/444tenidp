//
//  TENEmployeeDirector.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEmployeeDirector.h"

@implementation TENEmployeeDirector

#pragma mark -
#pragma mark Public Methods

- (void)takeProfit {
    NSLog(@"Director %@ took profit: %lu", self.name, self.money);
}

@end
