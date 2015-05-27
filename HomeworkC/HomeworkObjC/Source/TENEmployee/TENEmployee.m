//
//  TENEmployee.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEmployee.h"

#import "TENCar.h"
#import "TENQueue.h"

@interface TENEmployee()
@property (nonatomic, copy, readwrite)  NSString    *name;
@property (nonatomic, retain)           id          processedObject;
@property (nonatomic, retain)           TENQueue    *queueObjects;

- (void)performWorkWithObjectInBackground:(id)object;
- (void)finalizeWorkWithObjectOnMainThread:(id)object;

@end

@implementation TENEmployee

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
            self.state = TENEmployeePerformWork;
            [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                                   withObject:object];
        } else {
            [self.queueObjects enqueueObject:object];
        }
    }
}

- (void)finalizeWorkWithObject:(TENEmployee *)object {
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
            
        case TENEmployeePerformWork:
            return @selector(employeeDidBecomePerformWork:);
            
        case TENEmployeeReadyForMoneyOperation:
            return @selector(employeeDidBecomeReadyForMoneyOperation:);
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
        if ([self.queueObjects isEmpty]) {
            self.state = TENEmployeeReadyForMoneyOperation;
        } else {
            [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                                   withObject:[self.queueObjects dequeueObject]];
        }
    
    [self finalizeWorkWithObject:object];
    }
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

- (void)employeeDidBecomeFree:(TENEmployee *)employee {
    if (self != employee) {
        return;
    }
    
    @synchronized (self) {
        if (TENEmployeeFree == employee.state && [self.queueObjects isNonEmpty]) {
            [self performWorkWithObject:[self.queueObjects dequeueObject]];
        }
        
    }
}

- (void)employeeDidBecomeReadyForMoneyOperation:(TENEmployee *)employee {
    if (self == employee) {
        return;
    }

    @synchronized (self) {
        if (TENEmployeeReadyForMoneyOperation == employee.state) {
            NSLog(@"(s)%@ -> %@", employee.name, NSStringFromSelector(_cmd));
            [self performWorkWithObject:employee];
        }
    }
}

@end
