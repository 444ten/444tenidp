//
//  TENValueBitOutput.c
//  HomeworkC
//
//  Created by 444ten on 2/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdio.h>

#include "TENCharBit.h"
#include "TENValueBitOutput.h"

void TENValueBitOutput(void *valueRef, uint64_t size) {
    char *charValue = (char *)valueRef;
    uint64_t upperByte = size - 1;
    
    for (uint64_t currentByte = 0; currentByte <= upperByte; currentByte++) {
        uint64_t index = TENBigEndian == TENEndianDetect() ? currentByte : upperByte - currentByte;

        TENCharBitOutput(charValue[index]);
        
        printf("%s", currentByte < upperByte ? " " : "\n");
    }
}

TENEndian TENEndianDetect() {
    unsigned short shortValue = 1;
    
    return *(char *)&shortValue;
}

void TENEndianConvert(void *valueRef, uint64_t size, TENEndian endian) {
    if (endian != TENEndianDetect()) {
        char *charValue = (char *)valueRef;
        char charTemp;
        uint64_t upperByte = size - 1;
        uint64_t midpoint = size / 2;
        
        for (int i = 0; i < midpoint; i++) {
            charTemp = charValue[i];
            charValue[i] = charValue[upperByte-i];
            charValue[upperByte-i] = charTemp;
        }
    }
}
