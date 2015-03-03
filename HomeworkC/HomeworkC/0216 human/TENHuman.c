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
void TENHumanHolderSetTarget(TENHuman **holder, TENHuman **target);

#pragma mark -
#pragma mark Public Implementations

void __TENHumanDeallocate(TENHuman *human) {
    TENObjectRelease(human->_name);
    TENObjectRelease(human->_childArray);
    
    __TENObjectDeallocate(human);
}

void TENHumanSetName(TENHuman *human, TENString *name) {
    human->_name = TENObjectCreate(TENString);
    TENStringSetData(human->_name, name->_data);
}

TENString *TENHumanGetName(TENHuman *human) {
    return human->_name;
}

void TENHumanSetPartner(TENHuman *human, TENHuman *partner) {
    if (NULL != human && human != partner) {
        TENHumanHolderSetTarget(&human->_partner, &partner);
    }
}

TENHuman *TENHumanGetPartner(TENHuman *human) {
    return (NULL != human) ? human->_partner : NULL;
}

void TENHumanSetFather(TENHuman *human, TENHuman *father) {
    if (NULL != human && human != father) {
        TENHumanHolderSetTarget(&human->_father, &father);
    }
}

void TENHumanSetMother(TENHuman *human, TENHuman *mother) {
    if (NULL != human && human != mother) {
        TENHumanHolderSetTarget(&human->_mother, &mother);
    }
}

void TENHumanSetGender(TENHuman *human, TENGender gender) {
    human->_gender = gender;
}

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

#pragma mark -
#pragma mark Private Implementations

void TENHumanHolderSetTarget(TENHuman **holder, TENHuman **target) {
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
