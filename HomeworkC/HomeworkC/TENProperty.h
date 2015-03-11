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
void TENPropertyHolderSetTargetRetain(void **holder, void *target);

extern
void TENPropertyHolderSetTargetAssign(void **holder, void *target);

extern
bool TENPropertyIsNullOrIsTarget(void *property, void *target);

#endif /* defined(__HomeworkC__TENProperty__) */
