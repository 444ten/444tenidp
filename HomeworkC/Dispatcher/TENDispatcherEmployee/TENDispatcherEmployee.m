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

+ (instancetype)employeeWithIndex:(NSUInteger)index {
    NSString *name = [NSString stringWithFormat:@"%@_%lu", self.className, index];

    return [self employeeWithName:name];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;

    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        self.state = TENEmployeeFree;
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
        self.state = TENEmployeePerformingWork;
        [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                               withObject:object];
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
        
        self.state = TENEmployeeReadyForMoneyOperation;
    
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

@end
