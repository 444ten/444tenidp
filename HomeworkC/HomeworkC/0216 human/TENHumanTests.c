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
    TENHuman *adam = TENObjectCreate(TENHuman);
    TENHuman *eva = TENObjectCreate(TENHuman);
    TENHuman *kain = TENObjectCreate(TENHuman);
    
    TENString *string = TENObjectCreate(TENString);

    TENStringSetData(string, "adam");
    TENHumanSetName(adam, string);
    
    TENStringSetData(string, "Eva");
    TENHumanSetName(eva, string);

    TENStringSetData(string, "Kain");
    TENHumanSetName(kain, string);
    
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
    TENHuman *adam = TENObjectCreate(TENHuman);
    TENHuman *eva = TENObjectCreate(TENHuman);
    TENHuman *kain = TENObjectCreate(TENHuman);
    TENHuman *avel = TENObjectCreate(TENHuman);
    
    TENString *string = TENObjectCreate(TENString);
    
    TENStringSetData(string, "adam");
    TENHumanSetName(adam, string);
    TENHumanSetGender(adam, TENGenderMale);
    
    TENStringSetData(string, "Eva");
    TENHumanSetName(eva, string);
    
    TENStringSetData(string, "Kain");
    TENHumanSetName(kain, string);
    TENHumanSetGender(kain, TENGenderMale);

    TENStringSetData(string, "Avel");
    TENHumanSetName(avel, string);
    TENHumanSetGender(avel, TENGenderMale);
    
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

void TENHumanPerformTests() {
//    TENObjectTest();
    TENChildArrayTest();
//    TENHumanChildTest();
}
