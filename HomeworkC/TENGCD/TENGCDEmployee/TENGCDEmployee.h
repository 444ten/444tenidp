//
//  TENGCDEmployee.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TENGCDObservableObject.h"
#import "TENMoneyProtocol.h"

typedef  NS_ENUM(NSUInteger, TENEmployeeState) {
    TENEmployeeFree,
    TENEmployeePerformingWork,
    TENEmployeeReadyForMoneyOperation
};

@class TENGCDEmployee;

@protocol TENEmployeeObserver <NSObject>

@optional

- (void)employeeDidBecomeFree:(TENGCDEmployee *)employee;
- (void)employeeDidBecomePerformWork:(TENGCDEmployee *)employee;
- (void)employeeDidBecomeReadyForMoneyOperation:(TENGCDEmployee *)employee;

@end

@interface TENGCDEmployee : TENGCDObservableObject <TENMoneyProtocol>
@property (nonatomic, copy, readonly)   NSString    *name;
@property (nonatomic, assign)           NSUInteger  experience;
@property (nonatomic, assign)           NSUInteger  salary;

+ (instancetype)employeeWithName:(NSString *)name;
+ (instancetype)employeeWithIndex:(NSUInteger)index;

- (instancetype)initWithName:(NSString *)name;

- (void)performWorkWithObject:(id)object;
- (void)finalizeWorkWithObject:(id)object;

// This method is intended for subclassing. Never call it directly.
- (void)processObject:(id)object;

@end
