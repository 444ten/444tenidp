//
//  NSObject+TENObjectCategory.m
//  HomeworkC
//
//  Created by 444ten on 4/14/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "NSObject+TENObjectCategory.h"

@implementation NSObject (TENObjectCategory)

+ (instancetype)object {
    return [[[self alloc] init] autorelease];
}


@end
