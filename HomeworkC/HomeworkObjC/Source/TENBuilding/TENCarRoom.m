//
//  TENCarRoom.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENCarRoom.h"

@implementation TENCarRoom

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *string = [NSMutableString stringWithString:[super description]];
    [string appendFormat:@", car capacity = %lu", self.carCapacity];
    
    return string;
}

@end
