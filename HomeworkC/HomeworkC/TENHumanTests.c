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

    TENPersonStruct *adam = TENPersonWasBorn("Adam", TENPersonGenderMale, NULL, NULL);
    TENPersonStruct *eva = TENPersonWasBorn("Eva", TENPersonGenderFemale, NULL, NULL);
    
    TENWeddingSangAndDanced(adam, eva);
    
    TENPersonProfileOutput(adam);
    TENPersonProfileOutput(eva);
}
