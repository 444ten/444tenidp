//
//  TENQueue.m
//  HomeworkC
//
//  Created by Andrey Ten on 5/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENQueue.h"

@interface TENQueue ()
@property (nonatomic, retain)   NSMutableArray  *mutableQueue;

@end

@implementation TENQueue

@dynamic queue;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableQueue = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableQueue = [NSMutableArray array];
    }
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)queue {
    @synchronized (self) {
        return [[self.mutableQueue copy] autorelease];
    }
}

#pragma mark - 
#pragma mark Public

- (BOOL)isEmpty {
    @synchronized (self) {
        return 0 == [self.mutableQueue count];
    }
}

- (void)enqueueObject:(id)object {
    @synchronized (self) {
        [self.mutableQueue addObject:object];
    }
}
    
- (id)dequeueObject {
    @synchronized (self) {
        NSMutableArray *aQueue = self.mutableQueue;
        id result = [[[aQueue firstObject] retain] autorelease];
        
        if (result) {
            [aQueue removeObject:result];
        }
        
        return result;
    }
}

@end
