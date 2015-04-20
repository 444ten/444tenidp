//
//  TENEntityTests.m
//  HomeworkC
//
//  Created by 444ten on 4/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <assert.h>

#import "TENEntity.h"
#import "TENEntityFemale.h"
#import "TENEntityMale.h"
#import "TENEntityTests.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENEntityCreateTest();

static
void TENEntityMakeEntityTest();

static
void TENEntityMaleFemaleTest();

static
void TENEntityFemaleMakeChildTest();

#pragma mark -
#pragma mark Public Implementations

void TENEntityPerformTests() {
    TENEntityCreateTest();
    TENEntityMakeEntityTest();
    TENEntityMaleFemaleTest();
    TENEntityFemaleMakeChildTest();
}

#pragma mark -
#pragma mark Private Implementations

void TENEntityCreateTest() {
    //TENEntity
    //after being init john, jane, mike, barbie
    TENEntity *john = nil;
    TENEntity *jane = nil;
    TENEntity *mike = nil;
    TENEntity *barbie = nil;
    
    @autoreleasepool {
        john = [TENEntity entityWithName:@"John" gender:TENGenderMale age:16 weight:70.6];
        [john retain];
        assert(2 == [john retainCount]);
        
        jane = [john makeChildWithName:@"Jane" gender:TENGenderFemale weight:55.5];
        [jane retain];
        assert(2 == [jane retainCount]);
        
        [john addChild:jane];
        assert(3 == [jane retainCount]);
        
        mike = [TENEntity entityWithName:@"Mike" gender:TENGenderMale age:10 weight:40.1];
        barbie = [TENEntity entityWithName:@"Barbie" gender:TENGenderFemale age:40 weight:60.4];
        
        [john removeChild:mike];
        
        [john addChild:john];
        assert(3 == [jane retainCount]);
        
        [john children];
        assert(4 == [jane retainCount]);

        [john children];
        assert(5 == [jane retainCount]);
        
        [john addChild:mike];
        [jane addChild:barbie];
        [jane addChild:mike];
    }
    
    assert(1 == [john retainCount]);
    assert(2 == [jane retainCount]);
    
    [john release];
    assert(1 == [jane retainCount]);
    
    [jane release];
}

void TENEntityMakeEntityTest() {
    TENEntity *viktor = [TENEntity entityWithName:@"Viktor"
                                           gender:TENGenderMale
                                              age:62
                                           weight:80.8];
    TENEntity *natali = [TENEntity entityWithName:@"Natali"
                                           gender:TENGenderFemale
                                              age:50
                                           weight:60.6];
    TENEntity *andrey = [TENEntity entityWithName:@"Andrey"
                                           gender:TENGenderMale
                                              age:40
                                           weight:74.7];
    
    NSArray *entityArray = @[viktor, natali, andrey];
    
    TENEntity *vitaliy = [TENEntity entityWithName:@"Vitaliy"
                                            gender:TENGenderMale
                                               age:38
                                            weight:77.7];
    TENEntity *yulia = [TENEntity entityWithName:@"Yulia"
                                          gender:TENGenderFemale
                                             age:35
                                          weight:50.1];
    TENEntity *anna = [TENEntity entityWithName:@"Anna"
                                         gender:TENGenderFemale
                                            age:37
                                         weight:60.1];
    TENEntity *sergey = [TENEntity entityWithName:@"Sergeyy"
                                           gender:TENGenderMale
                                              age:20
                                           weight:60.7];
    [viktor addChild:vitaliy];
    [viktor addChild:yulia];
    [natali addChild:anna];
    [andrey addChild:sergey];

    NSMutableArray *makeEntityArray = [[NSMutableArray new] autorelease];
    
    for (TENEntity *entity in entityArray) {
        if (TENGenderFemale == [entity gender]) {
            [makeEntityArray addObject:[entity makeChildWithName:@"noname"
                                                          gender:TENGenderFemale
                                                          weight:2.5]];
        } else {
            [entity fight];
        }
    }
}

void TENEntityMaleFemaleTest() {
    TENEntityMale *ivan = [TENEntityMale entityWithName:@"Ivan" age:30 weight:70];
    TENEntityFemale *mary = [TENEntityFemale entityWithName:@"Mary" age:25 weight:50];
    
    [ivan performGenderSpecificOperation];
    [mary performGenderSpecificOperation];
}

void TENEntityFemaleMakeChildTest() {
    TENEntityFemale *anna = [TENEntityFemale entityWithName:@"Anna"
                                                        age:37
                                                     weight:60.1];
    [anna performGenderSpecificOperation];

    id petr = [anna makeChildWithGender:TENGenderMale name:@"Petr" weight:2.5];
    [petr performGenderSpecificOperation];
    
    id inna = [anna makeChildWithGender:TENGenderFemale name:@"Inna" weight:2.5];
    [inna performGenderSpecificOperation];    
}
