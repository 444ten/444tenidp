//
//  TENAutoreleasePool.c
//  HomeworkC
//
//  Created by 444ten on 4/6/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>

#include "TENAutoreleasePool.h"
#include "TENLinkedList.h"
#include "TENObject.h"
#include "TENProperty.h"
#include "TENStack.h"

static
const uint64_t TENStackCapacity = 16;

#pragma mark -
#pragma mark Private Declarations

static
void __TENAutoreleasePoolDeallocate(TENAutoreleasePool *pool);

static
void TENSetAutoreleasePool(TENAutoreleasePool *pool);

static
void *TENGetAutoreleasePool();

static
void TENAutoreleasePoolSetList(TENAutoreleasePool *pool, void *list);

static
void *TENAutoreleasePoolGetList(TENAutoreleasePool *pool);

static
void TENAutoreleasePoolSetCurrentStack(TENAutoreleasePool *pool, void *stack);

static
void *TENAutoreleasePoolGetCurrentStack(TENAutoreleasePool *pool);

static
void TENAutoreleasePoolInsertObject(TENAutoreleasePool *pool, void *object);

#pragma mark -
#pragma mark Public Implementations

static void *__TENAutoreleasePool = NULL;

void *TENAutoreleasePoolNew() {
    TENAutoreleasePool *pool = TENGetAutoreleasePool();
    
    if (NULL == pool) {
        pool = calloc(1, sizeof(*pool));
        TENSetAutoreleasePool(pool);
        
        TENLinkedList *list = TENObjectCreate(TENLinkedList);
        TENAutoreleasePoolSetList(pool, list);
        TENObjectRelease(list);
    }
    
    TENAutoreleasePoolInsertObject(pool, NULL);
    
    return __TENAutoreleasePool;
}

void TENAutoreleasePoolAddObject(TENAutoreleasePool *pool, void *object) {
    assert(NULL != object);
    
    if (NULL == pool) {
        return;
    }
    
    TENAutoreleasePoolInsertObject(pool, object);
}

extern
void TENAutoreleasePoolDrain(TENAutoreleasePool *pool);

#pragma mark -
#pragma mark Private Implementations

void __TENAutoreleasePoolDeallocate(TENAutoreleasePool *pool) {
    TENAutoreleasePoolSetList(pool, NULL);
    TENAutoreleasePoolSetCurrentStack(pool, NULL);
    
    if (NULL != pool) {
        free(pool);
        TENSetAutoreleasePool(NULL);
    }
}

void TENSetAutoreleasePool(TENAutoreleasePool *pool) {
    __TENAutoreleasePool = pool;
}

void *TENGetAutoreleasePool() {
    return  __TENAutoreleasePool;
}

void TENAutoreleasePoolSetList(TENAutoreleasePool *pool, void *list) {
    if (NULL == pool) {
        return;
    }
    
    TENPropertyHolderSetTargetRetain((void **)&pool->_list, list);
}

void *TENAutoreleasePoolGetList(TENAutoreleasePool *pool) {
    return (NULL == pool) ? NULL : pool->_list;
}

void TENAutoreleasePoolSetCurrentStack(TENAutoreleasePool *pool, void *stack) {
    if (NULL == pool) {
        return;
    }
    
    TENPropertyHolderSetTargetRetain((void **)&pool->_currentStack, stack);
}

void *TENAutoreleasePoolGetCurrentStack(TENAutoreleasePool *pool) {
    return (NULL == pool) ? NULL : pool->_currentStack;
}

void TENAutoreleasePoolInsertObject(TENAutoreleasePool *pool, void *object) {
    if (NULL == pool) {
        return;
    }
    
    TENLinkedList *list = TENAutoreleasePoolGetList(pool);
    TENStack *currentStack = TENAutoreleasePoolGetCurrentStack(pool);
    
    if (NULL == currentStack || TENStackIsFull(currentStack)) {
        currentStack = TENStackCreateWithCapacity(TENStackCapacity);
        TENAutoreleasePoolSetCurrentStack(pool, currentStack);
        
        TENLinkedListAddObject(list, currentStack);
        
        pool->_stackCount += 1;
        TENObjectRelease(currentStack);

    }
    
    TENStackPushObject(currentStack, object);
}
