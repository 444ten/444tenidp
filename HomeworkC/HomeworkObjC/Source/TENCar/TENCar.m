//
//  TENCar.m
//  HomeworkC
//
//  Created by 444ten on 4/23/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENCar.h"

#import "TENAssignReference.h"

@interface TENCar()
@property (nonatomic, copy, readwrite)  NSString        *model;
@property (nonatomic, retain)           NSMutableSet    *mutableReferenceSet;

- (void)notifyOfStateChangeWithSelector:(SEL)selector;

@end

@implementation TENCar

@dynamic observerSet;

@synthesize money = _money;

#pragma mark -
#pragma mark Class

+ (instancetype)carWithModel:(NSString *)model {
    return [[[self alloc] initWithModel:model] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.model = nil;
    self.mutableReferenceSet = nil;
    
    [super dealloc];
}

- (instancetype)initWithModel:(NSString *)model {
    self = [super init];
    if (self) {
        self.model = model;
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSSet *)observerSet {
    NSMutableSet *referenceSet = self.mutableReferenceSet;
    NSMutableSet *set = [NSMutableSet setWithCapacity:[referenceSet count]];
    for (TENReference *reference in referenceSet) {
        [set addObject:reference.target];
    }
    
    return [[set copy] autorelease];
}

- (void)setState:(TENCarState)state {
    if (_state != state) {
        _state = state;
        
        [self notifyOfStateChangeWithSelector:[self selectorForState:state]];
    }
}


#pragma mark -
#pragma mark Public

- (void)addObserver:(id)observer {
    
}

- (void)removeObserver:(id)observer {
    
}

- (SEL)selectorForState:(TENCarState)state {
    return nil;
}

#pragma mark -
#pragma mark Private

- (void)notifyOfStateChangeWithSelector:(SEL)selector {
    
}

#pragma mark -
#pragma mark TENMoneyProtocol

- (void)takeMoneyFromPayer:(id<TENMoneyProtocol>)payer {
}

@end
