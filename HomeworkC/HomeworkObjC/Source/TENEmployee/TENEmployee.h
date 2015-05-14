//
//  TENEmployee.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TENMoneyProtocol.h"

typedef  NS_ENUM(NSUInteger, TENEmployeeState) {
    TENEmployeeFree,
    TENEmployeePerformWork,
    TENEmployeeReadyMoneyOperation
};

@class TENEmployee;

@protocol TENEmployeeDelegate <NSObject>

- (void)employeeDidChange:(TENEmployee *)employee;

@end

@interface TENEmployee : NSObject <TENMoneyProtocol, TENEmployeeDelegate>
@property (nonatomic, copy, readonly)   NSString            *name;
@property (nonatomic, assign)           NSUInteger          experience;
@property (nonatomic, assign)           NSUInteger          salary;
@property (nonatomic, assign)           TENEmployeeState    state;

@property (nonatomic, assign)   id<TENEmployeeDelegate> delegate;

+ (instancetype)employeeWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name;

- (void)performWorkWithObject:(id<TENMoneyProtocol>)object;

// This method is intended for subclassing
- (void)performSpecificOperationWithObject:(id<TENMoneyProtocol>)object;

@end
