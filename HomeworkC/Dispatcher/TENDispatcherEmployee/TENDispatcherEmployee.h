//
//  TENDispatcherEmployee.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TENObservableObject.h"
#import "TENMoneyProtocol.h"

typedef  NS_ENUM(NSUInteger, TENEmployeeState) {
    TENEmployeeFree,
    TENEmployeePerformingWork,
    TENEmployeeReadyForMoneyOperation
};

@class TENDispatcherEmployee;

@protocol TENEmployeeObserver <NSObject>

@optional

- (void)employeeDidBecomeFree:(TENDispatcherEmployee *)employee;
- (void)employeeDidBecomePerformWork:(TENDispatcherEmployee *)employee;
- (void)employeeDidBecomeReadyForMoneyOperation:(TENDispatcherEmployee *)employee;

@end

@interface TENDispatcherEmployee : TENObservableObject <TENMoneyProtocol, TENEmployeeObserver>
@property (nonatomic, copy, readonly)   NSString    *name;
@property (nonatomic, assign)           NSUInteger  experience;
@property (nonatomic, assign)           NSUInteger  salary;

+ (instancetype)employeeWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name;

- (void)performWorkWithObject:(id)object;
- (void)finalizeWorkWithObject:(id)object;

// This method is intended for subclassing. Never call it directly.
- (void)processObject:(id)object;

@end
