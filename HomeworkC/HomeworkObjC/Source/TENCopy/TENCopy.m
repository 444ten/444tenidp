//
//  TENCopy.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENCopy.h"

@implementation TENCopy

+ (instancetype)objectWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    
    return self;
}

- (NSString *)description {
    return [NSString stringWithFormat:@"%@", self.name];
}

- (NSMutableString *)backDoorGetter {
    return (NSMutableString *)_name;
}

@end
