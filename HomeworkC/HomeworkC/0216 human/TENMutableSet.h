//
//  TENMutableSet.h
//  HomeworkC
//
//  Created by 444ten on 3/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENMutableSet__
#define __HomeworkC__TENMutableSet__

#include <stdbool.h>
#include <stdio.h>

#include "TENObject.h"

extern
const uint64_t TENIndexNotFound;

struct TENMutableSet {
    TENObject _object;
    TENObject **_array;
    uint64_t _count;
    uint64_t _capacity;
};
typedef struct TENMutableSet TENMutableSet;

extern
void __TENMutableSetDeallocate(TENMutableSet *set);

extern
TENObject *TENMutableSetGetObjectAtIndex(TENMutableSet *set, uint64_t index);

extern
void TENMutableSetAddObject(TENMutableSet *set, TENObject *object);

extern
uint64_t TENMutableSetIndexOfObject(TENMutableSet *set, TENObject *object);

extern
bool TENMutableSetContainsObject(TENMutableSet *set, TENObject *object);

extern
uint64_t TENMutableSetGetCount(TENMutableSet *set);

extern
void TENMutableSetRemoveObjectAtIndex(TENMutableSet *set, uint64_t index);

extern
void TENMutableSetRemoveLastObject(TENMutableSet *set);

extern
void TENMutableSetRemoveObject(TENMutableSet *set, TENObject *object);

extern
void TENMutableSetRemoveAllObjects(TENMutableSet *set);

#endif /* defined(__HomeworkC__TENMutableSet__) */
