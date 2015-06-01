//
//  TENDispatcherEnterprise.h
//  HomeworkC
//
//  Created by 444ten on 4/22/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TENDispatcherEmployee.h"

@class TENCar;

@interface TENDispatcherEnterprise : NSObject <TENEmployeeObserver>
@property (nonatomic, readonly) NSSet   *employeeSet;

- (void)start;

@end
