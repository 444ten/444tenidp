//
//  TENStaffBuilding.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENStaffBuilding.h"
#import "TENRoom.h"

@implementation TENStaffBuilding

- (id)roomWithSpecification:(NSArray *)specification {
    return [TENRoom roomWithName:specification[0]
                  peopleCapacity:[specification[1] unsignedIntegerValue]];
}

@end
