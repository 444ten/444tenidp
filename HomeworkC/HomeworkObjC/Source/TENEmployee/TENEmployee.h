//
//  TENEmployee.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TENEmployee : NSObject
@property (nonatomic, copy)     NSString*   name;
@property (nonatomic, assign)   NSUInteger  experience;
@property (nonatomic, assign)   NSUInteger  salary;
@property (nonatomic, assign)   NSUInteger  money;

+ (instancetype)employee;
+ (instancetype)employeeWithName:(NSString *)name salary:(NSUInteger)salary;

- (BOOL)money:(NSUInteger)money toEmployee:(TENEmployee *)employee;

@end
