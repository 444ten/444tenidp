//
//  TENProperty.c
//  HomeworkC
//
//  Created by 444ten on 3/10/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include "TENProperty.h"
#include "TENObject.h"

#pragma mark -
#pragma mark Public Implementations

void __TENRetainingSetter(void *owner, void **dataRef, void *object) {
    if (NULL == owner) {
        return;
    }
    
    if (*dataRef != object) {
        if (NULL != object) {
            TENRetain(object);
        }
        
        if (NULL != *dataRef) {
            TENRelease(object);
        }
        
        *dataRef = object;
    }
}

void __TENAssigningSetter(void *owner, void **dataRef, void *object) {
    if (NULL == owner) {
        return;
    }

    *dataRef = object;
}

void TENPropertyHolderSetTargetRetain(void **holder, void *target) {
    if (*holder != target) {
        if (NULL != target) {
            TENRetain(target);
        }

        if (NULL != *holder) {
            TENRelease(*holder);
        }
        
        *holder = target;
    }
}

void TENPropertyHolderSetTargetAssign(void **holder, void *target) {
    *holder = target;
}

bool TENPropertyIsNullOrIsTarget(void *property, void *target) {
    return (NULL == property || property == target);
}
