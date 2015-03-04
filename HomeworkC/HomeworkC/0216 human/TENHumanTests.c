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

void TENChildArrayTest() {
    TENHuman *adam = TENHumanCreateWithNameGender("Adam", TENGenderMale);
    TENHuman *eva = TENHumanCreateWithNameGender("Eva", TENGenderMale);
    TENHuman *kain = TENHumanCreateWithNameGender("Kain", TENGenderMale);
    
    TENChildArray *godArray = TENObjectCreate(TENChildArray);
    
    TENChildArrayAddObject(godArray, adam);
    TENChildArrayAddObject(godArray, eva);
    TENChildArrayAddObject(godArray, kain);
    
    TENHumanChildArrayPrint(godArray);
    printf("\n");
    
    
    uint8_t index = TENChildArrayIndexOfObject(godArray, eva);
    TENChildArrayRemoveObjectAtIndex(godArray, index);
    
    
}

void TENHumanChildTest() {
    TENHuman *adam = TENHumanMaleCreateWithName("adam");
    TENHuman *eva = TENHumanFemaleCreateWithName("Eva");
    TENHuman *kain = TENHumanMaleCreateWithName("Kain");
    TENHuman *avel = TENHumanMaleCreateWithName("Avel");
    
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
    TENHuman *adam = TENHumanMaleCreateWithName("adam");
    TENHuman *eva = TENHumanFemaleCreateWithName("Eva");
    TENHuman *kain = TENHumanMaleCreateWithName("Kain");
    TENHuman *avel = TENHumanMaleCreateWithName("Avel");
    
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


void TENHumanPerformTests() {
//    TENChildArrayTest();
    TENHumanChildTest();
//    TENHumanPartnerTest();
    
    
}
