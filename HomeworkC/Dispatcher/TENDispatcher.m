//
//  TENDispatcher.m
//  HomeworkC
//
//  Created by Andrey Ten on 5/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENDispatcher.h"

#import "NSObject+TENExtensions.h"
#import "TENQueue.h"
#import "TENDispatcherEmployee.h"

@interface TENDispatcher ()
@property (nonatomic, retain)   NSMutableArray  *handlers;
@property (nonatomic, retain)   TENQueue        *queue;

- (void)removeObservers;

- (id)nextHandlerWithState:(TENEmployeeState)state;

- (TENDispatcherEmployee *)bookedHanler;

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
        self.queue = [TENQueue object];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (void)addHandler:(TENDispatcherEmployee *)handler {
    @synchronized (self) {
        [handler addObserver:self];
        [self.handlers addObject:handler];
    }
}

- (void)removeHandler:(TENDispatcherEmployee *)handler {
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
                TENDispatcherEmployee *handler = [self bookedHanler];
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
        for (TENDispatcherEmployee *handler in handlers) {
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

- (TENDispatcherEmployee *)bookedHanler {
    TENDispatcherEmployee *handler = nil;
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

- (void)employeeDidBecomeFree:(TENDispatcherEmployee *)employee {
    [self processObject:nil];
}

@end
