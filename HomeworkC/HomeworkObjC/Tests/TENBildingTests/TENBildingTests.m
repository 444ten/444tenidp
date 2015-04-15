//
//  TENBildingTests.m
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENBildingTests.h"
#import "TENCarRoom.h"
#import "TENStaffBuilding.h"
#import "TENWashBilding.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENCarRoomTest();

static
void TENBuildingTest();

#pragma mark -
#pragma mark Public Implementations

void TENBildingPerformTests() {
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
    TENStaffBuilding *staffBuilding = [TENStaffBuilding bildingWithName:@"Admin"];
    
//    : name, peopleCapacity
    NSDictionary *masterplanStaff = @{@(1) : @[@"Director"    , @(1)],
                                      @(2) : @[@"Accountant's", @(3)],
                                      @(3) : @[@"Washer's"    , @(6)],};

    [staffBuilding buildWithMasterplan:masterplanStaff];
    
    TENWashBilding *washBilding = [TENWashBilding bildingWithName:@"Wash"];

//    : name, peopleCapacity, carCapacity    
    NSDictionary *masterplanWash = @{@(1) : @[@"Big"   , @(6), @(3)],
                                     @(2) : @[@"Medium", @(4), @(2)],
                                     @(3) : @[@"Small" , @(2), @(1)],};

    [washBilding buildWithMasterplan:masterplanWash];
}

