//
//  TENValueBitOutputTest.c
//  HomeworkC
//
//  Created by 444ten on 2/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include "TENValueBitOutputTest.h"
#include "TENValueBitOutput.h"

void TENValueBitOutputPerformTest() {
    int value1 = 1000;
    short value2 = 1;
    char value3 = '\0';
    char value4 = 'B';

    TENValueBitOutput(&value1, sizeof(value1));
    TENValueBitOutput(&value2, sizeof(value2));
    TENValueBitOutput(&value3, sizeof(value3));
    TENValueBitOutput(&value4, sizeof(value4));
    
    if (TENLittleEndianOrder()) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}
