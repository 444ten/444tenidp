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

struct TENPersonStruct {
    char *_name;
    uint8_t _age;
    TENPersonGender _gender;
    uint8_t _numberOfChildren;
    bool _isMarried;
    TENPersonStruct *_partnerRef;
    TENPersonStruct *_fatherRef;
    TENPersonStruct *_motherRef;
    TENPersonStruct *_childRefArray[20];
    uint64_t _referenceCount;
};

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

TENPersonStruct *TENPersonWasBorn(char *name,
                                  TENPersonGender gender,
                                  TENPersonStruct *fatherRef,
                                  TENPersonStruct *motherRef)
{
    TENPersonStruct *person = malloc(sizeof(*person));
    person->_name = name;
    person->_age = 0;
    person->_gender = gender;
    person->_numberOfChildren = 0;
    person->_isMarried = false;
    person->_partnerRef = NULL;
    person->_fatherRef = fatherRef;
    person->_motherRef = motherRef;
    person->_referenceCount = 1;
    
    return person;
}

void TENPersonProfileOutput(TENPersonStruct *person) {
    printf("profile person  %s\n", person->_name);
    printf("               age %d\n", person->_age);
    printf("            gender %s\n", TENPersonGenderMale == person->_gender ? "male" : "female");
    printf("number of children %d\n", person->_numberOfChildren);
    printf("        is married %s\n", person->_isMarried ? "Yes" : "No");
    printf("      partner name %s\n", person->_partnerRef->_name);
    
    printf("reference count %llu\n", person->_referenceCount);
    printf("\n");
}

void TENWeddingSangAndDanced(TENPersonStruct *husband, TENPersonStruct *wife) {
    husband->_isMarried = true;
    husband->_partnerRef = wife;
    husband->_referenceCount += 1;
    
    wife->_isMarried = true;
    wife->_partnerRef = wife;
    wife->_referenceCount += 1;
}

#pragma mark -
#pragma mark Private Implementations
