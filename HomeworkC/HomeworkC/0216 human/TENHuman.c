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

static
void TENHumanHolderSetTargetRetain(void **holder, void *target);

static
void TENHumanHolderSetTargetAssign(void **holder, void *target);

static
bool TENHumanNullOrEqualTarget(TENHuman *human, TENHuman *target);

#pragma mark -
#pragma mark Public Implementations

TENHuman *TENHumanCreateWithNameGender(TENString *name, TENGender gender) {
    TENHuman *human = TENObjectCreate(TENHuman);

    TENHumanSetName(human, name);
    TENHumanSetAge(human, 16);
    TENHumanSetGender(human, gender);
    
    TENChildArray *childArray = TENObjectCreate(TENChildArray);
    TENHumanSetChildArray(human, childArray);
    TENObjectRelease(childArray);
    
    return human;
}

TENHuman *TENHumanMaleCreateWithName(TENString *name) {
    return TENHumanCreateWithNameGender(name, TENGenderMale);
}

TENHuman *TENHumanFemaleCreateWithName(TENString *name) {
    return TENHumanCreateWithNameGender(name, TENGenderFemale);
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
    return TENHumanNullOrEqualTarget(human, NULL) ? NULL : human->_name;
}

TENHuman *TENHumanGetFather(TENHuman *human) {
    return TENHumanNullOrEqualTarget(human, NULL) ? NULL : human->_father;
}

TENHuman *TENHumanGetMother(TENHuman *human) {
    return TENHumanNullOrEqualTarget(human, NULL) ? NULL : human->_mother;
}

TENHuman *TENHumanGetPartner(TENHuman *human) {
    return TENHumanNullOrEqualTarget(human, NULL) ? NULL : human->_partner;
}

TENChildArray *TENHumanGetChildArray(TENHuman *human) {
    return TENHumanNullOrEqualTarget(human, NULL) ? NULL : human->_childArray;
}

uint8_t TENHumanGetAge(TENHuman *human) {
    return TENHumanNullOrEqualTarget(human, NULL) ? 0 : human->_age;
}

TENGender TENHumanGetGender(TENHuman *human) {
    return TENHumanNullOrEqualTarget(human, NULL) ? 0 : human->_gender;
}

#pragma mark - Behavior

void TENHumanMarry(TENHuman *husband, TENHuman *wife) {
    TENHumanDivorce(husband);
    TENHumanDivorce(wife);
    TENHumanSetPartner(husband, wife);
    TENHumanSetPartner(wife, husband);
}

void TENHumanDivorce(TENHuman *human) {
    if (TENHumanNullOrEqualTarget(human, NULL)) {
        return;
    }

    TENHumanSetPartner(TENHumanGetPartner(human), NULL);
    TENHumanSetPartner(human, NULL);
}

void TENHumanAddChild(TENHuman *parent, TENHuman *child) {
    if (TENHumanNullOrEqualTarget(parent, child)) {
        return;
    }
    
    if (TENHumanNullOrEqualTarget(child, NULL)) {
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
    if (TENHumanNullOrEqualTarget(parent, child)) {
        return;
    }

    if (TENHumanNullOrEqualTarget(child, NULL)) {
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
    if (TENHumanNullOrEqualTarget(human, NULL)) {
        return;
    }

    TENHumanHolderSetTargetRetain((void **)&human->_name, name);
}

void TENHumanSetFather(TENHuman *human, TENHuman *father) {
    if (TENHumanNullOrEqualTarget(human, father)) {
        return;
    }

    TENHumanHolderSetTargetRetain((void **)&human->_father, father);
}

void TENHumanSetMother(TENHuman *human, TENHuman *mother) {
    if (TENHumanNullOrEqualTarget(human, mother)) {
        return;
    }

    TENHumanHolderSetTargetRetain((void **)&human->_mother, mother);
}

void TENHumanSetPartner(TENHuman *human, TENHuman *partner) {
    if (TENHumanNullOrEqualTarget(human, partner)) {
        return;
    }

    TENGender humanGender = TENHumanGetGender(human);
    if (humanGender == TENGenderMale) {
        TENHumanHolderSetTargetRetain((void **)&human->_partner, partner);
    } else {
        TENHumanHolderSetTargetAssign((void **)&human->_partner, partner);
    }
}

void TENHumanSetChildArray(TENHuman *human, TENChildArray *childArray) {
    if (TENHumanNullOrEqualTarget(human, NULL)) {
        return;
    }

    TENHumanHolderSetTargetRetain((void **)&human->_childArray, childArray);
}

void TENHumanSetAge(TENHuman *human, uint8_t age) {
    if (TENHumanNullOrEqualTarget(human, NULL)) {
        return;
    }
    
    human->_age = age;
}

void TENHumanSetGender(TENHuman *human, TENGender gender) {
    if (TENHumanNullOrEqualTarget(human, NULL)) {
        return;
    }
    
    human->_gender = gender;
}

void TENHumanHolderSetTargetRetain(void **holder, void *target) {
    if (*holder != target) {
        if (NULL != *holder) {
            TENObjectRelease(*holder);
        }
        
        *holder = target;
        
        if (NULL != *holder) {
            TENObjectRetain(*holder);
        }
    }
}

void TENHumanHolderSetTargetAssign(void **holder, void *target) {
    *holder = target;
}

bool TENHumanNullOrEqualTarget(TENHuman *human, TENHuman *target) {
    return (NULL == human || human == target);
}
