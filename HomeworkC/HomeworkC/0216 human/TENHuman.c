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
#include "TENString.h"

struct TENHuman {
    TENString *_name;
    uint8_t _age;
    TENGender _gender;
    uint8_t _childrenCount;
    TENHuman *_partner;
    TENHuman *_father;
    TENHuman *_mother;
    TENHuman *_childArray[20];
    uint64_t _referenceCount;
};

#pragma mark -
#pragma mark Private Declarations

static
void TENHumanAddChild(TENHuman *parent, TENHuman *child);

static
void TENHumanRemoveChild(TENHuman *parent, TENHuman *child);

static
void TENHumanDealloc(TENHuman *human);

static
void TENHumanHold(TENHuman **holder, TENHuman *target);

static
void TENHumanDrop(TENHuman **holder, TENHuman *target);

static
int TENHumanIndexChild(TENHuman *parent, TENHuman *child);

static
void TENHumanRemoveElementFromChildArray(TENHuman *parent, int index);

#pragma mark -
#pragma mark Public Implementations

TENHuman *TENHumanCreate() {
    TENHuman *human = calloc(1, sizeof(*human));
    
    human->_referenceCount = 1;
    
    return human;
}

void TENHumanRetain(TENHuman *human) {
    human->_referenceCount += 1;
}

void TENHumanRelease(TENHuman *human) {
    human->_referenceCount -= 1;
    if (0 == human->_referenceCount) {
        TENHumanDealloc(human);
    }
}

void TENHumanSetPartner(TENHuman *human, TENHuman *partner) {
    if (NULL != human && human != partner) {
        if (NULL != human->_partner) {
            TENHumanRelease(human->_partner);
        }
        
        human->_partner = partner;
        
        if (NULL != human->_partner) {
            TENHumanRetain(human->_partner);
        }
    }
}

TENHuman *TENHumanGetPartner(TENHuman *human) {
    return (NULL != human) ? human->_partner : NULL;
}


void TENHumanSetFather(TENHuman *human, TENHuman *father) {
    if (NULL != human && human != father) {
        if (NULL != human->_father) {
            TENHumanRelease(human->_father);
        }
        
        human->_father = father;
        
        if (NULL != human->_father) {
            TENHumanRetain(human->_father);
        }
    }
}

void TENHumanSetChildrenCount(TENHuman *human, uint8_t childrenCount) {
    human->_childrenCount = childrenCount;
}

uint8_t TENHumanGetChildrenCount(TENHuman *human, uint8_t childrenCount) {
    return human->_childrenCount;
}


TENHuman *TENHumanCreateWithParam(char *name, TENGender gender, TENHuman *father, TENHuman *mother) {
    TENHuman *human = malloc(sizeof(*human));
    
    human->_referenceCount = 1;

    human->_name = TENStringCreate(name);
    human->_age = 0;
    human->_gender = gender;
    human->_childrenCount = 0;
    human->_partner = NULL;
    human->_mother = NULL;
    human->_father = NULL;
    
    TENHumanAddChild(father, human);
    TENHumanAddChild(mother, human);
    
    return human;
}


void TENHumanHold(TENHuman **holder, TENHuman *target) {
    *holder = target;
    TENHumanRetain(target);
}


void TENHumanDrop(TENHuman **holder, TENHuman *target) {
    *holder = NULL;
    TENHumanRelease(target);
}

void TENHumanPrint(TENHuman *human) {
    printf("(%2llu) ", human->_referenceCount);
    printf("%s ", TENStringGetData(human->_name));
    
    char *nameFather = NULL != human->_father ? TENStringGetData(human->_father->_name) : "...";
    char *nameMother = NULL != human->_mother ? TENStringGetData(human->_mother->_name) : "...";
    
    printf("<%s+%s>: ", nameFather, nameMother);
//    printf("%d year /", human->_age);
    printf("%s/", TENGenderMale == human->_gender ? "male" : "female");
    
    if (NULL == TENHumanGetPartner(human)) {
        printf("single\n");
    } else {
        printf("married to %s\n", TENStringGetData(TENHumanGetPartner(human)->_name));
    }
    
    printf("children(%d): ", human->_childrenCount);
    
    for (int i = 0 ; i < human->_childrenCount; i++) {
        printf("%s ", TENStringGetData(human->_childArray[i]->_name));
    }
    
    printf("\n\n");
}

void TENHumanRename(TENHuman *human, char *newName) {
    TENStringSetData(human->_name, newName);
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

void TENHumanClear(TENHuman *human) {
    TENHumanDivorce(human);
    
    TENHumanRemoveChild(human->_father, human);
    TENHumanRemoveChild(human->_mother, human);
    
    while (human->_childrenCount > 0) {
        TENHumanRemoveChild(human, human->_childArray[0]);
    }
    
    TENHumanRelease(human);
}

#pragma mark -
#pragma mark Private Implementations

void TENHumanDealloc(TENHuman *human) {
    TENStringRelease(human->_name);
    free(human);
}


void TENHumanAddChild(TENHuman *parent, TENHuman *child) {
    if (NULL != parent) {
        
        TENHumanHold(&parent->_childArray[parent->_childrenCount], child);
        parent->_childrenCount += 1;

        
//        TENHuman *holdParent = (TENGenderMale == parent->_gender) ? child->_father : child->_mother;
//        TENHumanHold(&holdParent, parent);

        if (TENGenderMale == parent->_gender) {
            TENHumanHold(&child->_father, parent);
        } else {
            TENHumanHold(&child->_mother, parent);
        }
    }
}

void TENHumanRemoveChild(TENHuman *parent, TENHuman *child) {
    
    if (NULL != parent) {
        TENHumanRemoveElementFromChildArray(parent, TENHumanIndexChild(parent, child));
        
        TENHumanDrop(&parent->_childArray[parent->_childrenCount], child);
        
        TENHuman *dropParent = (parent == child->_father) ? child->_father : child->_mother;
        
        TENHumanDrop(&dropParent, parent);
    }
}

int TENHumanIndexChild(TENHuman *parent, TENHuman *child) {
    int indexChild = 0;
    
    for (; parent->_childArray[indexChild] != child; indexChild++);

    return indexChild;
}

void TENHumanRemoveElementFromChildArray(TENHuman *parent, int index) {
    parent->_childrenCount -= 1;
    
    for (; index < parent->_childrenCount; index++ ) {
        parent->_childArray[index] = parent->_childArray[index+1];
    }
    
    parent->_childArray[parent->_childrenCount] = NULL;
}
