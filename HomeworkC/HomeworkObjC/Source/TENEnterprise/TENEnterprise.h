//
//  TENEnterprise.h
//  HomeworkC
//
//  Created by 444ten on 4/22/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TENEmployee.h"

@class TENCar;

@interface TENEnterprise : NSObject <TENEmployeeObserver>
@property (nonatomic, readonly) NSSet   *employeeSet;
@property (nonatomic, readonly) NSArray *cars;

- (void)workWithCar:(TENCar *)car;

- (void)addCar:(TENCar *)car;
- (void)removeCar:(TENCar *)car;

@end
