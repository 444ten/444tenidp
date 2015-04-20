//
//  TENBuilding.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENBuilding.h"

@implementation TENBuilding

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
        self.roomsArray = [[[NSMutableArray alloc] init] autorelease];
    }
    
    return self;
}

- (void)dealloc {
    self.name = nil;
    self.roomsArray = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Public Methods

- (id)roomWithSpecification:(NSArray *)specification {
    return nil;
}

- (void)buildWithMasterplan:(NSDictionary *)masterplan {
    NSArray *keysArray = [masterplan allKeys];
    
    for (NSNumber *key in keysArray) {
        NSArray *specification = masterplan[key];
        
        [self.roomsArray addObject:[self roomWithSpecification:specification]];
    }
}


@end
