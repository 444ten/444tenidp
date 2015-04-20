//
//  TENCar.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENCar.h"

@interface TENCar()
@property (nonatomic, copy, readwrite)  NSString    *name;

@end

@implementation TENCar

#pragma mark -
#pragma mark Class Methods

+ (instancetype)carWithName:(NSString *)name {
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
#pragma mark Accessors Methods

- (NSString *)name {
    return [NSString stringWithString:_name];
}

@end
