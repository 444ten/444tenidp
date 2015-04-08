//
//  TENObject.h
//  HomeworkC
//
//  Created by 444ten on 2/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENObject__
#define __HomeworkC__TENObject__

#include <stdlib.h>

typedef void(*TENDeallocateCallback)(void *);

struct TENObject {
    uint64_t _referenceCount;
    TENDeallocateCallback _deallocateCallback;
};
typedef struct TENObject TENObject;

extern
void *__TENObjectCreate(size_t objectSize, TENDeallocateCallback deallocateCallback);
#define TENObjectCreate(type) \
    __TENObjectCreate(sizeof(type), (TENDeallocateCallback)__##type##Deallocate)

extern
void *__TENObjectWithSizeAndDeallocator(size_t objectSize, TENDeallocateCallback dellocatorCallback);
#define TENObjectWithType(type) \
    __TENObjectWithSizeAndDeallocator(sizeof(type), (TENDeallocateCallback)__##type##Deallocate)

extern
void __TENObjectDeallocate(void *object);

extern
uint64_t TENObjectGetReferenceCount(void *object);

extern
void *TENRetain(void *object);

extern
void TENRelease(void *voidObject);

extern
void *TENAutorelease(void *object);

#endif /* defined(__HomeworkC__TENObject__) */
