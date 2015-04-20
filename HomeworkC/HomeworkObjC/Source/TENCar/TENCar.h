//
//  TENCar.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TENCar : NSObject
@property (nonatomic, copy, readonly)           NSString    *name;
@property (nonatomic, assign)                   NSUInteger  money;
@property (nonatomic, assign, getter=isClean)   BOOL        clean;

+ (instancetype)carWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name;

@end
