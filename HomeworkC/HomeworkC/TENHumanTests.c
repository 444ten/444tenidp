//
//  TENHumanTests.c
//  HomeworkC
//
//  Created by 444ten on 2/17/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>

#include "TENHuman.h"
#include "TENHumanTests.h"

void TENHumanPerformTests() {

    TENHuman *adam = TENHumanCreate("Adam", TENGenderMale, NULL, NULL);
    TENHuman *eva = TENHumanCreate("Eva", TENGenderFemale, NULL, NULL);
    TENHuman *cain = TENHumanCreate("Cain", TENGenderMale, adam, eva);

    TENHumanPrint(adam);
    TENHumanPrint(eva);
    TENHumanPrint(cain);
    

    TENHumanMarry(adam, eva);
    
    TENHumanPrint(adam);
    TENHumanPrint(eva);
    
    TENHumanDivorce(adam);

    TENHumanPrint(adam);
    TENHumanPrint(eva);
    
}
