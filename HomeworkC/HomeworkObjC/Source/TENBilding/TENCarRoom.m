//
//  TENCarRoom.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENCarRoom.h"

@implementation TENCarRoom

#pragma mark -
#pragma mark Class Methods

+ (instancetype)carRoomWithName:(NSString *)name
                 peopleCapacity:(NSUInteger)peopleCapacity
                    carCapacity:(NSUInteger)carCapacity
{
    return [[[self alloc] initWithName:name
                        peopleCapacity:peopleCapacity
                           carCapacity:carCapacity] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithName:(NSString *)name
                 peopleCapacity:(NSUInteger)peopleCapacity
                    carCapacity:(NSUInteger)carCapacity
{
    self = [super initWithName:name peopleCapacity:peopleCapacity];
    
    if (self) {
        self.carCapasity = carCapacity;
    }
    
    return self;
}

- (void)dealloc {
    [super dealloc];
}

@end
