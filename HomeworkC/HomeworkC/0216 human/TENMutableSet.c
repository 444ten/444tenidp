//
//  TENMutableSet.c
//  HomeworkC
//
//  Created by 444ten on 3/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "TENMutableSet.h"
#include "TENProperty.h"

const uint64_t TENIndexNotFound = UINT64_MAX;

#pragma mark -
#pragma mark Private Declarations

static
void TENMutableSetSetObjectAtIndex(TENMutableSet *set, TENObject *object, uint64_t index);

static
void TENMutableSetSetCapacity(TENMutableSet *set, uint64_t capacity);

static
void TENMutableSetChangeCapacityIfNeeded(TENMutableSet *set);

static
uint64_t TENMutableSetRequiredCapacity(TENMutableSet *set);

#pragma mark -
#pragma mark Public Implementations

void __TENMutableSetDeallocate(TENMutableSet *set) {
    TENMutableSetRemoveAllObjects(set);
    
    __TENObjectDeallocate(set);
}

TENObject *TENMutableSetGetObjectAtIndex(TENMutableSet *set, uint64_t index) {
    return (NULL != set && index < set->_count) ? set->_array[index] : NULL;
}

void TENMutableSetAddObject(TENMutableSet *set, TENObject *object) {
    if (NULL != set &&
        NULL != object &&
        TENIndexNotFound == TENMutableSetIndexOfObject(set, object))
    {
        TENMutableSetChangeCapacityIfNeeded(set);
        TENMutableSetSetObjectAtIndex(set, object, set->_count);
        set->_count += 1;
    }
}

extern
uint64_t TENMutableSetIndexOfObject(TENMutableSet *set, TENObject *object) {
    if (NULL != set) {
        for (uint64_t index = 0; index < set->_count; index++) {
            if (set->_array[index] == object) {
                return index;
            }
        }
    }
    
    return TENIndexNotFound;
}

uint64_t TENMutableSetGetCount(TENMutableSet *set) {
    return (NULL == set) ? 0 : set->_count;
}

void TENMutableSetRemoveObjectAtIndex(TENMutableSet *set, uint64_t index) {
    if (NULL != set && index < set->_count) {
        TENMutableSetSetObjectAtIndex(set, NULL, index);

        set->_count -= 1;
        
        for (; index < set->_count; index++) {
            set->_array[index] = set->_array[index + 1];
        }
        
        set->_array[set->_count] = NULL;
        
        TENMutableSetChangeCapacityIfNeeded(set);
    }
}

void TENMutableSetRemoveLastObject(TENMutableSet *set) {
    if (NULL != set) {
        TENMutableSetRemoveObjectAtIndex(set, set->_count - 1);
    }
}

void TENMutableSetRemoveObject(TENMutableSet *set, TENObject *object) {
    if (NULL != set) {
        TENMutableSetRemoveObjectAtIndex(set, TENMutableSetIndexOfObject(set, object));
    }
}

void TENMutableSetRemoveAllObjects(TENMutableSet *set) {
    if (NULL != set) {
        while (TENMutableSetGetCount(set) > 0) {
            TENMutableSetRemoveLastObject(set);
        }
    }
}

#pragma mark -
#pragma mark Private Implementations

void TENMutableSetSetObjectAtIndex(TENMutableSet *set, TENObject *object, uint64_t index) {
    assert(NULL != set);
    TENPropertyHolderSetTargetRetain((void **)&set->_array[index], object);
}

void TENMutableSetSetCapacity(TENMutableSet *set, uint64_t capacity) {
    assert(NULL != set);
    
    if (set->_capacity != capacity) {
        set->_array = realloc(set->_array, capacity * sizeof(*set->_array));
        
        if (capacity > set->_capacity) {
            void *startPointer = set->_array + set->_capacity;
            size_t numberOfBytes = (capacity - set->_capacity) * sizeof(*set->_array);
            
            memset(startPointer, 0, numberOfBytes);
        }
        
        set->_capacity = capacity;
    }
}

void TENMutableSetChangeCapacityIfNeeded(TENMutableSet *set) {
    TENMutableSetSetCapacity(set, TENMutableSetRequiredCapacity(set));
}

uint64_t TENMutableSetRequiredCapacity(TENMutableSet *set) {
    assert(NULL != set);
    
    uint64_t capacity =  set->_capacity;
    
    if (set->_count == capacity) {
        capacity *= 2;
    }
    
    if (set->_count < capacity / 2) {
        capacity /= 2;
    }
    
    return fmax(capacity, 1);
}
