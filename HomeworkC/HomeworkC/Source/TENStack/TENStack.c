//
//  TENStack.c
//  HomeworkC
//
//  Created by 444ten on 3/25/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>

#include "TENStack.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENStackSetCount(TENStack *stack, uint64_t count);

static
uint64_t TENStackGetCount(TENStack *stack);

static
void TENStackSetCapacity(TENStack *stack, uint64_t capacity);

static
uint64_t TENStackGetCapacity(TENStack *stack);

static
void TENStackPopAllObjects(TENStack *stack);

#pragma mark -
#pragma mark Public Implementations

TENStack *TENStackCreateWithCapacity(uint64_t capacity) {
    assert(0 != capacity);
    
    TENStack *stack = TENObjectCreate(TENStack);
    TENStackSetCapacity(stack, capacity);
    
    return stack;
}

void __TENStackDeallocate(TENStack *stack) {
    TENStackPopAllObjects(stack);

    TENStackSetCapacity(stack, 0);
    
    __TENObjectDeallocate(stack);
}

bool TENStackIsEmpty(TENStack *stack) {
    return 0 == TENStackGetCount(stack);
}

bool TENStackIsFull(TENStack *stack) {
    return TENStackGetCapacity(stack) == TENStackGetCount(stack);
}

void TENStackPushObject(TENStack *stack, void *object) {
    assert(!TENStackIsFull(stack));
    
    uint64_t index = TENStackGetCount(stack);
    
    stack->_data[index] = object;
    
    TENStackSetCount(stack, index + 1);
}

TENStackPopType TENStackPopObject(TENStack *stack) {
    assert(!TENStackIsEmpty(stack));
    
    uint64_t index = TENStackGetCount(stack) - 1;
    
    TENStackSetCount(stack, index);
    
    if (NULL != stack->_data[index]) {
        TENRelease(stack->_data[index]);
        stack->_data[index] = NULL;
        
        return TENStackPopTypeObject;
    }
    
    return TENStackPopTypeNull;
}

TENStackPopType TENStackPopObjects(TENStack *stack) {
    while (TENStackPopTypeObject == TENStackPopObject(stack)) {
        if (TENStackIsEmpty(stack)) {
            return TENStackPopTypeObject;
        }
    }
    
    return TENStackPopTypeNull;
}

#pragma mark -
#pragma mark Private Implementations

void TENStackSetCount(TENStack *stack, uint64_t count) {
    if (NULL == stack) {
        return;
    }
    
    stack->_count = count;
}

uint64_t TENStackGetCount(TENStack *stack) {
    return (NULL == stack) ? 0 : stack->_count;
}

void TENStackSetCapacity(TENStack *stack, uint64_t capacity) {
    if (NULL == stack) {
        return;
    }
    
    if (stack->_capacity != capacity) {
        if (NULL != stack->_data) {
            free(stack->_data);
            stack->_data = NULL;
        }
        
        stack->_capacity = capacity;
        
        if (0 != stack->_capacity) {
            stack->_data = calloc(stack->_capacity, sizeof(*stack->_data));
        }
    }
}

uint64_t TENStackGetCapacity(TENStack *stack) {
    return (NULL == stack) ? 0 : stack->_capacity;
}

void TENStackPopAllObjects(TENStack *stack) {
    while (!TENStackIsEmpty(stack)) {
        TENStackPopObjects(stack);
    }
}
