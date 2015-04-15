//
//  TENWashBuilding.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENWashBuilding.h"
#import "TENCarRoom.h"

@implementation TENWashBuilding

- (id)roomWithSpecification:(NSArray *)specification {
    return [TENCarRoom carRoomWithName:specification[0]
                        peopleCapacity:[specification[1] unsignedIntegerValue]
                           carCapacity:[specification[2] unsignedIntegerValue]];
}

@end
