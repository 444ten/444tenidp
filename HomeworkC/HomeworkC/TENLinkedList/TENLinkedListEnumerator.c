//
//  TENLinkedListEnumerator.c
//  HomeworkC
//
//  Created by 444ten on 4/1/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>

#include "TENLinkedList.h"
#include "TENLinkedListEnumerator.h"
#include "TENLinkedListEnumeratorPrivate.h"
#include "TENNode.h"
#include "TENProperty.h"

#pragma mark -
#pragma mark Public Implementations

TENLinkedListEnumerator *TENLinkedListEnumeratorCreateWithList(TENLinkedList *list) {
    if (NULL == list) {
        return NULL;
    }
    
    TENLinkedListEnumerator *enumerator = TENObjectCreate(TENLinkedListEnumerator);
    
    TENLinkedListEnumeratorSetList(enumerator, list);
    TENLinkedListEnumeratorSetMutationCount(enumerator, TENLinkedListGetMutationCount(list));
    TENLinkedListEnumeratorSetValid(enumerator, true);
    
    return enumerator;
}

void __TENLinkedListEnumeratorDeallocate(TENLinkedListEnumerator *enumerator) {
    TENLinkedListEnumeratorSetList(enumerator, NULL);
    TENLinkedListEnumeratorSetNode(enumerator, NULL);
    
    __TENObjectDeallocate(enumerator);
}

void *TENLinkedListEnumeratorNextObject(TENLinkedListEnumerator *enumerator) {
    return TENNodeGetStack(TENLinkedListEnumeratorNextNode(enumerator));
}

bool TENLinkedListEnumeratorIsValid(TENLinkedListEnumerator *enumerator) {
    return (NULL != enumerator) && enumerator->_isValid;
}

#pragma mark -
#pragma mark Private Implementations

TENNode *TENLinkedListEnumeratorNextNode(TENLinkedListEnumerator *enumerator) {
    TENLinkedListEnumeratorCheckMutations(enumerator);
    
    if (!TENLinkedListEnumeratorIsValid(enumerator)) {
        return NULL;
    }
    
    TENNode *node = TENLinkedListEnumeratorGetNode(enumerator);
    if (NULL == node) {
        TENLinkedList *list = TENLinkedListEnumeratorGetList(enumerator);
        node = TENLinkedListGetRootNode(list);
        TENLinkedListEnumeratorSetNode(enumerator, node);
    }
        
    TENNode *nextNode = TENNodeGetNextNode(node);
    if (nextNode == NULL) {
        TENLinkedListEnumeratorSetValid(enumerator, false);
    }
    
    TENLinkedListEnumeratorSetNode(enumerator, nextNode);
    
    return node;
}

void TENLinkedListEnumeratorSetList(TENLinkedListEnumerator *enumerator, TENLinkedList *list) {
    if (NULL == enumerator) {
        return;
    }

    TENPropertyHolderSetTargetRetain((void **)&enumerator->_list, list);
}

TENLinkedList *TENLinkedListEnumeratorGetList(TENLinkedListEnumerator *enumerator) {
    return (NULL == enumerator) ? NULL : enumerator->_list;
}

void TENLinkedListEnumeratorSetNode(TENLinkedListEnumerator *enumerator, TENNode *node) {
    if (NULL == enumerator) {
        return;
    }
    
    TENPropertyHolderSetTargetRetain((void **)&enumerator->_node, node);
}

TENNode *TENLinkedListEnumeratorGetNode(TENLinkedListEnumerator *enumerator) {
    return (NULL == enumerator) ? NULL : enumerator->_node;
}

void TENLinkedListEnumeratorSetMutationCount(TENLinkedListEnumerator *enumerator, uint64_t mutationCount) {
    if (NULL == enumerator) {
        return;
    }
    
    enumerator->_mutationCount = mutationCount;
}

uint64_t TENLinkedListEnumeratorGetMutationCount(TENLinkedListEnumerator *enumerator) {
    return (NULL == enumerator) ? 0 : enumerator->_mutationCount;
}

void TENLinkedListEnumeratorSetValid(TENLinkedListEnumerator *enumerator, bool valid) {
    if (NULL == enumerator) {
        return;
    }
    
    enumerator->_isValid = valid;
}

void TENLinkedListEnumeratorCheckMutations(TENLinkedListEnumerator *enumerator) {
    uint64_t count = TENLinkedListGetMutationCount(TENLinkedListEnumeratorGetList(enumerator));
    
    assert(count == TENLinkedListEnumeratorGetMutationCount(enumerator));
}
