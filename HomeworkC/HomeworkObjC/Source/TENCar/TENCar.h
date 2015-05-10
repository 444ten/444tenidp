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
@property (nonatomic, copy, readonly)           NSString    *model;
@property (nonatomic, assign, getter=isClean)   BOOL        clean;

+ (instancetype)carWithModel:(NSString *)model;

- (instancetype)initWithModel:(NSString *)model;

@end
