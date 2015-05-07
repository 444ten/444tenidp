//
//  TENWasher.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEmployee.h"

#import "TENCar.h"

@interface TENWasher : TENEmployee <TENCarDelegate>

- (void)washCar:(TENCar *)car;

@end
