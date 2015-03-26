//
//  TENNode.h
//  HomeworkC
//
//  Created by 444ten on 3/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENNode__
#define __HomeworkC__TENNode__

#include "TENObject.h"

typedef struct TENNode TENNode;
struct TENNode {
    TENObject _super;
    
    TENNode *_nextNode;
    void *_stack;
};

extern
void __TENNodeDeallocate(TENNode *node);

extern
void TENNodeSetNextNode(TENNode *node, TENNode* nextNode);

extern
TENNode *TENNodeGetNextNode(TENNode *node);

extern
void TENNodeSetStack(TENNode *node, TENObject *stack);

extern
void *TENNodeGetStack(TENNode *node);

#endif /* defined(__HomeworkC__TENNode__) */
