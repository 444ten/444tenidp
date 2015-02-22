//
//  TENValueBitOutputTest.c
//  HomeworkC
//
//  Created by 444ten on 2/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>
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
    
    printf("is LittleEndianOrder? - %s\n", TENLittleEndian == TENEndianDetect() ? "Yes" : "No");
    
    const int resultFourBytes = 1 + (3 << 8) + (7 << 16);
    const int resultFourBytesConvert = (1 << 24) + (3 << 16) + (7 << 8);
    const int resultThreeBytesConvert = (1 << 16) + (3 << 8) + 7;
    int value;
    
    value = resultFourBytes;
    TENEndianConvert(&value, 4, TENEndianDetect());
    assert(value == resultFourBytes);
    
    value = resultFourBytes;
    TENEndianConvert(&value, 4, !TENEndianDetect());
    assert(value == resultFourBytesConvert);
    
    value = resultFourBytes;
    TENEndianConvert(&value, 3, !TENEndianDetect());
    assert(value == resultThreeBytesConvert);

}
