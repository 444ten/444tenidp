//
//  TENMutableSet.h
//  HomeworkC
//
//  Created by 444ten on 3/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENMutableSet__
#define __HomeworkC__TENMutableSet__

#include <stdio.h>

#include "TENObject.h"

static const uint64_t TENIndexNotFound = UINT64_MAX;

struct TENMutableSet {
    TENObject _object;
    void **_array;
    uint64_t _size;
    uint64_t _capacity;
};
typedef struct TENMutableSet TENMutableSet;

extern
void __TENMutableSetDeallocate(TENMutableSet *set);

extern
void TENMutableSetAddObject(TENMutableSet *set, void *object);

extern
uint64_t TENMutableSetIndexOfObject(TENMutableSet *set, TENObject *object);

extern
uint64_t TENMutableSetGetSize(TENMutableSet *set);

extern
void TENMutableSetRemoveLastObject(TENMutableSet *set);

extern
void TENMutableSetRemoveObject(TENMutableSet *set, void *object);

extern
void TENMutableSetRemoveAllObjects(TENMutableSet *set);

#endif /* defined(__HomeworkC__TENMutableSet__) */
