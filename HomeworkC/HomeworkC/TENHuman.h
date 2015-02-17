//
//  TENHuman.h
//  HomeworkC
//
//  Created by 444ten on 2/17/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENHuman__
#define __HomeworkC__TENHuman__

typedef enum {
    TENPersonGenderMale,
    TENPersonGenderFemale
} TENPersonGender;

typedef struct TENPersonStruct TENPersonStruct;

extern
TENPersonStruct *TENPersonWasBorn(char *name,
                                  TENPersonGender gender,
                                  TENPersonStruct *fatherRef,
                                  TENPersonStruct *motherRef);

extern
void TENPersonProfileOutput(TENPersonStruct *person);

extern
void TENWeddingSangAndDanced(TENPersonStruct *husband, TENPersonStruct *wife);

#endif /* defined(__HomeworkC__TENHuman__) */
