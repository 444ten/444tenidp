//
//  TENRoom.h
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TENEmployee;

@interface TENRoom : NSObject
@property (nonatomic, assign)   NSUInteger  peopleCapacity;
@property (nonatomic, readonly) NSArray     *employees;

- (void)addEmployee:(TENEmployee *)employee;
- (void)removeEmployee:(TENEmployee *)employee;

@end
