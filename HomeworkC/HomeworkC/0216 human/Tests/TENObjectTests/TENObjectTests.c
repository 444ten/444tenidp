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
    
    TENObjectRelease(object);
}

void TENObjectBehaviorTest() {
    //after retain NULL object, method should return NULL
    assert(NULL == TENObjectRetain(NULL));
    
    //TENObject
    //  after being created
    TENObject *object = TENObjectCreate(TENObject);
    
    //      after retain object two times
    TENObjectRetain(TENObjectRetain(object));
    
    //          objects reference count should be equal 3
    assert(3 == TENObjectGetReferenceCount(object));
    
    //              after release object
    TENObjectRelease(object);
    
    //                  objects reference count should equal 2
    assert(2 == TENObjectGetReferenceCount(object));
    
    TENObjectRelease(object);
    TENObjectRelease(object);
}
