//
//  TENObjectTests.c
//  HomeworkC
//
//  Created by 444ten on 3/11/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>

#include "TENObject.h"
#include "TENObjectTests.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENObjectCreateTest();

static
void TENObjectBehaviorTest();

#pragma mark -
#pragma mark Public Implementations

void TENObjectPerformTest() {
    TENObjectCreateTest();
    TENObjectBehaviorTest();
}

#pragma mark -
#pragma mark Private Implementations

void TENObjectCreateTest() {
    TENObject *object = TENObjectCreate(TENObject);
    
    assert(1 == TENObjectGetReferenceCount(object));
    
    TENRelease(object);
}

void TENObjectBehaviorTest() {
    //TENObject
    //  after retaining NULL object
    //      method should return NULL
    assert(NULL == TENRetain(NULL));
    
    //TENObject
    //  after being created
    TENObject *object = TENObjectCreate(TENObject);
    
    //      after retaining object two times
    TENRetain(TENRetain(object));
    
    //          objects reference count should equal 3
    assert(3 == TENObjectGetReferenceCount(object));
    
    //              after releasing object
    TENRelease(object);
    
    //                  objects reference count should equal 2
    assert(2 == TENObjectGetReferenceCount(object));
    
    TENRelease(object);
    TENRelease(object);
}
