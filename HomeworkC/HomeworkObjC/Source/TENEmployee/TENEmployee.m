//
//  TENEmployee.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEmployee.h"

#import "TENAssignReference.h"
#import "TENCar.h"

@interface TENEmployee()
@property (nonatomic, copy, readwrite)  NSString        *name;
@property (nonatomic, retain)           NSMutableSet    *mutableObserverSet;
@property (nonatomic, retain)           id              processedObject;
@property (nonatomic, retain)           NSMutableArray  *queueObjects;

- (void)performWorkWithObjectInBackground:(id)object;
- (void)finalizeWorkWithObjectOnMainThread:(id)object;

- (void)notifyOfStateChangeWithSelector:(SEL)selector;

- (void)enqueueObject:(id)object;
- (id)dequeueObject;

@end

@implementation TENEmployee

@dynamic observerSet;

@synthesize money = _money;
@synthesize state = _state;

#pragma mark -
#pragma mark Class

+ (instancetype)employeeWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.mutableObserverSet = nil;
    self.processedObject = nil;
    self.queueObjects = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        self.state = TENEmployeeFree;
        self.mutableObserverSet = [NSMutableSet set];
        self.queueObjects = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setState:(TENEmployeeState)state {
    @synchronized (self) {
        if (_state != state) {
            _state = state;
            
            [self notifyOfStateChangeWithSelector:[self selectorForState:state]];
        }
    }
}

- (TENEmployeeState)state {
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

- (void)performWorkWithObject:(id)object {
    if (object) {
        if (TENEmployeeFree == self.state ) {
            self.state = TENEmployeePerformWork;
            
            [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                                   withObject:object];
        } else {
            [self enqueueObject:object];
        }
    }
}

- (void)finalizeWorkWithObject:(id)object {
    ((TENEmployee *)object).state = TENEmployeeFree;
}

- (void)processObject:(id)object {
    [self doesNotRecognizeSelector:_cmd];
}

- (SEL)selectorForState:(TENEmployeeState)state {
    switch (state) {
        case TENEmployeeFree:
            return @selector(employeeDidBecomeFree:);
            
        case TENEmployeePerformWork:
            return @selector(employeeDidBecomePerformWork:);
            
        case TENEmployeeReadyForMoneyOperation:
            return @selector(employeeDidBecomeReadyForMoneyOperation:);
    }
    
    return NULL;
}

- (void)addObserver:(id<TENEmployeeObserver>)observer {
    @synchronized (self) {
        [self.mutableObserverSet addObject:[TENAssignReference referenceWithTarget:observer]];
    }
}

- (void)removeObserver:(id<TENEmployeeObserver>)observer {
    @synchronized (self) {
        [self.mutableObserverSet removeObject:[TENAssignReference referenceWithTarget:observer]];
    }
}

- (BOOL)isObsevedByObserver:(id<TENEmployeeObserver>)observer {
    @synchronized (self) {
        return [self.mutableObserverSet containsObject:
                [TENAssignReference referenceWithTarget:observer]];
    }
}

#pragma mark -
#pragma mark Private

- (void)performWorkWithObjectInBackground:(id)object {
    [self processObject:object];
    
    if ([NSThread isMainThread]) {
        [self finalizeWorkWithObjectOnMainThread:object];
    } else {
        [self performSelectorOnMainThread:@selector(finalizeWorkWithObjectOnMainThread:)
                               withObject:object
                            waitUntilDone:NO];
    }
}

- (void)finalizeWorkWithObjectOnMainThread:(id)object {
    
    id objectFromQueue = [self dequeueObject];
    if (objectFromQueue) {
        [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                               withObject:objectFromQueue];
    } else {
        self.state = TENEmployeeReadyForMoneyOperation;
    }
    
    [self finalizeWorkWithObject:object];
}



- (void)notifyOfStateChangeWithSelector:(SEL)selector {
    NSSet *referenceSet = self.mutableObserverSet;
    for (TENReference *reference in referenceSet) {
        if ([reference.target respondsToSelector:selector]) {
            [reference.target performSelector:selector withObject:self];
        }
    }
}

- (void)enqueueObject:(id)object {
    [self.queueObjects addObject:object];
}

- (id)dequeueObject {
    NSMutableArray *queue = self.queueObjects;
    id result = [[[queue firstObject] retain] autorelease];
    
    if (result) {
        [queue removeObject:result];
    }
    
    return result;
}

#pragma mark -
#pragma mark TENMoneyProtocol

- (void)takeMoneyFromPayer:(id<TENMoneyProtocol>)payer {
    NSString *name  = ([payer isKindOfClass:[TENEmployee class]])
                    ? ((TENEmployee *)payer).name
                    : ((TENCar *)payer).model;
    
    NSLog(@"(m)%@ take %lu from %@", self.name, (unsigned long)payer.money, name);
    self.money += payer.money;
    payer.money = 0;
}

#pragma mark -
#pragma mark TENEmployeeObserver

- (void)employeeDidBecomeReadyForMoneyOperation:(TENEmployee *)employee {
    NSLog(@"(s)%@ -> %@", employee.name, NSStringFromSelector(_cmd));
    [self performWorkWithObject:employee];
}

@end
