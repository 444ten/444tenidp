//
//  TENRoom.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENRoom.h"

@interface TENRoom()
@property (nonatomic, copy, readwrite)  NSString    *name;

@end

@implementation TENRoom

#pragma mark -
#pragma mark Class Methods

+ (instancetype)roomWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *string = [NSMutableString stringWithString:[super description]];
    [string appendFormat:@" name:'%@', people capacity = %lu", self.name, self.peopleCapacity];

    return string;
}

@end
