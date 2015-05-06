//
//  TENBuilding.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENBuilding.h"

@interface TENBuilding()
@property (nonatomic, retain)   NSMutableArray  *mutableRooms;

@end

@implementation TENBuilding

@dynamic rooms;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableRooms = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableRooms = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors Methods

- (NSArray *)rooms {
    return [[self.mutableRooms copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)addRoom:(id)room {
    [self.mutableRooms addObject:room];
}

- (void)removeRoom:(id)room {
    [self.mutableRooms removeObject:room];
}

@end
