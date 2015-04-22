//
//  TENRoom.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENRoom.h"

@implementation TENRoom

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *string = [NSMutableString stringWithString:[super description]];
    [string appendFormat:@" name:'%@', people capacity = %lu", self.name, self.peopleCapacity];

    return string;
}

@end
