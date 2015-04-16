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
    TENCarRoom *carRoom = [TENCarRoom carRoomWithName:@"car wash 1"
                                       peopleCapacity:3
                                          carCapacity:2];
    NSLog(@"%@", carRoom);
}

void TENBuildingTest() {
    TENStaffBuilding *staffBuilding = [TENStaffBuilding buildingWithName:@"Admin"];
    
//    : name, peopleCapacity
    NSDictionary *masterplanStaff = @{@(1) : @[@"Director"    , @(1)],
                                      @(2) : @[@"Accountant's", @(3)],
                                      @(3) : @[@"Washer's"    , @(6)],};

    [staffBuilding buildWithMasterplan:masterplanStaff];
    
    TENWashBuilding *washBuilding = [TENWashBuilding buildingWithName:@"Wash"];

    NSMutableString *big = [NSMutableString stringWithString:@"BIG"];
//    : name, peopleCapacity, carCapacity    
    NSDictionary *masterplanWash = @{@(1) : @[big   , @(6), @(3)],
                                     @(2) : @[@"Medium", @(4), @(2)],
                                     @(3) : @[@"Small" , @(2), @(1)],};

    [washBuilding buildWithMasterplan:masterplanWash];
    
    [big appendString:@" very"];
}

