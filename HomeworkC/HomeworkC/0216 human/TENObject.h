//
//  TENObject.h
//  HomeworkC
//
//  Created by 444ten on 2/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENObject__
#define __HomeworkC__TENObject__

#include <stdio.h>

typedef void(*TENDeallocateCallBack)(void *);

struct TENObject {
    uint64_t _refernceCount;
    TENDeallocateCallBack _deallocateCallBack;
};
typedef struct TENObject TENObject;

extern
void *__TENObjectCreate(size_t objectSize, TENDeallocateCallBack deallocateCallback);
#define TenObjectCreate(type) \
    __TENObjectCreate(sizeof(type), (TENDeallocateCallBack)__##type##Deallocate)

extern
void *TENObjectRetain(void *object);

extern
void TENObjectRelease(void *voidObject);

extern
uint64_t TENObjectGetReferenceCount(void *object);

extern
void __TENObjectDeallocate(void *object);

#endif /* defined(__HomeworkC__TENObject__) */
