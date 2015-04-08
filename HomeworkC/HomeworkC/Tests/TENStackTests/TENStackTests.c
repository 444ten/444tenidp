//
//  TENStackTests.c
//  HomeworkC
//
//  Created by 444ten on 3/25/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>

#include "TENStack.h"
#include "TENStackTests.h"

static const uint64_t TENStackCapacity = 16;

#pragma mark -
#pragma mark Private Declarations

static
void TENStackCreateTest();

static
void TENStackOneObjectPushAndPopTest();

static
void TENStackSixteenObjectsPushAndPopTest();

static
void TENStackNULLAndFifteenObjectsPushAndPopTest();

static
void TENStackSixteenNULLObjectsPushAndPopTest();

#pragma mark -
#pragma mark Public Implementations

void TENStackPerformTest() {
    TENStackCreateTest();
    TENStackOneObjectPushAndPopTest();
    TENStackSixteenObjectsPushAndPopTest();
    TENStackNULLAndFifteenObjectsPushAndPopTest();
    TENStackSixteenNULLObjectsPushAndPopTest();

}

#pragma mark -
#pragma mark Private Implementations

void TENStackCreateTest() {
    //TENStack
    //  after being created
    TENStack *stack = TENStackCreateWithCapacity(TENStackCapacity);
    
    //      it retain count should equal 1
    assert(1 == TENObjectGetReferenceCount(stack));
    
    //      it is empty
    assert(TENStackIsEmpty(stack));
    
    TENRelease(stack);
}

void TENStackOneObjectPushAndPopTest() {
    //TENStack
    //  after being created
    TENStack *stack = TENStackCreateWithCapacity(TENStackCapacity);
    TENObject *object = TENRetain(TENObjectCreate(TENObject));
    
    //      after pushing 1 object
    TENStackPushObject(stack, object);
    
    //          objects reference count shouldn't change
    assert(TENObjectGetReferenceCount(object) == 2);
    
    //          stack shouldn't be empty
    assert(!TENStackIsEmpty(stack));
    
    //              after popping 1 object
    TENStackPopType popType = TENStackPopObject(stack);
    
    //                  objects reference count should decrement
    assert(TENObjectGetReferenceCount(object) == 1);
    
    //                  stack should be empty
    assert(TENStackIsEmpty(stack));
    
    //                  stack pop type should equal IDPAutoreleasingStackObjectPop
    assert(TENStackPopTypeObject == popType);
    
    TENRelease(object);
    TENRelease(stack);
}

void TENStackSixteenObjectsPushAndPopTest() {
    //TENStack
    //  after being created for 16 objects
    TENStack *stack = TENStackCreateWithCapacity(TENStackCapacity);
    TENObject *object = TENObjectCreate(TENObject);
    
    //      after pushing 1 object 16 times
    for (uint8_t retainCount = 0; retainCount < 16; retainCount++) {
        TENRetain(object);
        
        //          objects reference count shouldn't change
        assert(TENObjectGetReferenceCount(object) == (retainCount + 2));
        TENStackPushObject(stack, object);
    }
    
    //          stack should be full
    assert(TENStackIsFull(stack));
    
    //          stack shouldn't be empty
    assert(!TENStackIsEmpty(stack));
    
    //              after popping all objects
    TENStackPopType popType = TENStackPopObjects(stack);
    
    //                  stack should return TENStackPopTypeObject
    assert(TENStackPopTypeObject == popType);
    
    //                  objects reference count should decrement by 16
    assert(TENObjectGetReferenceCount(object) == 1);
    
    //          stack shouldn't be full
    assert(!TENStackIsFull(stack));
    
    //          stack should be empty
    assert(TENStackIsEmpty(stack));
    
    TENRelease(object);
    TENRelease(stack);
}

void TENStackNULLAndFifteenObjectsPushAndPopTest() {
    //TENStack
    //  after being created for 16 objects
    TENStack *stack = TENStackCreateWithCapacity(TENStackCapacity);
    TENObject *object = TENObjectCreate(TENObject);
    
    //      after pushing 1 null once and one object 15 times
    TENStackPushObject(stack, NULL);
    for (uint8_t retainCount = 0; retainCount < 15; retainCount++) {
        TENRetain(object);
        
        //          objects reference count shouldn't change
        assert(TENObjectGetReferenceCount(object) == (retainCount + 2));
        TENStackPushObject(stack, object);
    }
    
    //          stack should be full
    assert(TENStackIsFull(stack));
    
    //          stack shouldn't be empty
    assert(!TENStackIsEmpty(stack));
    
    //              after popping all objects
    TENStackPopType popType = TENStackPopObjects(stack);
    
    //                  stack should return TENStackPopTypeNull
    assert(TENStackPopTypeNull == popType);
    
    //                  objects reference count should decrement by 15
    assert(TENObjectGetReferenceCount(object) == 1);
    
    //          stack should be empty
    assert(TENStackIsEmpty(stack));
    
    TENRelease(object);
    TENRelease(stack);
}

void TENStackSixteenNULLObjectsPushAndPopTest() {
    //TENStack
    //  after being created for 16 objects
    TENStack *stack = TENStackCreateWithCapacity(TENStackCapacity);
    
    //      after pushing null 16 times
    for (uint8_t retainCount = 0; retainCount < 16; retainCount++) {
        TENStackPushObject(stack, NULL);
    }
    
    //          after popping all objects 16 times
    uint8_t count = 0;
    while (TENStackPopTypeNull == TENStackPopObjects(stack)) {
        count++;
        if (TENStackIsEmpty(stack)) {
            break;
        }
    }
    
    //              stack should return TENStackPopTypeNull 16 times
    assert(16 == count);
    
    TENRelease(stack);
}
