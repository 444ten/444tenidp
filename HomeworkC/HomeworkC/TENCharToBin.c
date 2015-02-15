//
//  TENCharToBin.c
//  charToBin
//
//  Created by 444ten on 2/12/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdio.h>
#include "TENCharToBin.h"

#pragma mark -
#pragma mark Private Defenitions

void TENCharToBinOut(char valueChar);

#pragma mark -
#pragma mark Public Implementations

void TENCharToBinOutPerformTest() {
    TENCharToBinOut('\0');
    TENCharToBinOut(1);
    TENCharToBinOut('A');
}

#pragma mark -
#pragma mark Private Implementations

void TENCharToBinOut(char valueChar) {
    int upperBit = sizeof(valueChar) * 8 - 1;
    
    printf("symbol '%c' = ", valueChar);
    
    for (int currentBit = upperBit; currentBit >= 0; currentBit--) {
        printf("%d", (valueChar >> currentBit) & 1);
    }
    
    printf("\n");
}
