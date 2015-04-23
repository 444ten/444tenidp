//
//  TENCar.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TENCar : NSObject
@property (nonatomic, copy, readonly)           NSString    *model;
@property (nonatomic, assign)                   NSUInteger  money;
@property (nonatomic, assign, getter=isClean)   BOOL        clean;

+ (instancetype)carWithModel:(NSString *)model;

- (instancetype)initWithModel:(NSString *)model;

@end
