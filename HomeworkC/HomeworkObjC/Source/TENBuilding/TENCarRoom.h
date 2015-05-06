//
//  TENCarRoom.h
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENRoom.h"

@class TENCar;

@interface TENCarRoom : TENRoom
@property (nonatomic, assign)   NSUInteger  carCapacity;
@property (nonatomic, readonly) NSArray     *cars;

- (void)addCar:(TENCar *)car;
- (void)removeCar:(TENCar *)car;

@end
