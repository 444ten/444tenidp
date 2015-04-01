//
//  TENLinkedListTests.c
//  HomeworkC
//
//  Created by 444ten on 3/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>

#include "TENLinkedList.h"
#include "TENLinkedListTests.h"
#include "TENNode.h"
#include "TENObject.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENLinkedListAddNodeTest();

static
void TENLinkedListRemoveNodeTest();

#pragma mark -
#pragma mark Public Implementations

extern
void TENLinkedListPerformTests() {
    TENLinkedListAddNodeTest();
    TENLinkedListRemoveNodeTest();

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
    TENLinkedListAddStack(list, stack1);
    
    //          it count should equal 1
    assert(1 == TENLinkedListGetCount(list));
    
    //          it mutationCount should equal 1
    assert(1 == TENLinkedListGetMutationCount(list));
    
    //          it rootNode->stack should equal stack1
    assert(stack1 == TENNodeGetStack(TENLinkedListGetRootNode(list)));
    
    //              after add (TENObject *)stack2
    TENObject *stack2 = TENObjectCreate(TENObject);
    TENLinkedListAddStack(list, stack2);

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
        TENLinkedListAddStack(list, stackArray[i]);
    }
    
    TENLinkedListRemoveFirstStack(list);

    assert((count - 1) == TENLinkedListGetCount(list));
    
    assert((count + 1) == TENLinkedListGetMutationCount(list));
    
    assert(stackArray[3] == TENNodeGetStack(TENLinkedListGetRootNode(list)));
    
    TENNode *nextNode = TENNodeGetNextNode(TENLinkedListGetRootNode(list));
    assert(stackArray[2] == TENNodeGetStack(nextNode));
    
    TENLinkedListRemoveAllStacks(list);

    assert(0 == TENLinkedListGetCount(list));
    
    assert(NULL == TENLinkedListGetRootNode(list));
    
    for (int i = 0; i < count; i++) {
        TENObjectRelease(stackArray[i]);
    }

    TENObjectRelease(list);
}

