//
//  TENEnterprise.m
//  HomeworkC
//
//  Created by 444ten on 4/22/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEnterprise.h"

#import "NSObject+TENExtensions.h"
#import "TENAccountant.h"
#import "TENBuilding.h"
#import "TENCar.h"
#import "TENCarRoom.h"
#import "TENDirector.h"
#import "TENRoom.h"
#import "TENWasher.h"

static const NSUInteger kTENRoomPeopleCapacity = 2;
static const NSUInteger kTENCarRoomPeopleCapacity = 1;
static const NSUInteger kTENCarCapacity = 1;
static  NSString *kTENDirectorName = @"Director";
static  NSString *kTENAccountantName = @"Accountant";
static  NSString *kTENWasherName = @"Washer";

@interface TENEnterprise()
@property (nonatomic, readwrite)        NSMutableArray  *mutableEmployees;
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
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableEmployees = nil;
    self.staffBuilding = nil;
    self.carwashBuilding = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployees = [NSMutableArray array];
        [self prepareBuilding];
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors Methods

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)performWorkWithCar:(TENCar *)car {
    if (!car.isClean) {
        TENDirector *director = self.mutableEmployees[0];
        TENAccountant *accountant = self.mutableEmployees[1];
        TENWasher *washer = self.mutableEmployees[2];
        
        [washer performWorkWithObject:car];
        [accountant performWorkWithObject:washer];
        [director performWorkWithObject:accountant];
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)prepareBuilding {
    [self prepareStaffBuilding];
    [self prepareCarwashBuilding];
}

- (void)prepareStaffBuilding {
    TENRoom *room = [TENRoom object];
    room.peopleCapacity = kTENRoomPeopleCapacity;
    
    self.staffBuilding = [TENBuilding object];
    [self.staffBuilding addRoom:room];
}

- (void)prepareCarwashBuilding {
    TENCarRoom *carRoom = [TENCarRoom object];
    carRoom.peopleCapacity = kTENCarRoomPeopleCapacity;
    carRoom.carCapacity = kTENCarCapacity;

    self.carwashBuilding = [TENBuilding object];
    [self.carwashBuilding addRoom:carRoom];
}

- (void)hireStaff {
    TENDirector *director = [TENDirector employeeWithName:kTENDirectorName];
    TENAccountant *accountant = [TENAccountant employeeWithName:kTENAccountantName];
    TENWasher *washer = [TENWasher employeeWithName:kTENWasherName];
    
    [self.mutableEmployees addObjectsFromArray:@[director, accountant, washer]];
    
    [self.staffBuilding.rooms[0] addEmployee:director];
    [self.staffBuilding.rooms[0] addEmployee:accountant];
    [self.carwashBuilding.rooms[0] addEmployee:washer];
}

@end










