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

#pragma mark -
#pragma mark Public Implementations

void TENStackPerformTest() {
    TENStackCreateTest();
    TENStackOneObjectPushAndPopTest();

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
    
    TENObjectRelease(stack);
}

void TENStackOneObjectPushAndPopTest() {
    //TENStack
    //  after being created
    TENStack *stack = TENStackCreateWithCapacity(TENStackCapacity);
    TENObject *object = TENObjectRetain(TENObjectCreate(TENObject));
    
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
    
    TENObjectRelease(object);
    TENObjectRelease(stack);
}
