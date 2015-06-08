//
//  TENGCDDispatcher.m
//  HomeworkC
//
//  Created by Andrey Ten on 5/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENGCDDispatcher.h"

#import "NSObject+TENExtensions.h"
#import "TENQueue.h"
#import "TENGCDEmployee.h"

@interface TENGCDDispatcher ()
@property (nonatomic, retain)   NSMutableArray  *handlers;
@property (nonatomic, retain)   TENQueue        *queue;

- (void)removeObservers;

- (id)nextHandlerWithState:(TENEmployeeState)state;

- (TENGCDEmployee *)bookedHandler;

@end

@implementation TENGCDDispatcher

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
        self.queue = [TENQueue object];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (void)addHandler:(TENGCDEmployee *)handler {
    @synchronized (self) {
        [handler addObserver:self];
        [self.handlers addObject:handler];
    }
}

- (void)removeHandler:(TENGCDEmployee *)handler {
    @synchronized (self) {
        [handler removeObserver:self];
        [self.handlers removeObject:handler];
    }
}

- (void)processObject:(id)object {
        TENQueue *queue = self.queue;
        [queue enqueueObject:object];
    
        @synchronized (queue) {
            if (![queue isEmpty]) {
                TENGCDEmployee *handler = [self bookedHandler];
                if (handler) {
                    [handler performWorkWithObject:[queue dequeueObject]];
                }
            }
        }
}

#pragma mark -
#pragma mark Private

- (void)removeObservers {
    NSArray *aHandlers = [[self.handlers copy] autorelease];
    for (id handler in aHandlers) {
        [self removeHandler:handler];
    }
}

- (id)nextHandlerWithState:(TENEmployeeState)state {
    @synchronized (self) {
        NSArray *handlers = [[self.handlers copy] autorelease];
        for (TENGCDEmployee *handler in handlers) {
            if (state == handler.state) {
                NSMutableArray *array = self.handlers;
                [array removeObject:handler];                
                [array addObject:handler];
                
                return handler;
            }
        }
        
        return nil;
    }
}

- (TENGCDEmployee *)bookedHandler {
    TENGCDEmployee *handler = nil;
    while ((handler = [self nextHandlerWithState:TENEmployeeFree])) {
        @synchronized (self) {
            if (TENEmployeeFree == handler.state) {
                handler.state = TENEmployeePerformingWork;
                
                return handler;
            }
        }
    }
    
    return nil;
}

#pragma mark -
#pragma mark TENEmployeeObserver

- (void)employeeDidBecomeFree:(TENGCDEmployee *)employee {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        [self processObject:nil];
    });
}

@end
