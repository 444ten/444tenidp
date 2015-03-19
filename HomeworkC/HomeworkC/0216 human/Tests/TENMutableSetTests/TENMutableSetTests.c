//
//  TENMutableSetTests.c
//  HomeworkC
//
//  Created by 444ten on 3/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "TENMutableSet.h"
#include "TENMutableSetTests.h"
#include "TENObject.h"
#include "TENString.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENMutableSetAllocateTest();

static
void TENMutableSetRemoveObjectTest();

static
void TENMutableSetBehaviorTest();

#pragma mark -
#pragma mark Public Implementations

void TENMutableSetPerformTests() {
//    TENMutableSetAllocateTest();
    TENMutableSetRemoveObjectTest();
//    TENMutableSetBehaviorTest();
}

#pragma mark -
#pragma mark Private Implementations

void TENMutableSetAllocateTest() {
    const int size = 9;
    TENObject *objectArray[size];
    uint64_t capacityAddArray[size] = {1, 2, 4, 4, 8, 8, 8, 8, 16};
    uint64_t capacityRemoveArray[size] = {16, 8, 8, 8, 8, 4, 4, 2, 1};

    //TENMutableSet
    //  after being created
    TENMutableSet *set = TENObjectCreate(TENMutableSet);

    //      capacity should equal 0
    assert(0 == set->_capacity);
    
    //      count should equal 0
    assert(0 == set->_count);
    
    //  after each adding object in cycle
    //      capacity should equal capacityAddArray[i]
    //      count should equal (i + 1)
    for (int i = 0; i < size; i++) {
        objectArray[i] = TENObjectCreate(TENObject);
        
        TENMutableSetAddObject(set, objectArray[i]);
        
        assert(capacityAddArray[i] == set->_capacity);
        assert((i + 1) == set->_count);
    }
    
    //  after each removing object in cycle
    //      capacity should equal capacityRemoveArray[i]
    //      count should equal siz - 1 - i
    for (int i = 0; i < size; i++) {
        TENMutableSetRemoveLastObject(set);
        assert(capacityRemoveArray[i] == set->_capacity);
        assert((size - 1 - i) == set->_count);
    }
    
    //releasing objects
    for (int i = 0; i < size; i++) {
        TENObjectRelease(objectArray[i]);
    }
    
    TENObjectRelease(set);
}

void TENMutableSetRemoveObjectTest() {
    TENObject *object0 = TENObjectCreate(TENObject);
    TENObject *object1 = TENObjectCreate(TENObject);
    TENObject *object2 = TENObjectCreate(TENObject);
    TENObject *object3 = TENObjectCreate(TENObject);
    
    //TENMutableSet
    //  after being created
    TENMutableSet *set = TENObjectCreate(TENMutableSet);
    
    //      after adding object0
    TENMutableSetAddObject(set, object0);
    
    //          count should equal 1
    assert(1 == set->_count);
    
    //          set->-array[0] should equal object0
    assert(object0 == set->_array[0]);
    
    //              after removing last object
    TENMutableSetRemoveLastObject(set);
    
    //                  count should equal 0
    assert(0 == set->_count);
    
    //                  set->-array[0] should equal NULL
    assert(NULL == set->_array[0]);
    
    //      after adding four object
    TENMutableSetAddObject(set, object0);
    TENMutableSetAddObject(set, object1);
    TENMutableSetAddObject(set, object2);
    TENMutableSetAddObject(set, object3);
    
    //          count should equal 4
    assert(4 == set->_count);
    
    //              after removing object2 twice
    TENMutableSetRemoveObject(set, object2);
    TENMutableSetRemoveObject(set, object2);
    
    //              after removing object at index 5
    TENMutableSetRemoveObjectAtIndex(set, 5);
    
    //                  count should equal 3
    assert(3 == set->_count);
    
    //              after removing object at index 1
    TENMutableSetRemoveObjectAtIndex(set, 1);
    
    //                  count should equal 2
    assert(2 == set->_count);
    
    //                  set->-array[1] should equal object3
    assert(object3 == set->_array[1]);
    
    //                  set->-array[2] should equal NULL
    assert(NULL == set->_array[2]);
    
    //                      after removing all object
    TENMutableSetRemoveAllObjects(set);
    
    //                          count should equal 0
    assert(0 == set->_count);
    
    //                          set->-array[0] should equal NULL
    assert(NULL == set->_array[0]);
    
    //releasing objects
    TENObjectRelease(object0);
    TENObjectRelease(object1);
    TENObjectRelease(object2);
    TENObjectRelease(object3);
    
    TENObjectRelease(set);
 }

//add object
//add same object
//add NULL object
//index of object
//get size

void TENMutableSetBehaviorTest() {
    TENObject *obj1 = TENObjectCreate(TENObject);
    TENObject *obj2 = TENObjectCreate(TENObject);
    TENObject *obj3 = TENObjectCreate(TENObject);

    //TENMutableSet
    //  after being created
    TENMutableSet *set = TENObjectCreate(TENMutableSet);
    assert(TENIndexNotFound == TENMutableSetIndexOfObject(set, NULL));
    TENMutableSetRemoveAllObjects(set);
    
    //      size should equal 0
    assert(0 == set->_count);
    
    //      capacity should equal 0
    assert(0 == set->_capacity);
    
    //          after adding object
    TENMutableSetAddObject(set, obj1);
    TENMutableSetAddObject(set, obj1);
    
    //              size should equal 1
    assert(1 == set->_count);
    
    //              capacity should equal 5
    assert(1 == set->_capacity);
    
    //              object reference count equal 2
    assert(2 == obj1->_referenceCount);
    
    //              set->_array[0] = object
    assert(set->_array[0] == obj1);
    
    TENMutableSetAddObject(set, obj2);
    assert(set->_array[1] == obj2);
    
    assert(0 == TENMutableSetIndexOfObject(set, obj1));
    assert(1 == TENMutableSetIndexOfObject(set, obj2));
    
    assert(TENIndexNotFound == TENMutableSetIndexOfObject(set, obj3));
    
    assert(TENIndexNotFound == TENMutableSetIndexOfObject(set, NULL));
    
    TENMutableSetAddObject(set, obj3);
    TENMutableSetRemoveObject(set, obj2);
    
    assert(set->_array[0] == obj1);
    assert(set->_array[1] == obj3);
    assert(2 == set->_count);
    assert(1 == obj2->_referenceCount);
    
    TENMutableSetRemoveAllObjects(set);
    assert(0 == set->_count);
    assert(1 == set->_capacity);
    assert(set->_array[0] == NULL);
    assert(set->_array[1] == NULL);
    
    assert(TENIndexNotFound == TENMutableSetIndexOfObject(set, NULL));
    
    assert(1 == obj1->_referenceCount);
    assert(1 == obj3->_referenceCount);
    
    TENObjectRelease(obj1);
    TENObjectRelease(obj2);
    TENObjectRelease(obj3);
    
    TENObjectRelease(set);
}
