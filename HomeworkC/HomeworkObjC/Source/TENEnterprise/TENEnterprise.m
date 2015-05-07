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
@property (nonatomic, readwrite)    NSMutableArray  *mutableEmployees;
@property (nonatomic, readwrite)    TENBuilding     *staffBuilding;
@property (nonatomic, readwrite)    TENBuilding     *carwashBuilding;
@property (nonatomic, retain)       TENDirector     *director;
@property (nonatomic, retain)       TENAccountant   *accountant;
@property (nonatomic, retain)       TENWasher       *washer;


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
    self.staffBuilding = nil;
    self.carwashBuilding = nil;
    self.director = nil;
    self.accountant = nil;
    self.washer = nil;
    self.mutableEmployees = nil;
    
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
        TENAccountant *aAccountant = self.accountant;
        TENWasher *aWasher = self.washer;
        car.delegate = aWasher;
        [aWasher washCar:car];
        
//        [aWasher performWorkWithObject:car];
//        [aAccountant performWorkWithObject:aWasher];
//        [self.director performWorkWithObject:aAccountant];
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
    self.director = [TENDirector employeeWithName:kTENDirectorName];
    self.accountant = [TENAccountant employeeWithName:kTENAccountantName];
    self.washer = [TENWasher employeeWithName:kTENWasherName];
    
    TENDirector *aDirector = self.director;
    TENAccountant *aAccountant = self.accountant;
    TENWasher *aWasher = self.washer;
    
    aWasher.delegate = aAccountant;
    aAccountant.delegate = aDirector;
    
    NSMutableArray *aEmployees = self.mutableEmployees;
    [aEmployees addObject:aDirector];
    [aEmployees addObject:aAccountant];
    [aEmployees addObject:aWasher];
    
    TENRoom *room = self.staffBuilding.rooms[0];
    [room addEmployee:aDirector];
    [room addEmployee:aAccountant];
    
    TENCarRoom *carRoom = self.carwashBuilding.rooms[0];
    [carRoom addEmployee:aWasher];
}

@end










