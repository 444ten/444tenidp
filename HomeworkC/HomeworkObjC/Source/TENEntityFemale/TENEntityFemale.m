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

- (TENEntityMale *)makeEntityMaleWithName:(NSString *)name weight:(double)weight {
    return [TENEntityMale entityWithName:name age:0 weight:weight];
}

- (instancetype)makeEntityFemaleWithName:(NSString *)name weight:(double)weight {
    return [TENEntityFemale entityWithName:name age:0 weight:weight];
}

- (void)performGenderSpecificOperation {
    NSLog(@"%@ gave birth to a newborn...", [self name]);
}

@end
