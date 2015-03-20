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

#pragma mark -
#pragma mark Private Declarations

static
void TENMutableSetAllocateTest();

static
void TENMutableSetAddObjectTest();

static
void TENMutableSetRemoveObjectTest();

#pragma mark -
#pragma mark Public Implementations

void TENMutableSetPerformTests() {
    TENMutableSetAllocateTest();
    TENMutableSetAddObjectTest();
    TENMutableSetRemoveObjectTest();
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
    assert(0 == TENMutableSetGetCount(set));
    
    //  after each adding object in cycle
    //      capacity should equal capacityAddArray[i]
    //      count should equal (i + 1)
    for (int i = 0; i < size; i++) {
        objectArray[i] = TENObjectCreate(TENObject);
        
        TENMutableSetAddObject(set, objectArray[i]);
        
        assert(capacityAddArray[i] == set->_capacity);
        assert((i + 1) ==  TENMutableSetGetCount(set));
    }
    
    //  after each removing object in cycle
    //      capacity should equal capacityRemoveArray[i]
    //      count should equal siz - 1 - i
    for (int i = 0; i < size; i++) {
        TENMutableSetRemoveLastObject(set);
        assert(capacityRemoveArray[i] == set->_capacity);
        assert((size - 1 - i) ==  TENMutableSetGetCount(set));
    }
    
    //releasing objects
    for (int i = 0; i < size; i++) {
        TENObjectRelease(objectArray[i]);
    }
    
    TENObjectRelease(set);
}

void TENMutableSetAddObjectTest() {
    TENObject *object0 = TENObjectCreate(TENObject);
    TENObject *object1 = TENObjectCreate(TENObject);
    TENObject *object2 = TENObjectCreate(TENObject);

    //TENMutableSet
    //  after being created
    TENMutableSet *set = TENObjectCreate(TENMutableSet);
    
    //      after adding object0 and object1
    TENMutableSetAddObject(set, object0);
    TENMutableSetAddObject(set, object1);
    
    //          index of object1 should equal 1
    assert(1 == TENMutableSetIndexOfObject(set, object1));
    
    //          index of object2 should equal TENIndexNotFound
    assert(!TENMutableSetContainObject(set, object2));
    
    //              after adding NULL-object and object2
    TENMutableSetAddObject(set, NULL);
    TENMutableSetAddObject(set, object2);
    
    //                  count should equal 3
    assert(3 == TENMutableSetGetCount(set));
    
    //                  set->-array[2] should equal object2
    assert(object2 == TENMutableSetGetObjectAtIndex(set, 2));
    
    //                      after adding object1
    TENMutableSetAddObject(set, object1);
    
    //                          count should equal 3
    assert(3 == TENMutableSetGetCount(set));

    //                          set->-array[3] should equal NULL
    assert(NULL == TENMutableSetGetObjectAtIndex(set, 3));
    
    //releasing objects
    TENObjectRelease(object0);
    TENObjectRelease(object1);
    TENObjectRelease(object2);
    
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
    assert(1 == TENMutableSetGetCount(set));
    
    //          set->-array[0] should equal object0
    assert(object0 == TENMutableSetGetObjectAtIndex(set, 0));
    
    //              after removing last object
    TENMutableSetRemoveLastObject(set);
    
    //                  count should equal 0
    assert(0 == TENMutableSetGetCount(set));
    
    //                  set->-array[0] should equal NULL
    assert(NULL == TENMutableSetGetObjectAtIndex(set, 0));
    
    //      after adding four object
    TENMutableSetAddObject(set, object0);
    TENMutableSetAddObject(set, object1);
    TENMutableSetAddObject(set, object2);
    TENMutableSetAddObject(set, object3);
    
    //          count should equal 4
    assert(4 == TENMutableSetGetCount(set));
    
    //              after removing object2 twice
    TENMutableSetRemoveObject(set, object2);
    TENMutableSetRemoveObject(set, object2);
    
    //              after removing object at index 5
    TENMutableSetRemoveObjectAtIndex(set, 5);
    
    //                  count should equal 3
    assert(3 == TENMutableSetGetCount(set));
    
    //              after removing object at index 1
    TENMutableSetRemoveObjectAtIndex(set, 1);
    
    //                  count should equal 2
    assert(2 == TENMutableSetGetCount(set));
    
    //                  set->-array[1] should equal object3
    assert(object3 == TENMutableSetGetObjectAtIndex(set, 1));
    
    //                  set->-array[2] should equal NULL
    assert(NULL == TENMutableSetGetObjectAtIndex(set, 2));
    
    //                      after removing all object
    TENMutableSetRemoveAllObjects(set);
    
    //                          count should equal 0
    assert(0 == TENMutableSetGetCount(set));
    
    //                          set->-array[0] should equal NULL
    assert(NULL == TENMutableSetGetObjectAtIndex(set, 0));
    
    //releasing objects
    TENObjectRelease(object0);
    TENObjectRelease(object1);
    TENObjectRelease(object2);
    TENObjectRelease(object3);
    
    TENObjectRelease(set);
 }
