//
//  TENHumanTests.c
//  HomeworkC
//
//  Created by 444ten on 2/17/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "TENChildArray.h"
#include "TENHuman.h"
#include "TENHumanTests.h"
#include "TENObject.h"
#include "TENString.h"

void TENObjectTest() {
    TENHuman *adam = TENObjectCreate(TENHuman);
    TENHuman *eva = TENObjectCreate(TENHuman);
    
    TENString *string = TENObjectCreate(TENString);
    TENStringSetData(string, "adam");
    
    TENHumanSetName(adam, string);
    TENHumanPrint(adam);
    
    TENStringSetData(string, "Eva");
    
    TENHumanSetName(eva, string);
    TENHumanPrint(adam);
    TENHumanPrint(eva);
}

void TENChildArrayTest() {
    TENHuman *adam = TENHumanCreateWithNameGender("Adam", TENGenderMale);
    TENHuman *eva = TENHumanCreateWithNameGender("Eva", TENGenderMale);
    TENHuman *kain = TENHumanCreateWithNameGender("Kain", TENGenderMale);
    
    TENChildArray *godArray = TENObjectCreate(TENChildArray);
    
    TENChildArrayAddObject(godArray, adam);
//    TENChildArrayAddObject(godArray, eva);
    TENChildArrayAddObject(godArray, kain);
    
    TENHumanChildArrayPrint(godArray);
    printf("\n");
    
    
    uint8_t index = TENChildArrayIndexOfObject(godArray, eva);
    TENChildArrayRemoveObjectAtIndex(godArray, index);
    
    TENObjectRelease(godArray);
}

void TENHumanChildTest() {
    TENHuman *adam = TENHumanCreateWithNameGender("Adam", TENGenderMale);
    TENHuman *eva = TENHumanCreateWithNameGender("Eva", TENGenderMale);
    TENHuman *kain = TENHumanCreateWithNameGender("Kain", TENGenderMale);
    TENHuman *avel = TENHumanCreateWithNameGender("Avel", TENGenderMale);
    
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(kain);
    TENHumanPrint(avel);
    
    TENHumanAddChild(adam, kain);
    TENHumanAddChild(eva, kain);
    TENHumanAddChild(adam, avel);
    TENHumanAddChild(eva, avel);
    
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(kain);
    TENHumanPrint(avel);
    
    TENHumanRemoveChild(adam, kain);
    TENHumanRemoveChild(eva, avel);
    
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(kain);
    TENHumanPrint(avel);
}

void TENHumanPartnerTest() {
    TENHuman *adam = TENHumanCreateWithNameGender("Adam", TENGenderMale);
    TENHuman *eva = TENHumanCreateWithNameGender("Eva", TENGenderMale);
    TENHuman *kain = TENHumanCreateWithNameGender("Kain", TENGenderMale);
    TENHuman *avel = TENHumanCreateWithNameGender("Avel", TENGenderMale);
    
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(kain);
    TENHumanPrint(avel);
    
    TENHumanMarry(adam, eva);
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(kain);
    TENHumanPrint(avel);

    TENHumanMarry(avel, eva);
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(kain);
    TENHumanPrint(avel);
    
}

void TENHumanSetNameTest() {
    TENHuman *adam = TENObjectCreate(TENHuman);
    TENHuman *eva = TENObjectCreate(TENHuman);
    
    TENHumanPrint(adam);

    TENString *string = TENObjectCreate(TENString);
    TENStringSetData(string, "adam");
    
    TENHumanSetName(NULL, string); // NULL - noNULL
    
    TENHumanSetName(adam, string);
    TENHumanPrint(adam);

    TENHumanSetName(adam, string); // same string
    
    TENStringSetData(string, "eva"); // change TENString
    TENHumanPrint(adam);
    
    TENHumanSetName(eva, string); // retain another Human
    TENHumanPrint(eva);

    TENHumanSetName(adam, NULL);
    TENHumanSetName(eva, NULL);
   
}

void TENHumanPerformTests() {
//    TENObjectTest();
//    TENChildArrayTest();
    TENHumanChildTest();
//    TENHumanPartnerTest();
//    TENHumanSetNameTest();
    
    
}
