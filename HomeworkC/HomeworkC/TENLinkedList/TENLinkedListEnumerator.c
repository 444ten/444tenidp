//
//  TENLinkedListEnumerator.c
//  HomeworkC
//
//  Created by 444ten on 4/1/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>

#include "TENLinkedListEnumerator.h"

#include "TENLinkedList.h"
#include "TENNode.h"
#include "TENProperty.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

TENLinkedListEnumerator *TENLinkedListEnumeratorCreateWithList(TENLinkedList *list) {
    assert(NULL != list);
    
    TENLinkedListEnumerator *enumerator = TENObjectCreate(TENLinkedListEnumerator);
    
    TENLinkedListEnumeratorSetList(enumerator, list);
    TENLinkedListEnumeratorSetMutationCount(enumerator, TENLinkedListGetMutationCount(list));
    TENLinkedListEnumeratorSetValid(enumerator, true);
    
    return enumerator;
}

void __TENLinkedListEnumeratorDeallocate(TENLinkedListEnumerator *enumerator) {
    TENLinkedListEnumeratorSetList(enumerator, NULL);
    
    __TENObjectDeallocate(enumerator);
}

extern
TENNode *TENLinkedListEnumeratorNextStack(TENLinkedListEnumerator *enumerator);

bool TENLinkedListEnumeratorIsValid(TENLinkedListEnumerator *enumerator) {
    assert(NULL != enumerator);
    
    return enumerator->_isValid;
}

void TENLinkedListEnumeratorSetList(TENLinkedListEnumerator *enumerator, TENLinkedList *list) {
    assert(NULL != enumerator);
    
    TENPropertyHolderSetTargetRetain((void **)&enumerator->_list, list);
}

TENLinkedList *TENLinkedListEnumeratorGetList(TENLinkedListEnumerator *enumerator) {
    assert(NULL != enumerator);

    return enumerator->_list;
}

void TENLinkedListEnumeratorSetMutationCount(TENLinkedListEnumerator *enumerator, uint64_t mutationCount) {
    assert(NULL != enumerator);
    
    enumerator->_mutationCount = mutationCount;
}

uint64_t TENLinkedListEnumeratorGetMutationCount(TENLinkedListEnumerator *enumerator) {
    assert(NULL != enumerator);

    return enumerator->_mutationCount;
}

void TENLinkedListEnumeratorSetValid(TENLinkedListEnumerator *enumerator, bool valid) {
    assert(NULL != enumerator);

    enumerator->_isValid = valid;
}


#pragma mark -
#pragma mark Private Implementations
