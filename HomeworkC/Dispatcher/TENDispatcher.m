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

//static const NSUInteger TENTotalCars = 20;

@interface TENDispatcher ()
@property (nonatomic, retain)   NSMutableArray  *handlers;
@property (nonatomic, retain)   TENQueue        *queue;

- (void)removeObservers;

- (id)nextHandlerWithState:(TENEmployeeState)state;

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
    [handler addObserver:self];
    [self.handlers addObject:handler];
}

- (void)removeHandler:(TENDispatcherEmployee *)handler {
    [handler removeObserver:self];
    [self.handlers removeObject:handler];
}

- (void)addObjectToProcess:(id)object {
    TENDispatcherEmployee *aHandler = [self nextHandlerWithState:TENEmployeeFree];
    
    if (aHandler) {
        aHandler.state = TENEmployeePerformingWork;
        [aHandler performWorkWithObject:object];
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

- (id)nextHandlerWithState:(TENEmployeeState)state {
    NSArray *aHandlers = [[self.handlers copy] autorelease];
    for (TENDispatcherEmployee *handler in aHandlers) {
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
#pragma mark TENEmployeeObserver

//- (void)employeeDidBecomeFree:(TENEmployee *)employee;

- (void)handlerDidBecomeFree:(TENDispatcherEmployee *)handler {
    @synchronized (self) {
        if (TENEmployeeFree == handler.state) {
            [self addObjectToProcess:[self.queue dequeueObject]];
        }
    }
}



//- (void)employeeDidBecomePerformWork:(TENEmployee *)employee;
//- (void)employeeDidBecomeReadyForMoneyOperation:(TENEmployee *)employee;


@end
