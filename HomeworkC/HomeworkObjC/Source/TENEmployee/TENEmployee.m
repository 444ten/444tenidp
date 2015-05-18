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
@property (nonatomic, retain)           NSMutableSet    *mutableObserverReferenceSet;

- (void)notifyOfStateChangeWithSelector:(SEL)selector;

@end

@implementation TENEmployee

@dynamic observerSet;

@synthesize money = _money;

#pragma mark -
#pragma mark Class

+ (instancetype)employeeWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.mutableObserverReferenceSet = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        self.state = TENEmployeeFree;
        self.mutableObserverReferenceSet = [NSMutableSet set];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setState:(TENEmployeeState)state {
    if (_state != state) {
        _state = state;
        
        [self notifyOfStateChangeWithSelector:[self selectorForState:state]];
    }
}

- (NSSet *)observerSet {
    NSSet *referenceSet = self.mutableObserverReferenceSet;
    NSMutableSet *observers = [NSMutableSet setWithCapacity:[referenceSet count]];
    for (TENReference *reference in referenceSet) {
        [observers addObject:reference.target];
    }
    
    return [[observers copy] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)performWorkWithObject:(id<TENMoneyProtocol>)object {
    self.state = TENEmployeePerformWork;
    
    [self processObject:object];

    self.state = TENEmployeeReadyForMoneyOperation;
    self.state = TENEmployeeFree;
}

- (void)processObject:(id<TENMoneyProtocol>)object {
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
    
    return nil;
}

- (void)addObserver:(id<TENEmployeeObserver>)observer {
    [self.mutableObserverReferenceSet addObject:[TENAssignReference referenceWithTarget:observer]];
}

- (void)removeObserver:(id<TENEmployeeObserver>)observer {
    [self.mutableObserverReferenceSet removeObject:[TENAssignReference referenceWithTarget:observer]];
}

- (BOOL)isObsevedByObserver:(id<TENEmployeeObserver>)observer {
    return [self.mutableObserverReferenceSet containsObject:[TENAssignReference referenceWithTarget:observer]];
}

#pragma mark -
#pragma mark Private

- (void)notifyOfStateChangeWithSelector:(SEL)selector {
    NSSet *referenceSet = self.mutableObserverReferenceSet;
    for (TENReference *reference in referenceSet) {
        if ([reference.target respondsToSelector:selector]) {
            [reference.target performSelector:selector withObject:self];
        }
    }
}

#pragma mark -
#pragma mark TENMoneyProtocol

- (void)takeMoneyFromPayer:(id<TENMoneyProtocol>)payer {
    NSString *name  = ([payer isKindOfClass:[TENEmployee class]])
                    ? ((TENEmployee *)payer).name
                    : ((TENCar *)payer).model;
    
    NSLog(@"%@ take %lu from %@", self.name, (unsigned long)payer.money, name);
    self.money += payer.money;
    payer.money = 0;
}

#pragma mark -
#pragma mark TENEmployeeObserver

//- (void)employeeDidBecomeFree:(TENEmployee *)employee {
//    NSLog(@"%@ -> %@", employee.name, NSStringFromSelector(_cmd));
//    
//}
//
//- (void)employeeDidBecomePerformWork:(TENEmployee *)employee {
//    NSLog(@"%@ -> %@", employee.name, NSStringFromSelector(_cmd));
//    
//}

- (void)employeeDidBecomeReadyForMoneyOperation:(TENEmployee *)employee {
    NSLog(@"%@ -> %@", employee.name, NSStringFromSelector(_cmd));
    [self performWorkWithObject:employee];
}

@end
