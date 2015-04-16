//
//  TENCar.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENCar.h"

@implementation TENCar

#pragma mark -
#pragma mark Class Methods

+ (instancetype)carWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    
    if (self) {
        self.name = name;
        self.money = 100;
        self.clean = false;
    }
    
    return self;
}

- (void)dealloc {
    self.name = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors Methods

#pragma mark -
#pragma mark Public Methods

@end
