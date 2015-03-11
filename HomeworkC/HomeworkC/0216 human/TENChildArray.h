//
//  TENChildArray.h
//  HomeworkC
//
//  Created by 444ten on 3/2/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENChildArray__
#define __HomeworkC__TENChildArray__

#include <stdio.h>
#include <stdlib.h>

#include "TENObject.h"

typedef struct TENHuman TENHuman;

typedef struct TENChildArray TENChildArray;
struct TENChildArray {
    TENObject _object;
    TENHuman **_array;
    uint8_t _childrenCount;
    uint8_t _size;
};

extern
void __TENChildArrayDeallocate(TENChildArray *childArray);

extern
uint8_t TENChildArrayGetChildrenCount(TENChildArray *childArray);

extern
void TENChildArrayAddObject(TENChildArray *childArray, TENHuman *object);

extern
uint8_t TENChildArrayIndexOfObject(TENChildArray *childArray, TENHuman *object);

extern
void TENChildArrayRemoveObjectAtIndex(TENChildArray *childArray, uint8_t index);

extern
void TENChildArrayPrint(TENChildArray *childArray);

#endif /* defined(__HomeworkC__TENChildArray__) */
