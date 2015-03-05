//
//  TENHuman.h
//  HomeworkC
//
//  Created by 444ten on 2/17/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENHuman__
#define __HomeworkC__TENHuman__

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
    
    TENHuman *_father;
    TENHuman *_mother;
    TENHuman *_partner;
    TENChildArray *_childArray;
    
    uint8_t _age;
    TENGender _gender;
};

extern
TENHuman *TENHumanCreateWithNameGender(TENString *name, TENGender gender);

extern
TENHuman *TENHumanMaleCreateWithName(TENString *name);

extern
TENHuman *TENHumanFemaleCreateWithName(TENString *name);

extern
void __TENHumanDeallocate(TENHuman *human);

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
