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
typedef struct TENLinkedListEnumerator TENLinkedListEnumerator;
typedef struct TENNode TENNode;

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
void *TENLinkedListEnumeratorNextObject(TENLinkedListEnumerator *enumerator);

extern
bool TENLinkedListEnumeratorIsValid(TENLinkedListEnumerator *enumerator);

#endif /* defined(__HomeworkC__TENLinkedListEnumerator__) */
