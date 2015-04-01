//
//  TENLinkedListEnumerator.h
//  HomeworkC
//
//  Created by 444ten on 4/1/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENLinkedListEnumerator__
#define __HomeworkC__TENLinkedListEnumerator__

#include <stdbool.h>

#include "TENObject.h"

typedef struct TENLinkedList TENLinkedList;
typedef struct TENNode TENNode;

typedef struct TENLinkedListEnumerator TENLinkedListEnumerator;
struct TENLinkedListEnumerator {
    TENObject _super;
    
    TENLinkedList *_list;
    TENNode *_node;
    
    uint64_t _mutationCount;
    bool  _isValid;
};

extern
TENLinkedListEnumerator *TENLinkedListEnumeratorCreateWithList(TENLinkedList *list);

extern
void __TENLinkedListEnumeratorDeallocate(TENLinkedListEnumerator *enumerator);

extern
TENNode *TENLinkedListEnumeratorNextStack(TENLinkedListEnumerator *enumerator);

extern
bool TENLinkedListEnumeratorIsValid(TENLinkedListEnumerator *enumerator);

extern
void TENLinkedListEnumeratorSetList(TENLinkedListEnumerator *enumerator, TENLinkedList *list);

extern
TENLinkedList *TENLinkedListEnumeratorGetList(TENLinkedListEnumerator *enumerator);

extern
void TENLinkedListEnumeratorSetMutationCount(TENLinkedListEnumerator *enumerator, uint64_t mutationCount);

extern
uint64_t TENLinkedListEnumeratorGetMutationCount(TENLinkedListEnumerator *enumerator);

extern
void TENLinkedListEnumeratorSetValid(TENLinkedListEnumerator *enumerator, bool valid);

#endif /* defined(__HomeworkC__TENLinkedListEnumerator__) */
