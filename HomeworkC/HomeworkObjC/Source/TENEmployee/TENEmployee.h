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
    TENEmployeeReadyForMoneyOperation
};

@class TENEmployee;

@protocol TENEmployeeObserver <NSObject>

@optional

- (void)employeeDidBecomeFree:(TENEmployee *)employee;
- (void)employeeDidBecomePerformWork:(TENEmployee *)employee;
- (void)employeeDidBecomeReadyForMoneyOperation:(TENEmployee *)employee;

@end

@interface TENEmployee : NSObject <TENMoneyProtocol, TENEmployeeObserver>
@property (nonatomic, copy, readonly)   NSString            *name;
@property (nonatomic, assign)           NSUInteger          experience;
@property (nonatomic, assign)           NSUInteger          salary;
@property (nonatomic, assign)           TENEmployeeState    state;

@property (nonatomic, readonly) NSSet   *observerSet;

+ (instancetype)employeeWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name;

- (void)performWorkWithObject:(id<TENMoneyProtocol>)object;

// This method is intended for subclassing
- (void)processObject:(id<TENMoneyProtocol>)object;

- (SEL)selectorForState:(TENEmployeeState)state;

- (void)addObserver:(id<TENEmployeeObserver>)observer;
- (void)removeObserver:(id<TENEmployeeObserver>)observer;
- (BOOL)isObsevedByObserver:(id<TENEmployeeObserver>)observer;

@end
