//
//  TENObservableObject.m
//  HomeworkC
//
//  Created by Andrey Ten on 5/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENObservableObject.h"

#import "TENAssignReference.h"

@interface TENObservableObject ()
@property (nonatomic, retain)   NSMutableSet    *mutableObserverSet;

- (void)notifyOfStateChangeWithSelector:(SEL)selector;

@end

@implementation TENObservableObject

@dynamic observerSet;

@synthesize state = _state;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableObserverSet = nil;

    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObserverSet = [NSMutableSet set];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setState:(NSUInteger)state {
    @synchronized (self) {
        if (_state != state) {
            _state = state;
            
            [self notifyOfStateChangeWithSelector:[self selectorForState:state]];
        }
    }
}

- (NSUInteger)state {
    @synchronized (self ) {
        return _state;
    }
}

- (NSSet *)observerSet {
    NSSet *referenceSet = self.mutableObserverSet;
    NSMutableSet *observers = [NSMutableSet setWithCapacity:[referenceSet count]];
    for (TENReference *reference in referenceSet) {
        [observers addObject:reference.target];
    }
    
    return [[observers copy] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)addObserver:(id)observer {
    @synchronized (self) {
        [self.mutableObserverSet addObject:[TENAssignReference referenceWithTarget:observer]];
    }
}

- (void)removeObserver:(id)observer {
    @synchronized (self) {
        [self.mutableObserverSet removeObject:[TENAssignReference referenceWithTarget:observer]];
    }
}

- (BOOL)isObsevedByObserver:(id)observer {
    @synchronized (self) {
        return [self.mutableObserverSet containsObject:
                [TENAssignReference referenceWithTarget:observer]];
    }
}

- (SEL)selectorForState:(NSUInteger)state {
    [self doesNotRecognizeSelector:_cmd];
    return NULL;
}

#pragma mark -
#pragma mark Private

- (void)notifyOfStateChangeWithSelector:(SEL)selector {
    NSSet *referenceSet = self.mutableObserverSet;
    for (TENReference *reference in referenceSet) {
        if ([reference.target respondsToSelector:selector]) {
            [reference.target performSelector:selector withObject:self];
        }
    }
}


@end
