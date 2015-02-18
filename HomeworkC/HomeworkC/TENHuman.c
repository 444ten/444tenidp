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
    uint8_t _numberOfChildren;
    bool _isMarried;
    TENHuman *_partnerRef;
    TENHuman *_fatherRef;
    TENHuman *_motherRef;
    TENHuman *_childRefArray[20];
    uint64_t _referenceCount;
};

#pragma mark -
#pragma mark Private Declarations

static
void TENHumanAddChild(TENHuman *parent, TENHuman *child);

static
void TENHumanDealloc(TENHuman *human);

#pragma mark -
#pragma mark Public Implementations

TENHuman *TENHumanCreate(char *name, TENGender gender, TENHuman *fatherRef, TENHuman *motherRef) {
    TENHuman *human = malloc(sizeof(*human));
    
    human->_referenceCount = 1;

    human->_name = TENStringCreate(name);
    human->_age = 0;
    human->_gender = gender;
    human->_numberOfChildren = 0;
    human->_isMarried = false;
    human->_partnerRef = NULL;
    
    human->_fatherRef = fatherRef;
    if (fatherRef) {
        TENHumanAddChild(fatherRef, human);
    }
    
    human->_motherRef = motherRef;
    if (motherRef) {
        TENHumanAddChild(motherRef, human);
    }
    
    return human;
}

void TENHumanRetain(TENHuman *human) {
    human->_referenceCount += 1;
}

extern
void TENHumanRelease(TENHuman *human) {
    human->_referenceCount -= 1;
    if (0 == human->_referenceCount) {
        TENHumanDealloc(human);
    }
}

void TENHumanPrint(TENHuman *human) {
    printf("(%3llu) ", human->_referenceCount);
    printf("%s: ", TENStringGetData(human->_name));
    printf("%d year /", human->_age);
    printf(" %s /", TENGenderMale == human->_gender ? "male" : "female");
    printf(" %s", human->_isMarried ? "married to" : "single");
    printf(" %s\n", NULL != human->_partnerRef ?
           TENStringGetData(human->_partnerRef->_name): "");
    
    printf("children(%d): ", human->_numberOfChildren);
    
    for (int i = 0 ; i < human->_numberOfChildren; i++) {
        printf("%s ", TENStringGetData(human->_childRefArray[i]->_name));
    }
    
    printf("\n\n");
}

void TENHumanRename(TENHuman *human, char *newName) {
    TENStringSetData(human->_name, newName);
}

void TENHumanMarry(TENHuman *husband, TENHuman *wife) {
    husband->_isMarried = true;
    husband->_partnerRef = wife;
    TENHumanRetain(husband);
    
    wife->_isMarried = true;
    wife->_partnerRef = husband;
    TENHumanRetain(wife);
}

void TENHumanDivorce(TENHuman *human) {
    human->_partnerRef->_isMarried = false;
    human->_partnerRef->_partnerRef = NULL;
    TENHumanRelease(human->_partnerRef);
    
    human->_isMarried = false;
    human->_partnerRef = NULL;
    TENHumanRelease(human);
}

void TENHumanClear(TENHuman *human) {
    if (NULL != human->_partnerRef) {
        human->_partnerRef->_partnerRef = NULL;
        TENHumanRelease(human->_partnerRef);
        TENHumanRelease(human);
    }
}

#pragma mark -
#pragma mark Private Implementations

void TENHumanAddChild(TENHuman *parent, TENHuman *child) {
    TENHumanRetain(parent);
    TENHumanRetain(child);
    parent->_childRefArray[parent->_numberOfChildren] = child;
    parent->_numberOfChildren += 1;
}

void TENHumanDealloc(TENHuman *human) {
    TENStringRelease(human->_name);
    free(human);
}
