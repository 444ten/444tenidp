//
//  TENLinkedList.c
//  HomeworkC
//
//  Created by 444ten on 3/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>

#include "TENLinkedList.h"
#include "TENLinkedListEnumerator.h"
#include "TENLinkedListEnumeratorPrivate.h"
#include "TENLinkedListPrivate.h"
#include "TENNode.h"
#include "TENProperty.h"

#pragma mark -
#pragma mark Public Implementations

void __TENLinkedListDeallocate(TENLinkedList *list) {
    TENLinkedListRemoveAllObjects(list);
    
    __TENObjectDeallocate(list);
}

void TENLinkedListAddObject(TENLinkedList *list, void *object) {
    if (NULL == list) {
        return;
    }
    
    TENLinkedListMutate(list);
    
    TENNode *oldRootNode = TENLinkedListGetRootNode(list);
    
    TENNode *newRootNode = TENObjectCreate(TENNode);
    TENNodeSetStack(newRootNode, object);
    
    if (NULL != oldRootNode) {
        TENNodeSetNextNode(newRootNode, oldRootNode);
    }

    TENLinkedListSetRootNode(list, newRootNode);
    
    list->_count += 1;

    TENObjectRelease(newRootNode);
}

void TENLinkedListRemoveObject(TENLinkedList *list, void *object) {
    TENNodeContext context = TENLinkedListGetContextForObject(list, object);
    TENNode *node = context.node;
    
    if (NULL != node) {
        TENLinkedListMutate(list);
        
        if (node == TENLinkedListGetRootNode(list)) {
            TENLinkedListRemoveFirstObject(list);
        } else {
            TENNodeSetNextNode(context.previousNode, TENNodeGetNextNode(node));
            list->_count -= 1;
        }
    }
}

void TENLinkedListRemoveFirstObject(TENLinkedList *list) {
    if (NULL == list) {
        return;
    }

    TENLinkedListMutate(list);
    
    TENNode *newRootNode = TENNodeGetNextNode(TENLinkedListGetRootNode(list));
    
    TENLinkedListSetRootNode(list, newRootNode);
    
    list->_count -= 1;
}

void TENLinkedListRemoveAllObjects(TENLinkedList *list) {
    if (NULL == list) {
        return;
    }
    
    while (TENLinkedListGetCount(list)) {
        TENLinkedListRemoveFirstObject(list);
    }
}

void TENLinkedListSetRootNode(TENLinkedList *list, void *rootNode) {
    if (NULL == list) {
        return;
    }
    
    TENPropertyHolderSetTargetRetain((void **)&list->_rootNode, rootNode);
}

bool TENLinkedListContainsObject(TENLinkedList *list, void *object) {
    return NULL != TENLinkedListGetNodeForObject(list, object);
}

extern
bool TENLinkedListInsertObjectBeforeObject(TENLinkedList *list, void *object, void *insertionPoint);

extern
bool TENLinkedListInsertObjectAfterObject(TENLinkedList *list, void *object, void *insertionPoint);

TENNode *TENLinkedListGetRootNode(TENLinkedList *list) {
    return (NULL == list) ? NULL : list->_rootNode;
}

uint64_t TENLinkedListGetCount(TENLinkedList *list) {
    return (NULL == list) ? 0 : list->_count;
}

uint64_t TENLinkedListGetMutationCount(TENLinkedList *list) {
    return (NULL == list) ? 0 : list->_mutationCount;
}

#pragma mark -
#pragma mark Private Implementations

void TENLinkedListMutate(TENLinkedList *list) {
    if (NULL == list) {
        return;
    }
    
    list->_mutationCount++;
}

TENNode *TENLinkedListFindNode(TENLinkedList *list, TENCompareFunction function, void *context) {
    if (NULL == list) {
        return NULL;
    }
    
    TENLinkedListEnumerator *enumerator = TENLinkedListEnumeratorCreateWithList(list);
    TENNode *result = NULL;
    
    while ((result = TENLinkedListEnumeratorNextNode(enumerator))) {
        if (function(result, context)) {
            break;
        }
    }
    
    TENObjectRelease(enumerator);
    
    return result;
}

TENNodeContext TENLinkedListGetContextForObject(TENLinkedList *list, void *object) {
    TENNodeContext context;
    context.object = object;
    context.node = NULL;
    context.previousNode = NULL;
    
    TENNode *node = TENLinkedListFindNode(list, &TENNodeContainsObject, &context);
    
    if (NULL == node) {
        context.node = NULL;
        context.previousNode = NULL;
    }
    
    return context;
}

TENNode *TENLinkedListGetNodeForObject(TENLinkedList *list, void *object) {
    if (NULL == list) {
        return NULL;
    }
    
    TENNodeContext context = TENLinkedListGetContextForObject(list, object);
    
    return context.node;
}

bool TENNodeContainsObject(void *node, void *nodeContext) {
    TENNodeContext *context = nodeContext;
    
    context->previousNode = context->node;
    context->node = node;
    
    return TENNodeGetStack(node) == context->object;
}

