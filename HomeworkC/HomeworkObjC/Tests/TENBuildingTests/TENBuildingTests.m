//
//  TENBuildingTests.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENBuildingTests.h"
#import "TENCarRoom.h"
#import "TENStaffBuilding.h"
#import "TENWashBuilding.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENCarRoomTest();

static
void TENBuildingTest();

#pragma mark -
#pragma mark Public Implementations

void TENBuildingPerformTests() {
    TENCarRoomTest();
    TENBuildingTest();
}

#pragma mark -
#pragma mark Private Implementations

void TENCarRoomTest() {
    TENCarRoom *carRoom = [TENCarRoom objectWithName:@"car wash 1"];
    carRoom.peopleCapacity = 3;
    carRoom.carCapacity = 1;
                           
    NSLog(@"%@", carRoom);
}

void TENBuildingTest() {

}

