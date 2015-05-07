//
//  TENCar.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TENMoneyProtocol.h"

@class TENCar;

@protocol TENCarDelegate <NSObject>

- (void)car:(TENCar *)car didChangeClean:(BOOL)clean;

@end

@interface TENCar : NSObject <TENMoneyProtocol>
@property (nonatomic, copy, readonly)           NSString    *model;
@property (nonatomic, assign, getter=isClean)   BOOL        clean;

@property (nonatomic, assign)   id<TENCarDelegate>  delegate;

+ (instancetype)carWithModel:(NSString *)model;

- (instancetype)initWithModel:(NSString *)model;

@end
