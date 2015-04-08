//
//  TENObject.c
//  HomeworkC
//
//  Created by 444ten on 2/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdlib.h>
#include "TENObject.h"

void *__TENObjectCreate(size_t objectSize, TENDeallocateCallback deallocateCallback) {
    TENObject *object = calloc(1, objectSize);
    
    object->_referenceCount = 1;
    object->_deallocateCallback = deallocateCallback;
    
    return object;
}

void *TENRetain(void *object) {
    if (NULL != object) {
        ((TENObject *)object)->_referenceCount += 1;
    }
    
    return object;
}

void TENRelease(void *voidObject) {
    if (NULL != voidObject) {
        TENObject *object = (TENObject *)voidObject;
        
        object->_referenceCount -= 1;
        if (0 == object->_referenceCount) {
            object->_deallocateCallback(object);
        }
    }
}

uint64_t TENObjectGetReferenceCount(void *object) {
    return (NULL == object) ? 0 : ((TENObject *)object)->_referenceCount;
}

void __TENObjectDeallocate(void *object) {
    free(object);
}
