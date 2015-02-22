//
//  TENCharBit.c
//  charToBin
//
//  Created by 444ten on 2/12/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdio.h>
#include "TENCharBit.h"

#pragma mark -
#pragma mark Public Implementations

void TENCharBitOutput(char charValue) {
    short upperBit = sizeof(charValue) * 8 - 1;

    for (short currentBit = upperBit; currentBit >= 0; currentBit--) {
        if (3 == currentBit) {
            printf("'");
        }
        
        printf("%d", (charValue >> currentBit) & 1);
    }
}
