//
//  TENAutoreleasePoolTests.c
//  HomeworkC
//
//  Created by 444ten on 4/6/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>

#include "TENAutoreleasePool.h"
#include "TENAutoreleasePoolTests.h"
#include "TENObject.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENAutoreleasePoolOneObjectTest();

static
void TENAutoreleasePoolMultiObjectsTest();

#pragma mark -
#pragma mark Public Implementations

void TENAutoreleasePoolPerformTests() {
//    TENAutoreleasePoolOneObjectTest();
    TENAutoreleasePoolMultiObjectsTest();
}

#pragma mark -
#pragma mark Private Implementations

void TENAutoreleasePoolOneObjectTest() {
    //TENAutoreleasePool
    //after calling new pool
    //after adding (TENObject *)object
    //it stackCount should equal 1
    //object retain count should not change
    
    TENAutoreleasePool *pool = TENAutoreleasePoolNew();
    
    TENObject *object = TENObjectCreate(TENObject);
    
    TENAutoreleasePoolAddObject(pool, TENObjectRetain(object));
    
    assert(1 == pool->_stackCount);
    assert(TENObjectGetReferenceCount(object) == 2);

    TENObjectRelease(object);

}

void TENAutoreleasePoolMultiObjectsTest() {
    //TENAutoreleasePool
    //after calling new pool0
    //after adding (TENObject *)object 14 times
    //it stackCount should equal 1
    //object retain count should not change
    //after calling new pool1
    //pool1 should equal pool0
    //it stackCount should equal 1
    //after adding (TENObject *)object
    //it stackCount should equal 2
    
    TENAutoreleasePool *pool0 = TENAutoreleasePoolNew();
    
    TENObject *object = TENObjectCreate(TENObject);
    const uint64_t count = 14;
    
    for (uint64_t i = 0; i < count; i++) {
        TENAutoreleasePoolAddObject(pool0, TENObjectRetain(object));
    }
    
    assert(1 == pool0->_stackCount);
    assert(TENObjectGetReferenceCount(object) == (1 + count));
    
    TENAutoreleasePool *pool1 = TENAutoreleasePoolNew();
    assert(pool0 == pool1);
    assert(1 == pool0->_stackCount);

    TENAutoreleasePoolAddObject(pool1, TENObjectRetain(object));
    assert(2 == pool0->_stackCount);
    
    TENObjectRelease(object);
}
