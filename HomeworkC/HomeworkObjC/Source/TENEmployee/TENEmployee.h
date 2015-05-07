//
//  TENEmployee.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TENMoneyProtocol.h"

@class TENEmployee;

@protocol TENEmployeeDelegate <NSObject>

- (void)employee:(TENEmployee *)employee didChangeMoney:(NSUInteger)money;

@end

@interface TENEmployee : NSObject <TENMoneyProtocol, TENEmployeeDelegate>
@property (nonatomic, copy, readonly)   NSString    *name;
@property (nonatomic, assign)           NSUInteger  experience;
@property (nonatomic, assign)           NSUInteger  salary;

@property (nonatomic, assign)   id<TENEmployeeDelegate> delegate;

+ (instancetype)employeeWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name;

- (void)performWorkWithObject:(id<TENMoneyProtocol>)object;

@end
