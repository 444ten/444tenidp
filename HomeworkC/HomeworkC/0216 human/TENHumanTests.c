//
//  TENHumanTests.c
//  HomeworkC
//
//  Created by 444ten on 2/17/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdlib.h>

#include "TENHuman.h"
#include "TENHumanTests.h"
#include "TENObject.h"
#include "TENString.h"

void TENHumanDoubleRefTest() {
    TENHuman *adam = TENHumanCreateWithParam("Adam", TENGenderMale, NULL, NULL);
    TENHuman *eva = TENHumanCreateWithParam("Eva", TENGenderFemale, NULL, NULL);
    TENHuman *cain = TENHumanCreateWithParam("Cain", TENGenderMale, adam, eva);
    TENHuman *mary = TENHumanCreateWithParam("Mary", TENGenderFemale, adam, eva);
    TENHuman *alcmene = TENHumanCreateWithParam("Alcmene", TENGenderFemale, adam, eva);
    TENHuman *heracles =TENHumanCreateWithParam("Heracles", TENGenderMale, NULL, alcmene);
    TENHuman *petr = TENHumanCreateWithParam("Petr", TENGenderMale, cain, mary);
    TENHuman *pavl = TENHumanCreateWithParam("Pavl", TENGenderMale, cain, mary);
    TENHuman *ivan = TENHumanCreateWithParam("Ivan", TENGenderMale, cain, mary);
    
    TENHumanMarry(cain, mary);
    TENHumanMarry(adam, eva);
    
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(cain);
    TENHumanPrint(mary);
    TENHumanPrint(alcmene);
    TENHumanPrint(heracles);
    
    TENHumanClear(mary);
    TENHumanPrint(mary);
    
    TENHumanRename(adam, "AdamKozlevich");
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(cain);
    TENHumanPrint(petr);
    TENHumanPrint(pavl);
    TENHumanPrint(ivan);
}

void TENHumanPartnerSetterTest() {
    TENHuman *adam = TENHumanCreateWithParam("Adam", TENGenderMale, NULL, NULL);
    TENHuman *eva = TENHumanCreateWithParam("Eva", TENGenderFemale, NULL, NULL);
    TENHuman *alcmene = TENHumanCreateWithParam("Alcmene", TENGenderFemale, NULL, NULL);
    
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(alcmene);
    
    TENHumanMarry(NULL, adam);
    
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(alcmene);
    
    TENHumanMarry(adam, alcmene);
    
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(alcmene);
}

void TENObjectTest() {
//    TENString *string = __TENObjectCreate(sizeof(TENString), (TENDeallocateCallBack)&__TENStringDeallocate);
    
    TENString *string = TenObjectCreate(TENString);


    TENStringSetData(string, "Hello");
    TENObjectRelease(TENObjectRetain(string));
    TENObjectRelease(string);
    
}

void TENHumanPerformTests() {
//    TENHumanDoubleRefTest();
//    TENHumanPartnerSetterTest();
    TENObjectTest();

}

