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
    TENHuman *_partner;
    TENHuman *_father;
    TENHuman *_mother;
    TENHuman *_childArray[20];
    uint64_t _referenceCount;
};

#pragma mark -
#pragma mark Private Declarations

static
void TENHumanAddReferenceParentChild(TENHuman *parent, TENHuman *child);

static
void TENHumanRemoveReferenceParentChild(TENHuman *parent, TENHuman *child);

static
void TENHumanDealloc(TENHuman *human);

#pragma mark -
#pragma mark Public Implementations

TENHuman *TENHumanCreate(char *name, TENGender gender, TENHuman *father, TENHuman *mother) {
    TENHuman *human = malloc(sizeof(*human));
    
    human->_referenceCount = 1;

    human->_name = TENStringCreate(name);
    human->_age = 0;
    human->_gender = gender;
    human->_numberOfChildren = 0;
    human->_isMarried = false;
    human->_partner = NULL;
    human->_mother = NULL;
    human->_father = NULL;
    
    TENHumanAddReferenceParentChild(father, human);
    TENHumanAddReferenceParentChild(mother, human);
    
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
    printf("(%2llu) ", human->_referenceCount);
    printf("%s ", TENStringGetData(human->_name));
    
    char *nameFather = NULL != human->_father ? TENStringGetData(human->_father->_name) : "...";
    char *nameMother = NULL != human->_mother ? TENStringGetData(human->_mother->_name) : "...";
    
    printf("<%s+%s>: ", nameFather, nameMother);
//    printf("%d year /", human->_age);
    printf("%s/", TENGenderMale == human->_gender ? "male" : "female");
    printf("%s", human->_isMarried ? "married to" : "single");
    printf(" %s\n", NULL != human->_partner ?
           TENStringGetData(human->_partner->_name): "");
    
    printf("children(%d): ", human->_numberOfChildren);
    
    for (int i = 0 ; i < human->_numberOfChildren; i++) {
        printf("%s ", TENStringGetData(human->_childArray[i]->_name));
    }
    
    printf("\n\n");
}

void TENHumanRename(TENHuman *human, char *newName) {
    TENStringSetData(human->_name, newName);
}

void TENHumanMarry(TENHuman *husband, TENHuman *wife) {
    husband->_isMarried = true;
    husband->_partner = wife;
    TENHumanRetain(husband);
    
    wife->_isMarried = true;
    wife->_partner = husband;
    TENHumanRetain(wife);
}

void TENHumanDivorce(TENHuman *human) {
    human->_partner->_isMarried = false;
    human->_partner->_partner = NULL;
    TENHumanRelease(human->_partner);
    
    human->_isMarried = false;
    human->_partner = NULL;
    TENHumanRelease(human);
}

void TENHumanClear(TENHuman *human) {
    TENHumanDivorce(human);
    TENHumanRemoveReferenceParentChild(human->_father, human);
    TENHumanRemoveReferenceParentChild(human->_mother, human);
    
    while (human->_numberOfChildren > 0) {
        TENHumanRemoveReferenceParentChild(human, human->_childArray[0]);
    }
    
    TENHumanRelease(human);
}

#pragma mark -
#pragma mark Private Implementations

void TENHumanAddReferenceParentChild(TENHuman *parent, TENHuman *child) {
    if (NULL != parent) {
        TENHumanRetain(parent);
        parent->_childArray[parent->_numberOfChildren] = child;
        parent->_numberOfChildren += 1;
        
        TENHumanRetain(child);
        if (TENGenderMale == parent->_gender) {
            child->_father = parent;
        } else {
            child->_mother = parent;
        }
    }
}

void TENHumanRemoveReferenceParentChild(TENHuman *parent, TENHuman *child) {

    if (NULL != parent) {
        int indexChild = 0;
        
        TENHumanRelease(parent);
        
        for (; parent->_childArray[indexChild] != child; indexChild++);
        
        parent->_numberOfChildren -= 1;
        
        for (; indexChild < parent->_numberOfChildren; indexChild++ ) {
            parent->_childArray[indexChild] = parent->_childArray[indexChild+1];
        }
        
        parent->_childArray[parent->_numberOfChildren] = NULL;
        
        TENHumanRelease(child);
        if (child->_mother == parent) {
            child->_mother = NULL;
        }
        if (child->_father == parent) {
            child->_father = NULL;
        }
    }
}

void TENHumanDealloc(TENHuman *human) {
    TENStringRelease(human->_name);
    free(human);
}
