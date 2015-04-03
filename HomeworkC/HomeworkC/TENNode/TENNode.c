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
    assert(node != nextNode);

    if (NULL == node) {
        return;
    }
    
    TENPropertyHolderSetTargetRetain((void **)&node->_nextNode, nextNode);

}

TENNode *TENNodeGetNextNode(TENNode *node) {
    return (NULL == node) ? NULL : node->_nextNode;
}

void TENNodeSetStack(TENNode *node, TENObject *stack) {
    if (NULL == node) {
        return;
    }
    
    TENPropertyHolderSetTargetRetain((void **)&node->_stack, stack);
}

void *TENNodeGetStack(TENNode *node) {
    return (NULL == node) ? NULL : node->_stack;
}

#pragma mark -
#pragma mark Private Implementations
