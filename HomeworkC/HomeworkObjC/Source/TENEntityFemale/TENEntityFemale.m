//
//  TENEntityFemale.m
//  HomeworkC
//
//  Created by 444ten on 4/14/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEntityFemale.h"
#import "TENEntityMale.h"

@implementation TENEntityFemale

#pragma mark -
#pragma mark Public Methods

- (id)makeChildWithGender:(TENGender)gender
                     name:(NSString *)name
                   weight:(double)weight
{
    Class class = (gender == TENGenderMale) ? [TENEntityMale class] : [TENEntityFemale class];
    
    return [class entityWithName:name age:0 weight:weight];
}

- (void)performGenderSpecificOperation {
    NSLog(@"%@ gave birth to a newborn...", [self name]);
}

@end
