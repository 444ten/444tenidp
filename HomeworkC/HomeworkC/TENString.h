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

typedef struct TENString TENString;

extern
TENString *TENStringCreate(char *source);

extern
void TENStringRetain(TENString *string);

extern
void TENStringRelease(TENString *string);

extern
void TENStringSetLength(TENString *string, uint64_t length);

extern
char *TENStringGetData(TENString *string);

extern
void TENStringSetData(TENString *string, char *newString);

#endif /* defined(__HomeworkC__TENString__) */
