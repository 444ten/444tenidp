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
#include "TENHuman.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENHumanHolderSetTarget(void **holder, void **target);

#pragma mark -
#pragma mark Public Implementations

TENHuman *TENHumanCreateWithNameGender(char *name, TENGender gender) {
    TENHuman *human =TENObjectCreate(TENHuman);

    TENString *stringName = TENObjectCreate(TENString);
    TENStringSetData(stringName, name);
    TENHumanSetName(human, stringName);
    
    TENHumanSetGender(human, gender);
    
    human->_childArray = TENObjectCreate(TENChildArray);
    
    return human;
}

void __TENHumanDeallocate(TENHuman *human) {
    TENHumanSetName(human, NULL);
    TENObjectRelease(human->_childArray);
    
    __TENObjectDeallocate(human);
}

void TENHumanSetName(TENHuman *human, TENString *name) {
    if (NULL != human) {
        TENHumanHolderSetTarget((void *)&human->_name, (void *)&name);
    }
}

void TENHumanSetPartner(TENHuman *human, TENHuman *partner) {
    if (NULL != human && human != partner) {
        TENHumanHolderSetTarget((void *)&human->_partner, (void *)&partner);
    }
}

void TENHumanSetFather(TENHuman *human, TENHuman *father) {
    if (NULL != human && human != father) {
        TENHumanHolderSetTarget((void *)&human->_father, (void *)&father);
    }
}

void TENHumanSetMother(TENHuman *human, TENHuman *mother) {
    if (NULL != human && human != mother) {
        TENHumanHolderSetTarget((void *)&human->_mother, (void *)&mother);
    }
}

void TENHumanSetGender(TENHuman *human, TENGender gender) {
    human->_gender = gender;
}

TENString *TENHumanGetName(TENHuman *human) {
    return human->_name;
}

TENHuman *TENHumanGetPartner(TENHuman *human) {
    return (NULL != human) ? human->_partner : NULL;
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
        TENHumanSetPartner(human->_partner, NULL);
        TENHumanSetPartner(human, NULL);
    }
}

void TENHumanAddChild(TENHuman *parent, TENHuman *child) {
    if (NULL == parent->_childArray) {
        parent->_childArray = TENObjectCreate(TENChildArray);
    }
    
    if (TENGenderMale == parent->_gender) {
        TENHumanSetFather(child, parent);
    } else {
        TENHumanSetMother(child, parent);
    }
    
    TENChildArrayAddObject(parent->_childArray, child);
}

void TENHumanRemoveChild(TENHuman *parent, TENHuman *child) {
    if (NULL != parent) {
        if (child->_father == parent) {
            TENHumanSetFather(child, NULL);
        } else {
            TENHumanSetMother(child, NULL);
        }
        
        uint8_t index = TENChildArrayIndexOfObject(parent->_childArray, child);
        TENChildArrayRemoveObjectAtIndex(parent->_childArray, index);
    }
}

void TENHumanChildArrayPrint(TENChildArray *childArray) {
    if (NULL != childArray && childArray->_childrenCount > 0) {
        printf(" total %d: ", childArray->_childrenCount);
        for (int i = 0; i < childArray->_childrenCount; i++) {
            printf("%s ", TENStringGetData(childArray->_array[i]->_name));
        }
        
        printf("\n");
    }
}

void TENHumanPrint(TENHuman *human) {
    printf("(%2llu) ", TENObjectGetReferenceCount(human));
    printf("%s ", TENStringGetData(TENHumanGetName(human)));
    
    char *nameFather = NULL != human->_father ? TENStringGetData(TENHumanGetName(human->_father)) : "...";
    char *nameMother = NULL != human->_mother ? TENStringGetData(TENHumanGetName(human->_mother)) : "...";
    
    printf("<%s+%s>: ", nameFather, nameMother);
    printf("%s/", TENGenderMale == human->_gender ? "male" : "female");
    
    if (NULL == TENHumanGetPartner(human)) {
        printf("single\n");
    } else {
        printf("married to %s\n", TENStringGetData(TENHumanGetName(TENHumanGetPartner(human))));
    }
    
    TENHumanChildArrayPrint(human->_childArray);
    
    printf("\n");
}

#pragma mark -
#pragma mark Private Implementations

void TENHumanHolderSetTarget(void **holder, void **target) {
    if (*holder != *target) {
        if (NULL != *holder) {
            TENObjectRelease(*holder);
        }
        
        *holder = *target;
        
        if (NULL != *holder) {
            TENObjectRetain(*holder);
        }
    }
}
