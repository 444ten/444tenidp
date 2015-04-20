//
//  TENEmployeeWasher.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEmployee.h"

@class TENCar;

@interface TENEmployeeWasher : TENEmployee

- (void)washCar:(TENCar *)car;
- (void)takeMoney:(NSUInteger)money fromCar:(TENCar *)car;

@end
