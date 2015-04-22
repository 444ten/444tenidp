//
//  TENBuilding.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENBuilding.h"

@interface TENBuilding()
@property (nonatomic, copy, readwrite)  NSString        *name;
@property (nonatomic, retain)           NSMutableArray  *roomsMutableArray;

@end

@implementation TENBuilding

@dynamic rooms;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)buildingWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    
    if (self) {
        self.name = name;
        self.roomsMutableArray = [NSMutableArray array];
    }
    
    return self;
}

- (void)dealloc {
    self.name = nil;
    self.roomsMutableArray = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors Methods

- (NSArray *)rooms {
    return [[self.roomsMutableArray copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)addRoom:(id)room {
    [self.roomsMutableArray addObject:room];
}

- (void)removeRoom:(id)room {
    [self.roomsMutableArray removeObject:room];
}

@end
