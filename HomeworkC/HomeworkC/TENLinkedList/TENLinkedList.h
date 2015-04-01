//
//  TENLinkedList.h
//  HomeworkC
//
//  Created by 444ten on 3/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENLinkedList__
#define __HomeworkC__TENLinkedList__

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
void TENLinkedListAddStack(TENLinkedList *list, void *stack);

extern
void TENLinkedListRemoveStack(TENLinkedList *list, void *stack);

extern
void TENLinkedListRemoveFirstStack(TENLinkedList *list);

extern
void TENLinkedListRemoveAllStacks(TENLinkedList *list);

extern
void TENLinkedListSetRootNode(TENLinkedList *list, void *rootNode);

extern
TENNode *TENLinkedListGetRootNode(TENLinkedList *list);

extern
uint64_t TENLinkedListGetCount(TENLinkedList *list);

extern
uint64_t TENLinkedListGetMutationCount(TENLinkedList *list);

#endif /* defined(__HomeworkC__TENLinkedList__) */
