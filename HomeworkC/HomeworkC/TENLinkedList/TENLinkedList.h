//
//  TENLinkedList.h
//  HomeworkC
//
//  Created by 444ten on 3/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENLinkedList__
#define __HomeworkC__TENLinkedList__

#include <stdbool.h>

#include "TENNode.h"
#include "TENObject.h"

typedef struct TENLinkedList TENLinkedList;
struct TENLinkedList {
    TENObject _super;
    
    TENNode *_rootNode;
    
    uint64_t _count;
    uint64_t _mutationCount;
};

extern
void __TENLinkedListDeallocate(TENLinkedList *list);

extern
void TENLinkedListAddObject(TENLinkedList *list, void *object);

extern
void TENLinkedListRemoveObject(TENLinkedList *list, void *object);

extern
void TENLinkedListRemoveFirstObject(TENLinkedList *list);

extern
void TENLinkedListRemoveAllObjects(TENLinkedList *list);

extern
bool TENLinkedListContainsObject(TENLinkedList *list, void *object);

extern
bool TENLinkedListInsertObjectBeforeObject(TENLinkedList *list, void *object, void *insertionPoint);

extern
bool TENLinkedListInsertObjectAfterObject(TENLinkedList *list, void *object, void *insertionPoint);

extern
void TENLinkedListSetRootNode(TENLinkedList *list, void *rootNode);

extern
TENNode *TENLinkedListGetRootNode(TENLinkedList *list);

extern
uint64_t TENLinkedListGetCount(TENLinkedList *list);

extern
uint64_t TENLinkedListGetMutationCount(TENLinkedList *list);

#endif /* defined(__HomeworkC__TENLinkedList__) */
