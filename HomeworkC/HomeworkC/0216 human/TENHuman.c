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
void TENHumanAddChild(TENHuman *parent, TENHuman *child);

static
void TENHumanRemoveChild(TENHuman *parent, TENHuman *child);

static
void TENHumanRemoveElementFromChildArray(TENHuman *parent, int index);

static
int TENHumanIndexChild(TENHuman *parent, TENHuman *child);

#pragma mark -
#pragma mark Public Implementations

void __TENHumanDeallocate(TENHuman *human) {
    TENObjectRelease(human->_name);
    
    __TENObjectDeallocate(human);
}

void TENHumanSetName(TENHuman *human, TENString *name) {
    human->_name = TenObjectCreate(TENString);
    TENStringSetData(human->_name, name->_data);
}

TENString *TENHumanGetName(TENHuman *human) {
    return human->_name;
}

void TENHumanSetPartner(TENHuman *human, TENHuman *partner) {
    if (NULL != human && human != partner && human->_partner != partner) {
        if (NULL != human->_partner) {
            TENObjectRelease(human->_partner);
        }
        
        human->_partner = partner;
        
        if (NULL != human->_partner) {
            TENObjectRetain(human->_partner);
        }
    }
}

TENHuman *TENHumanGetPartner(TENHuman *human) {
    return (NULL != human) ? human->_partner : NULL;
}

void TENHumanSetFather(TENHuman *human, TENHuman *father) {
    if (NULL != human && human != father) {
        if (NULL != human->_father) {
            TENObjectRelease(human->_father);
        }
        
        human->_father = father;
        
        if (NULL != human->_father) {
            TENObjectRetain(human->_father);
        }
    }
}

void TENHumanSetMother(TENHuman *human, TENHuman *mother) {
    if (NULL != human && human != mother) {
        if (NULL != human->_mother) {
            TENObjectRelease(human->_mother);
        }
        
        human->_mother = mother;
        
        if (NULL != human->_mother) {
            TENObjectRetain(human->_mother);
        }
    }
}


void TENHumanSetChildrenCount(TENHuman *human, uint8_t childrenCount) {
    human->_childrenCount = childrenCount;
}

uint8_t TENHumanGetChildrenCount(TENHuman *human) {
    return human->_childrenCount;
}


void TENHumanSetChildAtIndex(TENHuman *human, TENHuman *child, int index) {
    if (NULL != human && human != child) {
        if (NULL != human->_childArray[index]) {
            TENObjectRelease(human->_childArray[index]);
        }
        
        human->_childArray[index] = child;
        
        if (NULL != human->_childArray[index]) {
            TENObjectRetain(human->_childArray[index]);
        }
    }
    
}

TENHuman *TENHumanCreateWithParam(char *name, TENGender gender, TENHuman *father, TENHuman *mother) {
    TENHuman *human = TenObjectCreate(TENHuman);
    

    human->_name = TenObjectCreate(TENString);
    TENStringSetData(human->_name, name);
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
    
    TENObjectRelease(human);
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
    
    printf("children(%d): ", human->_childrenCount);
    
    for (int i = 0 ; i < human->_childrenCount; i++) {
        printf("%s ", TENStringGetData(TENHumanGetName(human->_childArray[i])));
    }
    
    printf("\n\n");
}

#pragma mark -
#pragma mark Private Implementations

void TENHumanAddChild(TENHuman *parent, TENHuman *child) {
    if (NULL != parent && NULL != child) {

        //        if (TENGenderMale == parent->_gender) {
        //            TENHumanHold(&child->_father, parent);
        //        } else {
        //            TENHumanHold(&child->_mother, parent);
        //        }
        
        
        TENHumanRemoveChild(child->_father, child);
        TENHumanRemoveChild(child->_mother, child);
        
        TENHumanSetChildAtIndex(parent, child, TENHumanGetChildrenCount(parent));
        
        
    }
}

void TENHumanRemoveChild(TENHuman *parent, TENHuman *child) {
    if (NULL != parent) {
        if (parent->_father == child) {
            TENHumanSetFather(child, NULL);
        } else {
            TENHumanSetMother(child, NULL);
        }
        
        
        int indexChild = TENHumanIndexChild(parent, child);
        
        TENHumanSetChildAtIndex(parent, NULL, indexChild);
        TENHumanRemoveElementFromChildArray(parent, indexChild);
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
