//
//  TENNodeTests.c
//  HomeworkC
//
//  Created by 444ten on 3/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include "TENNodeTests.h"

#include "TENNode.h"

#include <assert.h>
#include <stdlib.h>

#include "TENStack.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

void TENNodePerformTests() {
    //TENNode
    //  after being created
    TENNode *node = TENObjectCreate(TENNode);
    
    //      next node should equal NULL
    assert(NULL == TENNodeGetNextNode(node));
    
    //      object should equal NULL
    assert(NULL == TENNodeGetStack(node));
    
    //          after setting object = (IDPObject *)object
    TENObject *object = TENObjectCreate(TENObject);
    TENNodeSetStack(node, object);
    
    //              object should equal value
    assert(TENNodeGetStack(node) == object);
    
    //              value retain count should equal 2
    assert(TENObjectGetReferenceCount(object) == 2);
    
    //                  after setting object to NULL
    TENNodeSetStack(node, NULL);
    
    //                      object should equal NULL
    assert(TENNodeGetStack(node) == NULL);
    
    //                      value retain count should equal 1
    assert(TENObjectGetReferenceCount(object) == 1);
    
    TENObjectRelease(object);
    
    //          after setting next node = (IDPLinkedListNode *)nextNode
    TENNode *nextNode = TENObjectCreate(TENNode);
    TENNodeSetNextNode(node, nextNode);
    
    //              nextNode retain count should equal 2
    assert(TENObjectGetReferenceCount(nextNode) == 2);
    
    //              next node should equal nextNode
    assert(TENNodeGetNextNode(node) == nextNode);
    
    //                  after setting next node to NULL
    TENNodeSetNextNode(node, NULL);
    
    //                      nextNode retain count should equal 1
    assert(TENObjectGetReferenceCount(nextNode) == 1);
    
    //                      next node should equal NULL
    assert(TENNodeGetNextNode(node) == NULL);
    
    TENObjectRelease(nextNode);
    
    TENObjectRelease(node);
}

#pragma mark -
#pragma mark Private Implementations
