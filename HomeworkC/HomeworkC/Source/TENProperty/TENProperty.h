//
//  TENProperty.h
//  HomeworkC
//
//  Created by 444ten on 3/10/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENProperty__
#define __HomeworkC__TENProperty__

#include <stdio.h>
#include <stdbool.h>

extern
void __TENRetainingSetter(void *owner, void **dataRef, void *object);
#define TENRetainingSetter(owner, dataRef, object) \
    __TENRetainingSetter(owner, (void **)dataRef, object)

extern
void __TENAssigningSetter(void *owner, void **dataRef, void *object);
#define TENAssigningSetter(owner, dataRef, object) \
    __TENAssigningSetter(owner, (void **)dataRef, object)

#warning deprecate
extern
void TENPropertyHolderSetTargetRetain(void **holder, void *target);

#warning deprecate
extern
void TENPropertyHolderSetTargetAssign(void **holder, void *target);

extern
bool TENPropertyIsNullOrIsTarget(void *property, void *target);

#endif /* defined(__HomeworkC__TENProperty__) */
