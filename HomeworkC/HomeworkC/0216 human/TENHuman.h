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
    TENGenderFemale,
    TENGenderMale
} TENGender;

typedef struct TENHuman TENHuman;

extern
TENHuman *TENHumanCreate();

extern
TENHuman *TENHumanCreateWithParam(char *name, TENGender gender, TENHuman *father, TENHuman *mother);

extern
void TENHumanRetain(TENHuman *human);

extern
void TENHumanRelease(TENHuman *human);

extern
void TENHumanPrint(TENHuman *human);

extern
void TENHumanRename(TENHuman *human, char *newName);

extern
void TENHumanMarry(TENHuman *husband, TENHuman *wife);

extern
void TENHumanDivorce(TENHuman *human);

extern
void TENHumanClear(TENHuman *human);

#endif /* defined(__HomeworkC__TENHuman__) */
