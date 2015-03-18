//
//  TENMutableSet.c
//  HomeworkC
//
//  Created by 444ten on 3/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>

#include "TENMutableSet.h"
#include "TENProperty.h"

#pragma mark -
#pragma mark Private Declarations


static
void TENMutableSetSetObjectAtIndex(TENMutableSet *set, TENObject *object, uint64_t index);

static
void TENMutableSetSetSize(TENMutableSet *set, uint64_t size);

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

void TENMutableSetAddObject(TENMutableSet *set, void *object) {
    if (NULL != set &&
        TENIndexNotFound == TENMutableSetIndexOfObject(set, object))
    {
        uint64_t index = TENMutableSetGetSize(set);
        
        TENMutableSetChangeCapacityIfNeeded(set);
        TENMutableSetSetSize(set, index + 1);
        TENMutableSetSetObjectAtIndex(set, object, index);
    }
    
}

extern
uint64_t TENMutableSetIndexOfObject(TENMutableSet *set, void *object) {
    if (NULL != set) {
        uint64_t index = 0;
        
        for (; index < TENMutableSetGetSize(set); index++) {
            if (set->_array[index] == object) {
                return index;
            }
        }
    }
    
    return TENIndexNotFound;
}

uint64_t TENMutableSetGetSize(TENMutableSet *set) {
    return (NULL == set) ? 0 : set->_size;
}

void TENMutableSetRemoveLastObject(TENMutableSet *set) {
    if (NULL != set) {
        uint64_t size = TENMutableSetGetSize(set);
        
        if (size > 0) {
            TENMutableSetSetSize(set, size - 1);
            TENMutableSetSetObjectAtIndex(set, NULL, size - 1);
            TENMutableSetChangeCapacityIfNeeded(set);
        }
    }
}

void TENMutableSetRemoveObject(TENMutableSet *set, void *object) {
    if (NULL != set) {
        uint64_t index = TENMutableSetIndexOfObject(set, object);
        
        if (TENIndexNotFound != index) {
            TENMutableSetSetObjectAtIndex(set, NULL, index);
            
            for (; index < TENMutableSetGetSize(set); index++) {
                set->_array[index] = set->_array[index + 1];
            }
            
            TENMutableSetRemoveLastObject(set);
        }
    }
}

void TENMutableSetRemoveAllObjects(TENMutableSet *set) {
    if (NULL != set) {
        while (TENMutableSetGetSize(set) > 0) {
            TENMutableSetRemoveLastObject(set);
        }
    }
}

#pragma mark -
#pragma mark Private Implementations

void TENMutableSetSetObjectAtIndex(TENMutableSet *set, TENObject *object, uint64_t index) {
    assert(NULL != set);
    TENPropertyHolderSetTargetRetain(&set->_array[index], object);
}

void TENMutableSetSetSize(TENMutableSet *set, uint64_t size) {
    assert(NULL != set);
    set->_size = size;
}

void TENMutableSetSetCapacity(TENMutableSet *set, uint64_t capacity) {
    assert(NULL != set);
    
    if (set->_capacity != capacity) {
        set->_capacity = capacity;
//        set->_array = calloc(set->_capacity, sizeof(*set->_array));
        
        set->_array = realloc(set->_array, set->_capacity * sizeof(*set->_array));
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
//    assert(NULL != set);
//    
//    uint64_t capacity = set->_capacity;
//    
//    if (set->_size == set->_capacity) {
//        capacity += 1;
//    } else {
//        capacity -= 1;
//    }
//    
//    return capacity;
    return 20;

}
