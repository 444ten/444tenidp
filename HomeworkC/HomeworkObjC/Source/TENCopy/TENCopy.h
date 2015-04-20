//
//  TENCopy.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TENCopy : NSObject
@property (nonatomic, copy) NSString    *name;

+ (instancetype)objectWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name;

- (NSMutableString *)backDoorGetter;

@end
