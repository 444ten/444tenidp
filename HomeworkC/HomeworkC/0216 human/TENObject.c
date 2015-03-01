//
//  TENObject.c
//  HomeworkC
//
//  Created by 444ten on 2/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdlib.h>
#include "TENObject.h"

void *__TENObjectCreate(size_t objectSize, TENDeallocateCallBack deallocateCallback) {
    TENObject *object = calloc(1, objectSize);
    
    object->_refernceCount = 1;
    object->_deallocateCallBack = deallocateCallback;
    
    return object;
}

void *TENObjectRetain(void *object) {
    if (NULL != object) {
        ((TENObject *)object)->_refernceCount += 1;
    }
    
    return object;
}

void TENObjectRelease(void *voidObject) {
    if (NULL != voidObject) {
        TENObject *object = (TENObject *)voidObject;
        
        object->_refernceCount -= 1;
        if (0 == object->_refernceCount) {
            object->_deallocateCallBack(object);
        }
    }
}

uint64_t TENObjectGetReferenceCount(void *object) {
    return (NULL == object) ? 0 : ((TENObject *)object)->_refernceCount;
}

void __TENObjectDeallocate(void *object) {
    free(object);
}
