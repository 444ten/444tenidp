//
//  TENCar.m
//  HomeworkC
//
//  Created by 444ten on 4/23/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENCar.h"

@interface TENCar()
@property (nonatomic, copy, readwrite)  NSString    *model;

- (void)performNotification;

@end

@implementation TENCar

@synthesize money = _money;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)carWithModel:(NSString *)model {
    return [[[self alloc] initWithModel:model] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.model = nil;
    
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

- (void)setClean:(BOOL)clean {
    if (_clean != clean) {
        _clean = clean;
        [self performNotification];
    }    
}

#pragma mark -
#pragma mark Public

- (void)takeMoneyFromPayer:(id<TENMoneyProtocol>)payer {
}

#pragma mark -
#pragma mark Private

- (void)performNotification {
    [self.delegate carDidChange:self];
}

@end
