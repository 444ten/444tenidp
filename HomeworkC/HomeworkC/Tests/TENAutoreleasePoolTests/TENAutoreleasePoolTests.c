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
#include "TENProperty.h"
#include "TENStack.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENAutoreleasePoolOneObjectTest();

static
void TENAutoreleasePoolMultiObjectsTest();

static
void TENAutoreleasePoolMultiplePoolsTest();

static
void TENAutoreleasePoolDrainTest();

#pragma mark -
#pragma mark Public Implementations

void TENAutoreleasePoolPerformTests() {
//    TENAutoreleasePoolOneObjectTest();
//    TENAutoreleasePoolMultiObjectsTest();
//    TENAutoreleasePoolMultiplePoolsTest();
    TENAutoreleasePoolDrainTest();


}

#pragma mark -
#pragma mark Private Implementations

void TENAutoreleasePoolDrainTest() {
    //TENAutoreleasePool
    //after calling new pool0
    TENAutoreleasePool *pool0 = TENAutoreleasePoolNew();
    
    //after adding (TENObject *)object (TENStackCapacity - 1) times
    TENObject *object = TENObjectCreate(TENObject);
    
    for (uint64_t i = 1; i < TENStackCapacity; i++) {
        TENAutoreleasePoolAddObject(pool0, TENObjectRetain(object));
    }
    
    //it stackCount should equal 1
    assert(1 == pool0->_stackCount);
//
    //after calling new pool1
    TENAutoreleasePool *pool1 = TENAutoreleasePoolNew();
    
    //after adding (TENObject *)object (TENStackCapacity - 1) times
    for (uint64_t i = 1; i < TENStackCapacity; i++) {
        TENAutoreleasePoolAddObject(pool1, TENObjectRetain(object));
    }
    
    //it stackCount should equal 2
    assert(2 == pool0->_stackCount);
//
    //after calling new pool2
    TENAutoreleasePool *pool2 = TENAutoreleasePoolNew();
    
    //after adding (TENObject *)object (TENStackCapacity - 1) times
    for (uint64_t i = 1; i < TENStackCapacity; i++) {
        TENAutoreleasePoolAddObject(pool2, TENObjectRetain(object));
    }
    
    //it stackCount should equal 3
    assert(3 == pool0->_stackCount);
//
    //after drain pool2
    TENAutoreleasePoolDrain(pool2);
    
    //it stackCount should equal 3
    assert(3 == pool0->_stackCount);
//
    //after drain pool1
    TENAutoreleasePoolDrain(pool1);
    
    //it stackCount should equal 2
    assert(2 == pool0->_stackCount);
//
    //after drain pool0
    TENAutoreleasePoolDrain(pool0);
    
    //it stackCount should equal 1
    assert(1 == pool0->_stackCount);

    //after adding object application should crash by assert
//    TENAutoreleasePoolAddObject(pool0, TENObjectRetain(object));
    
    TENObjectRelease(object);
}


void TENAutoreleasePoolMultiplePoolsTest() {
    //TENAutoreleasePool
    //after calling new pool
    TENAutoreleasePool *pool0 = TENAutoreleasePoolNew();
    
    //after adding TENObject *object 100 times
    const uint64_t count = 100;
    TENObject *object = TENObjectCreate(TENObject);
    
    for (uint64_t i = 0; i < count; i++) {
        TENAutoreleasePoolAddObject(pool0, TENObjectRetain(object));
    }
    
    //object retain count should not change
    assert(TENObjectGetReferenceCount(object) == (count + 1));
    
    //after calling new pool1
    TENAutoreleasePool *pool1 = TENAutoreleasePoolNew();
    
    //pool1 should equal pool0
    assert(pool1 == pool0);
    
    //after calling new pool2
    TENAutoreleasePool *pool2 = TENAutoreleasePoolNew();
    
    //pool2 should equal pool0
    assert(pool2 == pool0);
    
    //after draining pool2
    TENAutoreleasePoolDrain(pool2);
    
    //after adding object
    TENAutoreleasePoolAddObject(pool0, TENObjectRetain(object));
    
    //object retain count shouldn't change
    assert(TENObjectGetReferenceCount(object) == (count + 2));
    
    //after draining the pool1
    TENAutoreleasePoolDrain(pool1);
    
    //object retain count should decrement
    assert(TENObjectGetReferenceCount(object) == (count + 1));
    
    //after draining the pool
    TENAutoreleasePoolDrain(pool0);
    
    //object retain count should decrement by 100
    assert(TENObjectGetReferenceCount(object) == 1);
    
    TENObjectRelease(object);
}


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
