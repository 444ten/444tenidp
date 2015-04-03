//
//  TENNode.c
//  HomeworkC
//
//  Created by 444ten on 3/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>

#include "TENNode.h"
#include "TENProperty.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

void __TENNodeDeallocate(TENNode *node) {
    TENNodeSetNextNode(node, NULL);
    TENNodeSetStack(node, NULL);
    
    __TENObjectDeallocate(node);
}

void TENNodeSetNextNode(TENNode *node, TENNode* nextNode) {
    assert(NULL != node);
    assert(node != nextNode);
    
    TENPropertyHolderSetTargetRetain((void **)&node->_nextNode, nextNode);
}

TENNode *TENNodeGetNextNode(TENNode *node) {
    return (NULL != node) ? node->_nextNode : NULL;
}

void TENNodeSetStack(TENNode *node, TENObject *stack) {
    assert(NULL != node);
    
    TENPropertyHolderSetTargetRetain((void **)&node->_stack, stack);
}

void *TENNodeGetStack(TENNode *node) {
    assert(NULL != node);

    return node->_stack;
}

#pragma mark -
#pragma mark Private Implementations
