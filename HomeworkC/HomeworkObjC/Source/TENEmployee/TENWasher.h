//
//  TENWasher.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEmployee.h"

@class TENCar;
@class TENWasher;

@protocol TENWasherObserver <NSObject>

- (void)washerDidBecomeFree:(TENWasher *)washer;
- (void)washerDidBecomePerformWork:(TENWasher *)washer;
- (void)washerDidBecomeReadyMoneyOperation:(TENWasher *)washer;

@end

@interface TENWasher : TENEmployee

- (void)washCar:(TENCar *)car;

- (SEL)selectorForState:(TENEmployeeState)state;

@end
