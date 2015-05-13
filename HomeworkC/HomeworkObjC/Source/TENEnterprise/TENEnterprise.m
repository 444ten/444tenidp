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

static const NSUInteger kTENRoomPeopleCapacity      = 2;
static const NSUInteger kTENCarRoomPeopleCapacity   = 1;
static const NSUInteger kTENCarCapacity             = 1;

static  NSString * const kTENDirectorName   = @"Director";
static  NSString * const kTENAccountantName = @"Accountant";
static  NSString * const kTENWasherName     = @"Washer";

@interface TENEnterprise()
@property (nonatomic, retain)   NSMutableArray  *mutableEmployees;
@property (nonatomic, retain)   TENBuilding     *staffBuilding;
@property (nonatomic, retain)   TENBuilding     *carwashBuilding;
@property (nonatomic, retain)   TENDirector     *director;
@property (nonatomic, retain)   TENAccountant   *accountant;
@property (nonatomic, retain)   TENWasher       *washer;

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
#pragma mark Accessors

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}

#pragma mark -
#pragma mark Public

- (void)workWithCar:(TENCar *)car {
    if (!car.isClean) {
        [self.washer performWorkWithObject:car];
    }
}

#pragma mark -
#pragma mark Private

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
    
    TENDirector *director = self.director;
    TENAccountant *accountant = self.accountant;
    TENWasher *washer = self.washer;
    
    washer.delegate = accountant;
    accountant.delegate = director;
    
    NSMutableArray *employees = self.mutableEmployees;
    [employees addObject:director];
    [employees addObject:accountant];
    [employees addObject:washer];
    
    TENRoom *room = self.staffBuilding.rooms[0];
    [room addEmployee:director];
    [room addEmployee:accountant];
    
    TENCarRoom *carRoom = self.carwashBuilding.rooms[0];
    [carRoom addEmployee:washer];
}

@end
