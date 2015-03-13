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

void TENPropertyHolderSetTargetRetain(void **holder, void *target) {
    if (*holder != target) {
        if (NULL != *holder) {
            TENObjectRelease(*holder);
        }
        
        *holder = target;
        
        if (NULL != *holder) {
            TENObjectRetain(*holder);
        }
    }
}

void TENPropertyHolderSetTargetAssign(void **holder, void *target) {
    *holder = target;
}

bool TENPropertyIsNullOrIsTarget(void *property, void *target) {
    return (NULL == property || property == target);
}
