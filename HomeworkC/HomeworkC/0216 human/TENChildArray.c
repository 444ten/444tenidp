//
//  TENChildArray.c
//  HomeworkC
//
//  Created by 444ten on 3/2/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include "TENChildArray.h"

const int8_t invalidIndex = 255;
const int8_t defaultSize = 5;

#pragma mark -
#pragma mark Public Implementations

void __TENChildArrayDeallocate(TENChildArray *childArray) {
    for (int i = 0; i < childArray->_childrenCount; i++) {
        free(childArray->_array[i]);
        childArray->_array[i] = NULL;
    }
    
    __TENObjectDeallocate(childArray);
}

void TENChildArrayAlloc(TENChildArray *childArray) {
    if (defaultSize != childArray->_size) {
        childArray->_size = defaultSize;
        childArray->_array = calloc(childArray->_size, sizeof(*childArray->_array));        
    }
}

void TENChildArrayAddObject(TENChildArray *childArray, TENHuman *object) {
    TENChildArrayAlloc(childArray);
    childArray->_array[childArray->_childrenCount] = object;
    childArray->_childrenCount += 1;
    TENObjectRetain(object);
}

uint8_t TENChildArrayIndexOfObject(TENChildArray *childArray, TENHuman *object) {
    uint8_t indexObject = 0;
    
    for (; childArray->_array[indexObject] != object; indexObject++) {
        if (indexObject >= childArray->_childrenCount) {
            return invalidIndex;
        }
    }
    
    return indexObject;
}

void TENChildArrayRemoveObjectAtIndex(TENChildArray *childArray, uint8_t index) {
#warning why not work with invalidIndex
    if (255 != index) {
        childArray->_childrenCount -= 1;
        TENObjectRelease(childArray->_array[index]);
        
        for (; index < childArray->_childrenCount; index++) {
            childArray->_array[index] = childArray->_array[index + 1];
        }
        
        childArray->_array[childArray->_childrenCount] = NULL;
        TENChildArrayAlloc(childArray);
    }
}
