//
//  TENCarRoom.h
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENRoom.h"

@interface TENCarRoom : TENRoom
@property (nonatomic, assign)   NSUInteger  carCapasity;

+ (instancetype)carRoomWithName:(NSString *)name
                 peopleCapacity:(NSUInteger)peopleCapacity
                    carCapacity:(NSUInteger)carCapacity;

@end
