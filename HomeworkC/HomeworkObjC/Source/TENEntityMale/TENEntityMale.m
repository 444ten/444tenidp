//
//  TENEntityMale.m
//  HomeworkC
//
//  Created by 444ten on 4/14/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEntityMale.h"

@implementation TENEntityMale

#pragma mark -
#pragma mark Public Methods

- (void)fighting {
    NSLog(@"%@ fighting", [self name]);
}

- (void)performGenderSpecificOperation {
    [self fighting];
}

@end
