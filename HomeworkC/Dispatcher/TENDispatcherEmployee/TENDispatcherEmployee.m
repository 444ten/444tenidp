//
//  TENEDispatchermployee.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENDispatcherEmployee.h"

#import "TENCar.h"
#import "TENQueue.h"

@interface TENDispatcherEmployee()
@property (nonatomic, copy, readwrite)  NSString    *name;
@property (nonatomic, retain)           id          processedObject;
@property (nonatomic, retain)           TENQueue    *queueObjects;

- (void)performWorkWithObjectInBackground:(id)object;
- (void)finalizeWorkWithObjectOnMainThread:(id)object;

@end

@implementation TENDispatcherEmployee

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
    self.processedObject = nil;
    self.queueObjects = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        self.state = TENEmployeeFree;
        self.queueObjects = [[TENQueue new] autorelease];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (void)performWorkWithObject:(id)object {
    if (nil == object) {
        return;
    }
    
    @synchronized (self) {
        if (TENEmployeeFree == self.state ) {
            self.state = TENEmployeePerformingWork;
            [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                                   withObject:object];
        } else {
            [self.queueObjects enqueueObject:object];
        }
    }
}

- (void)finalizeWorkWithObject:(TENDispatcherEmployee *)object {
    object.state = TENEmployeeFree;
}

- (void)processObject:(id)object {
    [self doesNotRecognizeSelector:_cmd];
}

#pragma mark -
#pragma mark Overload

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case TENEmployeeFree:
            return @selector(employeeDidBecomeFree:);
            
        case TENEmployeePerformingWork:
            return @selector(employeeDidBecomePerformWork:);
            
        case TENEmployeeReadyForMoneyOperation:
            return @selector(employeeDidBecomeReadyForMoneyOperation:);
            
        default:
            [super selectorForState:state];
    }
    
    return NULL;
}

#pragma mark -
#pragma mark Private

- (void)performWorkWithObjectInBackground:(id)object {
    [self processObject:object];
    [self performSelectorOnMainThread:@selector(finalizeWorkWithObjectOnMainThread:)
                           withObject:object
                        waitUntilDone:NO];
}

- (void)finalizeWorkWithObjectOnMainThread:(id)object {
    @synchronized (self) {
        id queueObject = [self.queueObjects dequeueObject];
        
        if (queueObject) {
            [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                                   withObject:queueObject];
        } else {
            self.state = TENEmployeeReadyForMoneyOperation;
        }
    
        [self finalizeWorkWithObject:object];
    }
}

#pragma mark -
#pragma mark TENMoneyProtocol

- (NSUInteger)giveMoney {
    @synchronized (self) {
        NSUInteger result = self.money;
        self.money = 0;
        NSLog(@"( - ) %@ give money: %lu", self.name, result);
        
        return result;
    }
}

- (void)takeMoney:(NSUInteger)money {
    @synchronized (self) {
        self.money += money;
        NSLog(@"( + ) %@ take money: %lu", self.name, money);
    }
}

#pragma mark -
#pragma mark TENEmployeeObserver

- (void)employeeDidBecomeFree:(TENDispatcherEmployee *)employee {
    if (self != employee) {
        return;
    }

    @synchronized (self) {
        if (TENEmployeeFree == self.state) {
            [self performWorkWithObject:[self.queueObjects dequeueObject]];
        }
    }
}

- (void)employeeDidBecomeReadyForMoneyOperation:(TENDispatcherEmployee *)employee {
    if (self == employee) {
        return;
    }

    NSLog(@"(s)%@ -> %@", employee.name, NSStringFromSelector(_cmd));
    [self performWorkWithObject:employee];
}

@end
