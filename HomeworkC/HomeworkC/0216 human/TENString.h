//
//  TENString.h
//  HomeworkC
//
//  Created by 444ten on 2/18/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENString__
#define __HomeworkC__TENString__

#include <stdlib.h>

#include "TENObject.h"

struct TENString {
    TENObject _object;
    char *_data;
    uint64_t _length;
};
typedef struct TENString TENString;

extern
TENString *TENStringCreateWithData(char *data);

extern
void __TENStringDeallocate(TENString *string);

extern
void TENStringSetData(TENString *string, char *data);

extern
char *TENStringGetData(TENString *string);

#endif /* defined(__HomeworkC__TENString__) */
