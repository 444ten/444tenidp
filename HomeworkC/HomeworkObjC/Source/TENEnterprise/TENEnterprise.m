//
//  TENEnterprise.m
//  HomeworkC
//
//  Created by 444ten on 4/22/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEnterprise.h"

#import "TENBuilding.h"
#import "TENRoom.h"
#import "TENCarRoom.h"
#import "TENDirector.h"
#import "TENAccountant.h"
#import "TENWasher.h"

@interface TENEnterprise()
@property (nonatomic, copy, readwrite)  NSString        *name;
@property (nonatomic, readwrite)        NSMutableArray  *employeesMutableArray;
@property (nonatomic, readwrite)        TENBuilding     *staffBuilding;
@property (nonatomic, readwrite)        TENBuilding     *carwashBuilding;

- (void)prepareBuilding;
- (void)hireStaff;
- (void)prepareStaffBuilding;
- (void)prepareCarwashBuilding;

@end

@implementation TENEnterprise

@dynamic employees;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)enterpriseWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.employeesMutableArray = nil;
    self.staffBuilding = nil;
    self.carwashBuilding = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        [self prepareBuilding];
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors Methods

- (NSArray *)employees {
    return [[self.employeesMutableArray copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

#pragma mark -
#pragma mark Private Methods

- (void)prepareBuilding {
    [self prepareStaffBuilding];
    [self prepareCarwashBuilding];
}

- (void)prepareStaffBuilding {
    TENRoom *room = [[TENRoom new] autorelease];
    room.peopleCapacity = 2;

    self.staffBuilding = [TENBuilding buildingWithName:@"Staff"];
    [self.staffBuilding addRoom:room];
}

- (void)prepareCarwashBuilding {
    TENCarRoom *carRoom = [[TENCarRoom new] autorelease];
    carRoom.peopleCapacity = 1;
    carRoom.carCapacity = 1;

    self.carwashBuilding = [TENBuilding buildingWithName:@"CarWash"];
    [self.carwashBuilding addRoom:carRoom];
}

- (void)hireStaff {
    TENDirector *director = [TENDirector employeeWithName:@"Ivan Ivanovich"];
    TENAccountant *accountant = [TENAccountant employeeWithName:@"Natali"];
    TENWasher *washer = [TENWasher employeeWithName:@"Vasya"];

    self.employeesMutableArray = [NSMutableArray arrayWithArray:@[director, accountant, washer]];
}

@end
