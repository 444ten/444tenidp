//
//  TENStack.h
//  HomeworkC
//
//  Created by 444ten on 3/25/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENStack__
#define __HomeworkC__TENStack__

#include <stdbool.h>

#include "TENObject.h"

typedef enum {
    TENStackPopTypeNull,
    TENStackPopTypeObject
}TENStackPopType;

typedef struct TENStack TENStack;
struct TENStack {
    TENObject _super;
    
    void **_data;
    uint64_t _count;
    uint64_t _capacity;
};

extern
TENStack *TENStackCreateWithCapacity(uint64_t capacity);

extern
void __TENStackDeallocate(TENStack *stack);

extern
bool TENStackIsEmpty(TENStack *stack);

extern
bool TENStackIsFull(TENStack *stack);

extern
void TENStackPushObject(TENStack *stack, void *object);

extern
TENStackPopType TENStackPopObject(TENStack *stack);

extern
TENStackPopType TENStackPopObjects(TENStack *stack);

#endif /* defined(__HomeworkC__TENStack__) */
