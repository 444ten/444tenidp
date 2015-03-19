//
//  TENMutableSet.c
//  HomeworkC
//
//  Created by 444ten on 3/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>
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
void TENMutableSetSetCount(TENMutableSet *set, uint64_t count);

static
void TENMutableSetSetCapacity(TENMutableSet *set, uint64_t capacity);

static
uint64_t TENMutableSetGetCapacity(TENMutableSet *set);

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

void TENMutableSetAddObject(TENMutableSet *set, TENObject *object) {
    if (NULL != set &&
        TENIndexNotFound == TENMutableSetIndexOfObject(set, object))
    {
        uint64_t index = TENMutableSetGetCount(set);
        
        TENMutableSetChangeCapacityIfNeeded(set);
        TENMutableSetSetCount(set, index + 1);
        TENMutableSetSetObjectAtIndex(set, object, index);
    }
    
}

extern
uint64_t TENMutableSetIndexOfObject(TENMutableSet *set, TENObject *object) {
    if (NULL != set) {
        uint64_t index = 0;
        
        for (; index < TENMutableSetGetCount(set); index++) {
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

void TENMutableSetRemoveLastObject(TENMutableSet *set) {
    if (NULL != set) {
        uint64_t count = TENMutableSetGetCount(set);
        
        if (count > 0) {
            TENMutableSetSetCount(set, count - 1);
            TENMutableSetSetObjectAtIndex(set, NULL, count - 1);
            TENMutableSetChangeCapacityIfNeeded(set);
        }
    }
}

void TENMutableSetRemoveObject(TENMutableSet *set, TENObject *object) {
    if (NULL != set) {
        uint64_t index = TENMutableSetIndexOfObject(set, object);
        
        if (TENIndexNotFound != index) {
            TENMutableSetSetObjectAtIndex(set, NULL, index);
            
            for (; index < TENMutableSetGetCount(set); index++) {
                set->_array[index] = set->_array[index + 1];
            }
            
            TENMutableSetRemoveLastObject(set);
        }
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

void TENMutableSetSetCount(TENMutableSet *set, uint64_t count) {
    assert(NULL != set);
    set->_count = count;
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

uint64_t TENMutableSetGetCapacity(TENMutableSet *set) {
    return (NULL == set) ? 0 : set->_capacity;
}

static
void TENMutableSetChangeCapacityIfNeeded(TENMutableSet *set) {
    TENMutableSetSetCapacity(set, TENMutableSetRequiredCapacity(set));
}

static
uint64_t TENMutableSetRequiredCapacity(TENMutableSet *set) {
    assert(NULL != set);
    
    uint64_t capacity = set->_capacity;
    
    if (set->_count == set->_capacity) {
        capacity += 1;
    } else {
        capacity -= 1;
    }
    
    return capacity;
}
