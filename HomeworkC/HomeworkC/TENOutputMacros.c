//
//  TENOutputMacrosTest.c
//  HomeworkC
//
//  Created by 444ten on 2/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdio.h>

#include "TENOutputMacros.h"

#define TENOutputValueGenerate(type, specifier) \
    void TENOutput_##type(type value) {         \
        printf("("#type") %"#specifier"\n", value);       \
    }

#define TENOutputValue(type, value) \
    TENOutput_##type(value);

TENOutputValueGenerate(int, d)
TENOutputValueGenerate(float, 5.2f)
TENOutputValueGenerate(char, c)

void TENOutputMacrosPerformTest() {
    TENOutputValue(int, 65)
    TENOutputValue(float, 65)
    TENOutputValue(char, 65)
}
