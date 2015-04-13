//
//  TENEntityTests.m
//  HomeworkC
//
//  Created by 444ten on 4/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <assert.h>

#import "TENEntity.h"
#import "TENEntityTests.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENEntityCreateTest();

#pragma mark -
#pragma mark Public Implementations

void TENEntityPerformTests() {
    TENEntityCreateTest();
    
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
        
        jane = [john makeEntityWithName:@"Jane" gender:TENGenderFemale weight:55.5];
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
        
        [john sayHi];
    }
    
    assert(1 == [john retainCount]);
    assert(2 == [jane retainCount]);
    
    [john release];
    assert(1 == [jane retainCount]);
    
    [jane release];
}
