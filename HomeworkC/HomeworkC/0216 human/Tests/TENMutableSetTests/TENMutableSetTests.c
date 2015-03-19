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
void TENMutableSetBehaviorTest();

static
void TENMutableSetAllocateTest();

static
void TENObjectArrayItemCreateAndAddToSet(TENObject **objectArray, int index,  TENMutableSet *set);


#pragma mark -
#pragma mark Public Implementations

void TENMutableSetPerformTests() {
    TENMutableSetAllocateTest();
//    TENMutableSetBehaviorTest();
}

#pragma mark -
#pragma mark Private Implementations

void TENObjectArrayItemCreateAndAddToSet(TENObject **objectArray, int index,  TENMutableSet *set) {
    objectArray[index] = TENObjectCreate(TENObject);
    TENMutableSetAddObject(set, objectArray[index]);
    
    assert((index + 1) == TENMutableSetGetSize(set));
}

void TENMutableSetAllocateTest() {
    const int size = 9;
    TENObject *objectArray[size];
    
    TENMutableSet *set = TENObjectCreate(TENMutableSet);
    assert(0 == set->_capacity);
    assert(0 == set->_size);

//    uint64_t capacityArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    uint64_t capacityArray[9] = {20, 20, 20, 20, 20, 20, 20, 20, 20};
    
    for (int i = 0; i < size; i++) {
        TENObjectArrayItemCreateAndAddToSet(objectArray, i, set);
//        TENMutableSetObjectCreateAndAdd(i);
    }
    
//    TENMutableSetRemoveLastObject(set); // size 8
//    assert(16 == set->_capacity);
//
//    TENMutableSetRemoveLastObject(set); // size 7
//    assert(8 == set->_capacity);
//    
//    TENMutableSetRemoveLastObject(set); // size 6
//    assert(8 == set->_capacity);
//
//    TENMutableSetRemoveLastObject(set); // size 5
//    assert(8 == set->_capacity);
//    
//    TENMutableSetRemoveLastObject(set); // size 4
//    assert(8 == set->_capacity);
//    
//    TENMutableSetRemoveLastObject(set); // size 3
//    assert(4 == set->_capacity);
//    
//    TENMutableSetRemoveLastObject(set); // size 2
//    assert(4 == set->_capacity);
//    
//    TENMutableSetRemoveLastObject(set); // size 1
//    assert(2 == set->_capacity);
//    
//    TENMutableSetRemoveLastObject(set); // size 0
//    assert(1 == set->_capacity);
//    
//    TENObjectRelease(objArray[0]);
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
