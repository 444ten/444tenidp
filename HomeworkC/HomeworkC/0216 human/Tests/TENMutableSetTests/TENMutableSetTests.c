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
void TENMutableSetAllocateObjectTest();

static
void TENMutableSetBehaviorTest();

static
void TENMutableSetAllocateTest();

#pragma mark -
#pragma mark Public Implementations

void TENMutableSetPerformTests() {
//    TENMutableSetAllocateObjectTest();
    TENMutableSetAllocateTest();
//    TENMutableSetBehaviorTest();
}

#pragma mark -
#pragma mark Private Implementations

void TENMutableSetAllocateObjectTest() {
    TENObject *obj1 = TENObjectCreate(TENObject);
    TENObject *obj2 = TENObjectCreate(TENObject);
    TENObject *obj3 = TENObjectCreate(TENObject);
    TENObject *obj4 = TENObjectCreate(TENObject);
    TENObject *obj5 = TENObjectCreate(TENObject);
    TENObject *obj6 = TENObjectCreate(TENObject);
    TENObject *obj7 = TENObjectCreate(TENObject);
    TENObject *obj8 = TENObjectCreate(TENObject);
    TENObject *obj9 = TENObjectCreate(TENObject);
    
    TENMutableSet *set = TENObjectCreate(TENMutableSet);
    TENMutableSetAddObject(set, obj1);
    TENMutableSetAddObject(set, obj2);
    TENMutableSetAddObject(set, obj3);
    TENMutableSetAddObject(set, obj4);
    TENMutableSetAddObject(set, obj5);
    TENMutableSetAddObject(set, obj6);
//    TENMutableSetAddObject(set, obj7);
//    TENMutableSetAddObject(set, obj8);
//    TENMutableSetAddObject(set, obj9);
    
    TENObjectRelease(obj1);
    TENObjectRelease(obj2);
    TENObjectRelease(obj3);
    TENObjectRelease(obj4);
    TENObjectRelease(obj5);
    TENObjectRelease(obj6);
    TENObjectRelease(obj7);
    TENObjectRelease(obj8);
    TENObjectRelease(obj9);
    
    TENObjectRelease(set);
}

#define TENMutableSetObjectCreateAndAdd(value, capacity)\
    TENString *obj##value = TENObjectCreate(TENString);\
    TENMutableSetAddObject(set, obj##value); \
    assert(capacity == set->_capacity);\
    assert(value + 1 == set->_size);

void TENMutableSetAllocateTest() {
    TENMutableSet *set = TENObjectCreate(TENMutableSet);
    assert(0 == set->_capacity);
    assert(0 == set->_size);

    uint64_t capacityArray[9] = {1, 2, 4, 4, 8, 8, 8, 8, 16};
    
//    for (uint64_t i = 0; i < 9; i++) {
//        TENMutableSetObjectCreateAndAdd(i, capacityArray[i]);
//    }
    
    int i = 0;
    TENMutableSetObjectCreateAndAdd(0, capacityArray[i])
    
    TENMutableSetRemoveLastObject(set); // size 8
    assert(16 == set->_capacity);
    
    TENMutableSetRemoveLastObject(set); // size 7
    assert(8 == set->_capacity);
    
    TENMutableSetRemoveLastObject(set); // size 6
    assert(8 == set->_capacity);

    TENMutableSetRemoveLastObject(set); // size 5
    assert(8 == set->_capacity);
    
    TENMutableSetRemoveLastObject(set); // size 4
    assert(8 == set->_capacity);
    
    TENMutableSetRemoveLastObject(set); // size 3
    assert(4 == set->_capacity);
    
    TENMutableSetRemoveLastObject(set); // size 2
    assert(4 == set->_capacity);
    
    TENMutableSetRemoveLastObject(set); // size 1
    assert(2 == set->_capacity);
    
    TENMutableSetRemoveLastObject(set); // size 0
    assert(1 == set->_capacity);
    
    TENObjectRelease(obj0);
//    TENObjectRelease(obj1);
//    TENObjectRelease(obj2);
//    TENObjectRelease(obj3);
//    TENObjectRelease(obj4);
//    TENObjectRelease(obj5);
//    TENObjectRelease(obj6);
//    TENObjectRelease(obj7);
//    TENObjectRelease(obj8);

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
    TENString *obj1 = TENObjectCreate(TENString);
    TENString *obj2 = TENObjectCreate(TENString);
    TENString *obj3 = TENObjectCreate(TENString);

    //TENMutableSet
    //  after being created
    TENMutableSet *set = TENObjectCreate(TENMutableSet);
    assert(TENIndexNotFound == TENMutableSetIndexOfObject(set, NULL));
    TENMutableSetRemoveAllObjects(set);
    
    //      size should equal 0
    assert(0 == set->_size);
    
    //      capacity should equal 0
    assert(0 == set->_capacity);
    
    //          after adding object
    TENMutableSetAddObject(set, obj1);
    TENMutableSetAddObject(set, obj1);
    
    //              size should equal 1
    assert(1 == set->_size);
    
    //              capacity should equal 5
    assert(1 == set->_capacity);
    
    //              object reference count equal 2
    assert(2 == obj1->_object._referenceCount);
    
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
    assert(2 == set->_size);
    assert(1 == obj2->_object._referenceCount);
    
    TENMutableSetRemoveAllObjects(set);
    assert(0 == set->_size);
    assert(1 == set->_capacity);
    assert(set->_array[0] == NULL);
    assert(set->_array[1] == NULL);
    
    assert(TENIndexNotFound == TENMutableSetIndexOfObject(set, NULL));
    
    assert(1 == obj1->_object._referenceCount);
    assert(1 == obj3->_object._referenceCount);
    
    TENObjectRelease(obj1);
    TENObjectRelease(obj2);
    TENObjectRelease(obj3);
    
    TENObjectRelease(set);
}
