//
//  TENValueBitOutput.c
//  HomeworkC
//
//  Created by 444ten on 2/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include "TENValueBitOutput.h"

void TENValueBitOutput(void *valueRef, long size) {
    char *charValueRef = (char *)valueRef;
    long upperByte = size - 1;
    
    for (long currentByte = upperByte; currentByte >= 0; currentByte--) {
        long index = TENLittleEndianOrder() ? currentByte : upperByte - currentByte;
        char charValue = charValueRef[index];
        
        for (int currentBit = 7; currentBit >= 0; currentBit--) {
            if (3 == currentBit) {
                printf("'");
            }
            printf("%d", (charValue >> currentBit) & 1);
        }
        
        if (0 == currentByte) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
}

bool TENLittleEndianOrder() {
    unsigned short shortValue = 1;
    char *charValueRef = (char *)&shortValue;
    
    return charValueRef[0];
}
