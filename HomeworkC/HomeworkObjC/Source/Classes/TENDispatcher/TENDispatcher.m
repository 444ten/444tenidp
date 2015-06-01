//
//  TENDispatcher.m
//  HomeworkC
//
//  Created by Andrey Ten on 5/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENDispatcher.h"

#import "TENQueue.h"
#import "TENObservableObject.h"

static const NSUInteger TENTotalCars = 20;

@interface TENDispatcher ()
@property (nonatomic, retain)   NSMutableArray  *handlers;
@property (nonatomic, retain)   TENQueue        *queue;

- (void)removeObservers;

- (id)nextHandlerWithState:(TENState)state;

@end

@implementation TENDispatcher

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self removeObservers];
    
    self.handlers = nil;
    self.queue = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.handlers = [NSMutableArray array];
        self.queue = [[TENQueue new] autorelease];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (void)addHandler:(TENObservableObject *)handler {
    [handler addObserver:self];
    [self.handlers addObject:handler];
}

- (void)removeHandler:(TENObservableObject *)handler {
    [handler removeObserver:self];
    [self.handlers removeObject:handler];
}

- (void)addObjectToProcess:(id)object {
    TENObservableObject *aHandler = [self nextHandlerWithState:TENStateFree];
    
    if (aHandler) {
        aHandler.state = TENStateBusy;
//        [aHandler performWorkWithObject:object];
    } else {
        [self.queue enqueueObject:object];
    }
}

#pragma mark -
#pragma mark Overload


#pragma mark -
#pragma mark Private

- (void)removeObservers {
    NSArray *aHandlers = [[self.handlers copy] autorelease];
    for (id handler in aHandlers) {
        [self removeHandler:handler];
    }
}

- (id)nextHandlerWithState:(TENState)state {
    NSArray *aHandlers = [[self.handlers copy] autorelease];
    for (TENObservableObject *handler in aHandlers) {
        if (state == handler.state) {
            
            NSMutableArray *array = self.handlers;
            [array addObject:handler];
            [array removeObject:handler];
            
            return handler;
        }
    }
    
    return nil;
}

#pragma mark -
#pragma mark TENStateProtocol

- (void)handlerDidBecomeFree:(TENObservableObject *)handler {
    @synchronized (self) {
        if (TENStateFree == handler.state) {
            [self addObjectToProcess:[self.queue dequeueObject]];
        }
    }
}

@end
