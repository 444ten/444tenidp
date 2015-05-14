//
//  TENEnterprise.h
//  HomeworkC
//
//  Created by 444ten on 4/22/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TENBuilding;
@class TENCar;

@interface TENEnterprise : NSObject
@property (nonatomic, readonly)         NSArray     *employees;

- (void)workWithCar:(TENCar *)car;

@end
