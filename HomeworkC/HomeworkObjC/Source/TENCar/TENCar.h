//
//  TENCar.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TENMoneyProtocol.h"

typedef NS_ENUM(NSUInteger, TENCarState) {
    TENCarInLine,
    TENCarWash,
    TENCarCleanAndReady,
    TENCarOutLine
};

@interface TENCar : NSObject <TENMoneyProtocol>
@property (nonatomic, copy, readonly)   NSString    *model;
@property (nonatomic, assign)           TENCarState state;
@property (nonatomic, readonly)         NSSet       *observerSet;

+ (instancetype)carWithModel:(NSString *)model;

- (instancetype)initWithModel:(NSString *)model;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;

- (SEL)selectorForState:(TENCarState)state;

@end
