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
    TENString *adamName = TENStringCreateWithData("Adam");
    TENString *evaName = TENStringCreateWithData("Eva");
    TENString *kainName = TENStringCreateWithData("Kain");
    TENString *avelName = TENStringCreateWithData("Avel");
    
    TENHuman *adam = TENHumanMaleCreateWithName(adamName);
    TENHuman *eva = TENHumanFemaleCreateWithName(evaName);
    TENHuman *kain = TENHumanMaleCreateWithName(kainName);
    
    TENRelease(adamName);
    TENRelease(evaName);
    TENRelease(kainName);
    TENRelease(avelName);
    
    TENChildArray *godArray = TENObjectCreate(TENChildArray);
    
    TENChildArrayAddObject(godArray, adam);
    TENChildArrayAddObject(godArray, eva);
    TENChildArrayAddObject(godArray, kain);
    
    TENChildArrayPrint(godArray);
    printf("\n");
    
    
    uint8_t index = TENChildArrayIndexOfObject(godArray, eva);
    TENChildArrayRemoveObjectAtIndex(godArray, index);
    
    
}

void TENHumanChildTest() {
    TENString *adamName = TENStringCreateWithData("Adam");
    TENString *evaName = TENStringCreateWithData("Eva");
    TENString *kainName = TENStringCreateWithData("Kain");
    TENString *avelName = TENStringCreateWithData("Avel");
    
    TENHuman *adam = TENHumanMaleCreateWithName(adamName);
    TENHuman *eva = TENHumanFemaleCreateWithName(evaName);
    TENHuman *kain = TENHumanMaleCreateWithName(kainName);
    TENHuman *avel = TENHumanMaleCreateWithName(avelName);
    
    TENRelease(adamName);
    TENRelease(evaName);
    TENRelease(kainName);
    TENRelease(avelName);
    
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
    TENString *adamName = TENStringCreateWithData("Adam");
    TENString *evaName = TENStringCreateWithData("Eva");
    TENString *kainName = TENStringCreateWithData("Kain");
    TENString *avelName = TENStringCreateWithData("Avel");
    
    TENHuman *adam = TENHumanMaleCreateWithName(adamName);
    TENHuman *eva = TENHumanFemaleCreateWithName(evaName);
//    TENHuman *kain = TENHumanMaleCreateWithName(kainName);
//    TENHuman *avel = TENHumanMaleCreateWithName(avelName);
    
    TENRelease(adamName);
    TENRelease(evaName);
    TENRelease(kainName);
    TENRelease(avelName);
    
    TENHumanPrint(adam);
    TENHumanPrint(eva);
//    TENHumanPrint(kain);
//    TENHumanPrint(avel);
    
    TENHumanMarry(adam, eva);
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    
//    TENRelease(eva);
//    TENHumanPrint(adam);
//    TENHumanPrint(eva);
    
//    TENRelease(adam);
//    TENRelease(adam);

//    TENHumanPrint(adam);
//    TENHumanPrint(eva);

//    TENHumanPrint(kain);
//    TENHumanPrint(avel);

//    TENHumanMarry(avel, eva);
//    TENHumanPrint(adam);
//    TENHumanPrint(eva);
//    TENHumanPrint(kain);
//    TENHumanPrint(avel);
//    
//    TENHumanMarry(kain, kain);
    
}


void TENHumanPerformTests() {
//    TENChildArrayTest();
//    TENHumanChildTest();
    TENHumanPartnerTest();
    
    
}
