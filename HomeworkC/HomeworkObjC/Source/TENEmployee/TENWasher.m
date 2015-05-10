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
    [self performWorkWithObject:car];
}

- (void)performWorkWithObject:(id<TENMoneyProtocol>)object {
    self.state = TENEmployeeBusy;
    ((TENCar *)object).clean = YES;
    
    [super performWorkWithObject:object];
    self.state = TENEmployeeFree;
}

@end