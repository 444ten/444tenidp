//
//  TENCar.m
//  HomeworkC
//
//  Created by 444ten on 4/23/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENCar.h"

@interface TENCar()
@property (nonatomic, copy, readwrite)  NSString    *model;

@end

@implementation TENCar

#pragma mark -
#pragma mark Class Methods

+ (instancetype)carWithModel:(NSString *)model {
    return [[[self alloc] initWithName:model] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithModel:(NSString *)model {
    self = [super init];
    
    if (self) {
        self.model = model;
    }
    
    return self;
}

- (void)dealloc {
    self.model = nil;
    
    [super dealloc];
}

@end
