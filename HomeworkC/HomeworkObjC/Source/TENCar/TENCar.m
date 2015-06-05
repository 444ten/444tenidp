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

@end

@implementation TENCar

@synthesize money = _money;

#pragma mark -
#pragma mark Class

+ (instancetype)carWithModel:(NSString *)model {
    return [[[self alloc] initWithModel:model] autorelease];
}

+ (instancetype)carWithIndex:(NSUInteger)index {
    NSString *model = [NSString stringWithFormat:@"%@_%lu", self.className, index];
    
    return [self carWithModel:model];
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
#pragma mark TENMoneyProtocol

- (NSUInteger)giveMoney {
    @synchronized (self) {
        NSUInteger result = self.money;
        self.money = 0;
//        NSLog(@"( - ) %@ give money: %lu", self.model, result);
        
        return result;
    }
}

- (void)takeMoney:(NSUInteger)money {
    
}

@end
