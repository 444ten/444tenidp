//
//  TENAutoreleasePool.h
//  HomeworkC
//
//  Created by 444ten on 4/6/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENAutoreleasePool__
#define __HomeworkC__TENAutoreleasePool__

#include <stdlib.h>

static
const uint64_t TENStackCapacity       = 16;

typedef struct TENAutoreleasePool TENAutoreleasePool;
typedef struct TENLinkedList TENLinkedList;
typedef struct TENStack TENStack;

struct TENAutoreleasePool {
    TENLinkedList *_list;
    
    TENStack *_currentStack;
    
    uint64_t _stackCount;
};

extern
void *TENAutoreleasePoolNew();

extern
void *TENGetAutoreleasePool();

extern
void TENAutoreleasePoolAddObject(TENAutoreleasePool *pool, void *object);

extern
void TENAutoreleasePoolDrain(TENAutoreleasePool *pool);

#endif /* defined(__HomeworkC__TENAutoreleasePool__) */
