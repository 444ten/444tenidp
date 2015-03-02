//
//  TENHuman.h
//  HomeworkC
//
//  Created by 444ten on 2/17/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENHuman__
#define __HomeworkC__TENHuman__

#include "TENChildArray.h"
#include "TENObject.h"
#include "TENString.h"

typedef enum {
    TENGenderFemale,
    TENGenderMale
} TENGender;

typedef struct TENChildArray TENChildArray;

typedef struct TENHuman TENHuman;
struct TENHuman {
    TENObject _object;
    TENString *_name;
    uint8_t _age;
    TENGender _gender;
    TENHuman *_partner;
    TENHuman *_father;
    TENHuman *_mother;
    TENChildArray *_childArray;
};

extern
void __TENHumanDeallocate(TENHuman *human);

extern
void TENHumanSetName(TENHuman *human, TENString *name);

extern
void TENHumanSetGender(TENHuman *human, TENGender gender);

extern
void TENHumanChildArrayPrint(TENChildArray *childArray);

extern
void TENHumanPrint(TENHuman *human);

extern
void TENHumanMarry(TENHuman *husband, TENHuman *wife);

extern
void TENHumanDivorce(TENHuman *human);

extern
void TENHumanAddChild(TENHuman *parent, TENHuman *child);

extern
void TENHumanRemoveChild(TENHuman *parent, TENHuman *child);

#endif /* defined(__HomeworkC__TENHuman__) */
