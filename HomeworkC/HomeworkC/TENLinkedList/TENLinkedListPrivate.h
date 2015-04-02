//
//  TENLinkedListPrivate.h
//  HomeworkC
//
//  Created by 444ten on 3/31/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef HomeworkC_TENLinkedListPrivate_h
#define HomeworkC_TENLinkedListPrivate_h

#include <stdbool.h>

typedef struct TENLinkedList TENLinkedList;
typedef struct TENNode TENNode;
typedef struct TENNodeContext TENNodeContext;

typedef bool(*TENCompareFunction)(void *object, void *context);

#pragma mark -
#pragma mark Private Declarations

TENNode *TENLinkedListFindNode(TENLinkedList *list, TENCompareFunction function, void *context);

extern
TENNodeContext TENLinkedListGetContextForObject(TENLinkedList *list, void *object);

extern
void TENLinkedListMutate(TENLinkedList *list);

struct TENNodeContext {
    void *object;
    void *node;
    void *previousNode;
};

extern
bool TENNodeContainsObject(void *node, void *nodeContext);

#endif
