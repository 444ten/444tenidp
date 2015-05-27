//
//  TENQueue.m
//  HomeworkC
//
//  Created by Andrey Ten on 5/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENQueue.h"

@interface TENQueue ()
@property (nonatomic, retain)   NSMutableArray  *queue;


@end


@implementation TENQueue

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.queue = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.queue = [NSMutableArray array];
    }
    return self;
}

#pragma mark - 
#pragma mark Public

- (void)enqueueObject:(id)object {
    [self.queue addObject:object];
}
    
- (id)dequeueObject {
    NSMutableArray *queue = self.queue;
    id result = [[[queue firstObject] retain] autorelease];
    
    if (result) {
        [queue removeObject:result];
    }
    
    return result;
}

@end
