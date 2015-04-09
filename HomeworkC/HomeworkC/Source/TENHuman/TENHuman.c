//
//  TENHuman.c
//  HomeworkC
//
//  Created by 444ten on 2/17/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "TENChildArray.h"
#include "TENHuman.h"
#include "TENProperty.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENHumanSetName(TENHuman *human, TENString *name);

static
void TENHumanSetFather(TENHuman *human, TENHuman *father);

static
void TENHumanSetMother(TENHuman *human, TENHuman *mother);

static
void TENHumanSetPartner(TENHuman *human, TENHuman *partner);

static
void TENHumanSetChildArray(TENHuman *human, TENChildArray *childArray);

static
void TENHumanSetAge(TENHuman *human, uint8_t age);

static
void TENHumanSetGender(TENHuman *human, TENGender gender);

#pragma mark -
#pragma mark Public Implementations

TENHuman *TENHumanWithNameGender(TENString *name, TENGender gender) {
    TENHuman *human = TENObjectWithType(TENHuman);

    TENHumanSetName(human, name);
    TENHumanSetAge(human, 16);
    TENHumanSetGender(human, gender);
    
    TENChildArray *childArray = TENObjectCreate(TENChildArray);
    TENHumanSetChildArray(human, childArray);
    TENRelease(childArray);
    
    return human;
}

TENHuman *TENHumanMaleWithName(TENString *name) {
    return TENHumanWithNameGender(name, TENGenderMale);
}

TENHuman *TENHumanFemaleWithName(TENString *name) {
    return TENHumanWithNameGender(name, TENGenderFemale);
}

void __TENHumanDeallocate(TENHuman *human) {
    TENHumanSetName(human, NULL);
    TENHumanSetFather(human, NULL);
    TENHumanSetMother(human, NULL);
    TENHumanSetPartner(human, NULL);
    TENHumanSetChildArray(human, NULL);
    
    __TENObjectDeallocate(human);
}

TENString *TENHumanGetName(TENHuman *human) {
    return TENPropertyIsNullOrIsTarget(human, NULL) ? NULL : human->_name;
}

TENHuman *TENHumanGetFather(TENHuman *human) {
    return TENPropertyIsNullOrIsTarget(human, NULL) ? NULL : human->_father;
}

TENHuman *TENHumanGetMother(TENHuman *human) {
    return TENPropertyIsNullOrIsTarget(human, NULL) ? NULL : human->_mother;
}

TENHuman *TENHumanGetPartner(TENHuman *human) {
    return TENPropertyIsNullOrIsTarget(human, NULL) ? NULL : human->_partner;
}

TENChildArray *TENHumanGetChildArray(TENHuman *human) {
    return TENPropertyIsNullOrIsTarget(human, NULL) ? NULL : human->_childArray;
}

uint8_t TENHumanGetAge(TENHuman *human) {
    return TENPropertyIsNullOrIsTarget(human, NULL) ? 0 : human->_age;
}

TENGender TENHumanGetGender(TENHuman *human) {
    return TENPropertyIsNullOrIsTarget(human, NULL) ? 0 : human->_gender;
}

#pragma mark - Behavior

void TENHumanMarry(TENHuman *husband, TENHuman *wife) {
    TENHumanDivorce(husband);
    TENHumanDivorce(wife);
    TENHumanSetPartner(husband, wife);
    TENHumanSetPartner(wife, husband);
}

void TENHumanDivorce(TENHuman *human) {
    if (TENPropertyIsNullOrIsTarget(human, NULL)) {
        return;
    }

    TENHumanSetPartner(TENHumanGetPartner(human), NULL);
    TENHumanSetPartner(human, NULL);
}

void TENHumanAddChild(TENHuman *parent, TENHuman *child) {
    if (TENPropertyIsNullOrIsTarget(parent, child) ||
        TENPropertyIsNullOrIsTarget(child, NULL))
    {
        return;
    }
    
    TENChildArray *childArray = TENHumanGetChildArray(parent);
    if (NULL != childArray) {
        if (TENGenderMale == TENHumanGetGender(parent)) {
            TENHumanSetFather(child, parent);
        } else {
            TENHumanSetMother(child, parent);
        }
        
        TENChildArrayAddObject(childArray, child);
    }
}

void TENHumanRemoveChild(TENHuman *parent, TENHuman *child) {
    if (TENPropertyIsNullOrIsTarget(parent, child) ||
        TENPropertyIsNullOrIsTarget(child, NULL))
    {
        return;
    }

    TENChildArray *childArray = TENHumanGetChildArray(parent);
    if (NULL != childArray) {
        if (TENHumanGetFather(child) == parent) {
            TENHumanSetFather(child, NULL);
        } else {
            TENHumanSetMother(child, NULL);
        }
        
        TENChildArrayRemoveObjectAtIndex(childArray, TENChildArrayIndexOfObject(childArray, child));
    }
}

void TENHumanPrint(TENHuman *human) {
    printf("(%2llu) ", TENObjectGetReferenceCount(human));
    printf("%s ", TENStringGetData(TENHumanGetName(human)));
    
    char *nameFather = NULL != (TENHumanGetFather(human)) ?
                                TENStringGetData(TENHumanGetName(TENHumanGetFather(human))) : "...";
    char *nameMother = NULL != (TENHumanGetMother(human)) ?
                                TENStringGetData(TENHumanGetName(TENHumanGetMother(human))) : "...";
    
    printf("<%s+%s>: ", nameFather, nameMother);
    printf("%s/", TENGenderMale == TENHumanGetGender(human) ? "male" : "female");
    
    if (NULL == TENHumanGetPartner(human)) {
        printf("single\n");
    } else {
        printf("married to %s\n", TENStringGetData(TENHumanGetName(TENHumanGetPartner(human))));
    }
    
    TENChildArrayPrint(TENHumanGetChildArray(human));
    
    printf("\n");
}

#pragma mark -
#pragma mark Private Implementations

void TENHumanSetName(TENHuman *human, TENString *name) {
    TENRetainingSetter(human, &human->_name, name);
}

void TENHumanSetFather(TENHuman *human, TENHuman *father) {
    if (human == father) {
        return;
    }

    TENRetainingSetter(human, &human->_father, father);
}

void TENHumanSetMother(TENHuman *human, TENHuman *mother) {
    if (human == mother) {
        return;
    }
    
    TENRetainingSetter(human, &human->_mother, mother);
}

void TENHumanSetPartner(TENHuman *human, TENHuman *partner) {
    if (TENPropertyIsNullOrIsTarget(human, partner)) {
        return;
    }

    TENGender humanGender = TENHumanGetGender(human);
    if (humanGender == TENGenderMale) {
        TENPropertyHolderSetTargetRetain((void **)&human->_partner, partner);
    } else {
        TENPropertyHolderSetTargetAssign((void **)&human->_partner, partner);
    }
}

void TENHumanSetChildArray(TENHuman *human, TENChildArray *childArray) {
    if (TENPropertyIsNullOrIsTarget(human, NULL)) {
        return;
    }

    TENPropertyHolderSetTargetRetain((void **)&human->_childArray, childArray);
}

void TENHumanSetAge(TENHuman *human, uint8_t age) {
    if (TENPropertyIsNullOrIsTarget(human, NULL)) {
        return;
    }
    
    human->_age = age;
}

void TENHumanSetGender(TENHuman *human, TENGender gender) {
    if (TENPropertyIsNullOrIsTarget(human, NULL)) {
        return;
    }
    
    human->_gender = gender;
}
