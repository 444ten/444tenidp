//
//  TENEmployee.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEmployee.h"

@interface TENEmployee()

@end

@implementation TENEmployee

#pragma mark -
#pragma mark Public Methods

- (void)transferMoney:(NSUInteger)money toEmployee:(TENEmployee *)employee {
    if (money <= self.money) {
        self.money -= money;
        employee.money += money;
    }
}

@end




