//
//  TENLinkedList.c
//  HomeworkC
//
//  Created by 444ten on 3/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>

#include "TENLinkedList.h"
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
    assert(NULL != list);
    
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

extern
void TENLinkedListRemoveObject(TENLinkedList *list, void *object);

void TENLinkedListRemoveFirstObject(TENLinkedList *list) {
    assert(NULL != list);

    TENLinkedListMutate(list);
    
    TENNode *newRootNode = TENNodeGetNextNode(TENLinkedListGetRootNode(list));
    
    TENLinkedListSetRootNode(list, newRootNode);
    
    list->_count -= 1;
}

void TENLinkedListRemoveAllObjects(TENLinkedList *list) {
    assert(NULL != list);
    
    while (TENLinkedListGetCount(list)) {
        TENLinkedListRemoveFirstObject(list);
    }
}

void TENLinkedListSetRootNode(TENLinkedList *list, void *rootNode) {
    assert(NULL != list);
    
    TENPropertyHolderSetTargetRetain((void **)&list->_rootNode, rootNode);
}

TENNode *TENLinkedListGetRootNode(TENLinkedList *list) {
    assert(NULL != list);
    
    return list->_rootNode;
}

uint64_t TENLinkedListGetCount(TENLinkedList *list) {
    assert(NULL != list);
    
    return list->_count;
}

extern
uint64_t TENLinkedListGetMutationCount(TENLinkedList *list) {
    assert(NULL != list);
    
    return list->_mutationCount;
}


#pragma mark -
#pragma mark Private Implementations

void TENLinkedListMutate(TENLinkedList *list) {
    assert(NULL != list);
    
    list->_mutationCount++;
}
