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
#pragma mark Class Methods

+ (instancetype)roomWithName:(NSString *)name peopleCapacity:(NSUInteger)peopleCapacity {
    return [[[self alloc] initWithName:name peopleCapacity:peopleCapacity] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithName:(NSString *)name peopleCapacity:(NSUInteger)peopleCapacity {
    self = [super init];
    
    if (self) {
        self.name = name;
        self.peopleCapacity = peopleCapacity;
    }
    
    return self;
}

- (void)dealloc {
    self.name = nil;
    
    [super dealloc];
}

@end
