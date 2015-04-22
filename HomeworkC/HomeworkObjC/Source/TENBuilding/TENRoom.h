//
//  TENRoom.h
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TENRoom : NSObject
@property (nonatomic, copy, readonly)   NSString    *name;
@property (nonatomic, assign)           NSUInteger  peopleCapacity;

+ (instancetype)roomWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name;

@end
