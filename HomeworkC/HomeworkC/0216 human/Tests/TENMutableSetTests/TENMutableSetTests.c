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
void TENMutableSetBehaviorTest();

static
void TENMutableSetAllocateTest();

#pragma mark -
#pragma mark Public Implementations

void TENMutableSetPerformTests() {
    TENMutableSetAllocateTest();
//    TENMutableSetBehaviorTest();
}

#pragma mark -
#pragma mark Private Implementations

void TENMutableSetAllocateTest() {
    const int size = 9;
    TENObject *objectArray[size];
    uint64_t capacityAddArray[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    uint64_t capacityAddArray[size] = {20, 20, 20, 20, 20, 20, 20, 20, 20};
    uint64_t capacityRemoveArray[size] = {8, 7, 6, 5, 4, 3, 2, 1, 0};
//    uint64_t capacityRemoveArray[size] = {20, 20, 20, 20, 20, 20, 20, 20, 20};

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
    
    // release objects
    for (int i = 0; i < size; i++) {
        TENObjectRelease(objectArray[i]);
    }
    
    TENObjectRelease(set);
}

//add object
//add same object
//add NULL object
//remove included object
//remove not-included object
//remove all objects
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
