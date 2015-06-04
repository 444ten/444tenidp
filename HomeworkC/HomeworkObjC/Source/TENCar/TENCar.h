//
//  TENCar.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TENMoneyProtocol.h"

@interface TENCar : NSObject <TENMoneyProtocol>
@property (nonatomic, copy, readonly)   NSString    *model;

+ (instancetype)carWithModel:(NSString *)model;
+ (instancetype)carWithIndex:(NSUInteger)index;

- (instancetype)initWithModel:(NSString *)model;

@end
