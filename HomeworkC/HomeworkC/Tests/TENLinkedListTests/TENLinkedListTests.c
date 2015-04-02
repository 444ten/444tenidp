//
//  TENLinkedListTests.c
//  HomeworkC
//
//  Created by 444ten on 3/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>

#include "TENLinkedList.h"
#include "TENLinkedListEnumerator.h"
#include "TENLinkedListTests.h"
#include "TENNode.h"
#include "TENObject.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENLinkedListAddNodeTest();

static
void TENLinkedListRemoveNodeTest();

static
void TENLinkedListEnumeratorTest();

#pragma mark -
#pragma mark Public Implementations

extern
void TENLinkedListPerformTests() {
    TENLinkedListAddNodeTest();
    TENLinkedListRemoveNodeTest();
    TENLinkedListEnumeratorTest();

}

#pragma mark -
#pragma mark Private Implementations

static
void TENLinkedListAddNodeTest() {
    // TENLinkedList
    //  after being created
    TENLinkedList *list = TENObjectCreate(TENLinkedList);

    //      after add (TENObject *)stack1
    TENObject *stack1 = TENObjectCreate(TENObject);
    TENLinkedListAddObject(list, stack1);
    
    //          it count should equal 1
    assert(1 == TENLinkedListGetCount(list));
    
    //          it mutationCount should equal 1
    assert(1 == TENLinkedListGetMutationCount(list));
    
    //          it rootNode->stack should equal stack1
    assert(stack1 == TENNodeGetStack(TENLinkedListGetRootNode(list)));
    
    //              after add (TENObject *)stack2
    TENObject *stack2 = TENObjectCreate(TENObject);
    TENLinkedListAddObject(list, stack2);

    //                  it count should equal 2
    assert(2 == TENLinkedListGetCount(list));
    
    //                  it mutationCount should equal 2
    assert(2 == TENLinkedListGetMutationCount(list));
    
    //                  it rootNode->stack should equal stack2
    assert(stack2 == TENNodeGetStack(TENLinkedListGetRootNode(list)));
    
    //                  it nextNode->stack should equal stack1
    TENNode *nextNode = TENNodeGetNextNode(TENLinkedListGetRootNode(list));
    assert(stack1 == TENNodeGetStack(nextNode));

    TENObjectRelease(stack1);
    TENObjectRelease(stack2);
    TENObjectRelease(list);
}

void TENLinkedListRemoveNodeTest() {
    // TENLinkedList
    //  after being created and added five unique stacks
    //      after removeFirstNode
    //          it count should equal 2
    //          it mutationCount should equal 4
    //          it rootNode->stack should equal stack2
    //          it nextNode->stack should equal stack1
    //              after remove all stacks
    //                  it count should equal 0
    //                  it rootNode should equal NULL
    
    TENLinkedList *list = TENObjectCreate(TENLinkedList);
    
    const uint8_t count = 5;
    TENObject *stackArray[count];
    
    for (int i = 0; i < count; i++) {
        stackArray[i] = TENObjectCreate(TENObject);
        TENLinkedListAddObject(list, stackArray[i]);
    }
    
    TENLinkedListRemoveFirstObject(list);

    assert((count - 1) == TENLinkedListGetCount(list));
    
    assert((count + 1) == TENLinkedListGetMutationCount(list));
    
    assert(stackArray[3] == TENNodeGetStack(TENLinkedListGetRootNode(list)));
    
    TENNode *nextNode = TENNodeGetNextNode(TENLinkedListGetRootNode(list));
    assert(stackArray[2] == TENNodeGetStack(nextNode));
    
    TENLinkedListRemoveAllObjects(list);

    assert(0 == TENLinkedListGetCount(list));
    
    assert(NULL == TENLinkedListGetRootNode(list));
    
    for (int i = 0; i < count; i++) {
        TENObjectRelease(stackArray[i]);
    }

    TENObjectRelease(list);
}

void TENLinkedListEnumeratorTest() {

    //TENLinkedList
    //after being created and added three unique stacks
    TENLinkedList *list = TENObjectCreate(TENLinkedList);
    
    const uint8_t count = 3;
    TENObject *stackArray[count];
    
    for (int i = 0; i < count; i++) {
        stackArray[i] = TENObjectCreate(TENObject);
        TENLinkedListAddObject(list, stackArray[i]);
    }

    //after being created TENLinkedListEnumerator with list
    TENLinkedListEnumerator *enumerator = TENLinkedListEnumeratorCreateWithList(list);

    //enumerator should valid
    assert(TENLinkedListEnumeratorIsValid(enumerator));
    
    //nextObject should equal stackArray[2]
    assert(TENLinkedListEnumeratorNextObject(enumerator) == stackArray[2]);
    
    //nextObject should equal stackArray[1]
    assert(TENLinkedListEnumeratorNextObject(enumerator) == stackArray[1]);
    
    //enumerator should valid
    assert(TENLinkedListEnumeratorIsValid(enumerator));
    
    //after modifying list application should crash by assert
//    TENLinkedListRemoveFirstObject(list);

    //nextObject should equal stackArray[0]
    assert(TENLinkedListEnumeratorNextObject(enumerator) == stackArray[0]);

    //enumerator should not valid
    assert(!TENLinkedListEnumeratorIsValid(enumerator));

    //nextObject should equal NULL
    assert(TENLinkedListEnumeratorNextObject(enumerator) == NULL);
    
    TENObjectRelease(enumerator);
    
    for (int i = 0; i < count; i++) {
        TENObjectRelease(stackArray[i]);
    }
    
    TENObjectRelease(list);
}

