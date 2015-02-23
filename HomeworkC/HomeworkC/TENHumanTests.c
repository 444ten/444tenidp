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

void TENHumanPerformTests() {

    TENHuman *adam = TENHumanCreate("Adam", TENGenderMale, NULL, NULL);
    TENHuman *eva = TENHumanCreate("Eva", TENGenderFemale, NULL, NULL);
    TENHuman *cain = TENHumanCreate("Cain", TENGenderMale, adam, eva);
    TENHuman *mary = TENHumanCreate("Mary", TENGenderFemale, adam, eva);
    TENHuman *alcmene = TENHumanCreate("Alcmene", TENGenderFemale, adam, eva);
    TENHuman *heracles =TENHumanCreate("Heracles", TENGenderMale, NULL, alcmene);
    TENHuman *petr = TENHumanCreate("Petr", TENGenderMale, cain, mary);
    TENHuman *pavl = TENHumanCreate("Pavl", TENGenderMale, cain, mary);
    TENHuman *ivan = TENHumanCreate("Ivan", TENGenderMale, cain, mary);
    
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
//
    TENHumanRename(adam, "AdamKozlevich");
    TENHumanPrint(adam);
//    TENHumanPrint(eva);
    TENHumanPrint(cain);
//    TENHumanPrint(petr);
//    TENHumanPrint(pavl);
//    TENHumanPrint(ivan);
    
}
