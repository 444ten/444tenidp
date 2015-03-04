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
void TENHumanSetGender(TENHuman *human, TENGender gender);

static
void TENHumanHolderSetTarget(void **holder, void *target);

#pragma mark -
#pragma mark Public Implementations

TENHuman *TENHumanCreateWithNameGender(char *name, TENGender gender) {
    TENHuman *human =TENObjectCreate(TENHuman);

    TENString *stringName = TENObjectCreate(TENString);
    TENStringSetData(stringName, name);
    TENHumanSetName(human, stringName);
    TENObjectRelease(stringName);
    
    TENHumanSetGender(human, gender);
    
    TENChildArray *childArray = TENObjectCreate(TENChildArray);
    TENHumanSetChildArray(human, childArray);
    TENObjectRelease(childArray);
    
    return human;
}

TENHuman *TENHumanMaleCreateWithName(char *name) {
    return TENHumanCreateWithNameGender(name, TENGenderMale);
}

TENHuman *TENHumanFemaleCreateWithName(char *name) {
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
    return (NULL != human) ? human->_name : NULL;
}

TENHuman *TENHumanGetFather(TENHuman *human) {
    return (NULL != human) ? human->_father : NULL;
}

TENHuman *TENHumanGetMother(TENHuman *human) {
    return (NULL != human) ? human->_mother : NULL;
}

TENHuman *TENHumanGetPartner(TENHuman *human) {
    return (NULL != human) ? human->_partner : NULL;
}

TENChildArray *TENHumanGetChildArray(TENHuman *human) {
    return (NULL != human) ? human->_childArray : NULL;
}

uint8_t TENHumanGetAge(TENHuman *human) {
    return (NULL != human) ? human->_age : 0;
}

TENGender TENHumanGetGender(TENHuman *human) {
    return (NULL != human) ? human->_gender : 0;
}

#pragma mark - Behavior

void TENHumanMarry(TENHuman *husband, TENHuman *wife) {
    TENHumanDivorce(husband);
    TENHumanDivorce(wife);
    TENHumanSetPartner(husband, wife);
    TENHumanSetPartner(wife, husband);
}

void TENHumanDivorce(TENHuman *human) {
    if (NULL != human) {
        TENHumanSetPartner(TENHumanGetPartner(human), NULL);
        TENHumanSetPartner(human, NULL);
    }
}

void TENHumanAddChild(TENHuman *parent, TENHuman *child) {
    if (NULL != parent &&
        NULL != child &&
        NULL != TENHumanGetChildArray(parent) &&
        parent != child)
    {
        if (TENGenderMale == TENHumanGetGender(parent)) {
            TENHumanSetFather(child, parent);
        } else {
            TENHumanSetMother(child, parent);
        }
        
        TENChildArrayAddObject(TENHumanGetChildArray(parent), child);
    }
}

void TENHumanRemoveChild(TENHuman *parent, TENHuman *child) {
    if (NULL != parent &&
        NULL != child &&
        NULL != TENHumanGetChildArray(parent) &&
        parent != child)
    {
        if (TENHumanGetFather(child) == parent) {
            TENHumanSetFather(child, NULL);
        } else {
            TENHumanSetMother(child, NULL);
        }
        
        uint8_t index = TENChildArrayIndexOfObject(TENHumanGetChildArray(parent), child);
        TENChildArrayRemoveObjectAtIndex(TENHumanGetChildArray(parent), index);
    }
}

void TENHumanChildArrayPrint(TENChildArray *childArray) {
    uint8_t childrenCount = TENChildArrayGetChildrenCount(childArray);
    
    if (NULL != childArray && childrenCount > 0) {
        printf(" total %d: ", childrenCount);
        for (int i = 0; i < childrenCount; i++) {
            printf("%s ", TENStringGetData(TENHumanGetName(TENChildArrayGetArray(childArray)[i])));
        }
        
        printf("\n");
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
    
    TENHumanChildArrayPrint(TENHumanGetChildArray(human));
    
    printf("\n");
}

#pragma mark -
#pragma mark Private Implementations

void TENHumanSetName(TENHuman *human, TENString *name) {
    if (NULL != human) {
        TENHumanHolderSetTarget((void **)&human->_name, name);
    }
}

void TENHumanSetFather(TENHuman *human, TENHuman *father) {
    if (NULL != human && human != father) {
        TENHumanHolderSetTarget((void **)&human->_father, father);
    }
}

void TENHumanSetMother(TENHuman *human, TENHuman *mother) {
    if (NULL != human && human != mother) {
        TENHumanHolderSetTarget((void **)&human->_mother, mother);
    }
}

void TENHumanSetPartner(TENHuman *human, TENHuman *partner) {
    if (NULL != human && human != partner) {
        TENHumanHolderSetTarget((void **)&human->_partner, partner);
    }
}

void TENHumanSetChildArray(TENHuman *human, TENChildArray *childArray) {
    if (NULL != human) {
        TENHumanHolderSetTarget((void **)&human->_childArray, childArray);
    }
}

void TENHumanSetGender(TENHuman *human, TENGender gender) {
    human->_gender = gender;
}

void TENHumanHolderSetTarget(void **holder, void *target) {
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
