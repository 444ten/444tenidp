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

struct TENHuman {
    char *_name;
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
void TENHumanDealloc(TENHuman *human);

#pragma mark -
#pragma mark Public Implementations

TENHuman *TENHumanCreate(char *name, TENGender gender, TENHuman *fatherRef, TENHuman *motherRef) {
    TENHuman *human = malloc(sizeof(*human));
    
    human->_referenceCount = 1;

    human->_name = name;
    human->_age = 0;
    human->_gender = gender;
    human->_numberOfChildren = 0;
    human->_isMarried = false;
    human->_partnerRef = NULL;
    
    human->_fatherRef = fatherRef;
    if (fatherRef) {
        TENHumanRetain(human->_fatherRef);
        TENHumanRetain(human);
    }
    
    human->_motherRef = motherRef;
    if (motherRef) {
        TENHumanRetain(human->_motherRef);
        TENHumanRetain(human);
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
    printf("profile human  %s\n", human->_name);
    printf("               age %d\n", human->_age);
    printf("            gender %s\n", TENGenderMale == human->_gender ? "male" : "female");
    printf("number of children %d\n", human->_numberOfChildren);
    printf("        is married %s\n", human->_isMarried ? "Yes" : "No");
    printf("      partner name %s\n", NULL != human->_partnerRef ? human->_partnerRef->_name : "none");
    
    printf("reference count %llu\n", human->_referenceCount);
    printf("\n");
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


#pragma mark -
#pragma mark Private Implementations

void TENHumanDealloc(TENHuman *human) {
    free(human);
}
