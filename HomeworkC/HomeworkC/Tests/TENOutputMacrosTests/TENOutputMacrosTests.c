//
//  TENOutputMacrosTests.c
//  HomeworkC
//
//  Created by 444ten on 2/22/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdio.h>
#include "TENOutputMacros.h"
#include "TENOutputMacrosTests.h"

TENOutputValueGenerate(int, d)
TENOutputValueGenerate(float, 5.2f)
TENOutputValueGenerate(char, c)

void TENOutputMacrosPerformTests() {
    TENOutputValue(int, 65)
    TENOutputValue(float, 65)
    TENOutputValue(char, 65)
    
}
