//
//  TENRoom.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENRoom.h"

@interface TENRoom ()
@property (nonatomic, retain)   NSMutableArray  *mutableEmployees;

@end

@implementation TENRoom

@dynamic employees;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableEmployees = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployees = [NSMutableArray new];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)addEmployee:(TENEmployee *)employee {
    NSMutableArray *array = self.mutableEmployees;
    
    if (array.count < self.peopleCapacity && ![array containsObject:employee]) {
        [self.mutableEmployees addObject:employee];
    }
}

- (void)removeEmployee:(TENEmployee *)employee {
    [self.mutableEmployees removeObject:employee];
}

@end
