//
//  TENCharToBin.c
//  charToBin
//
//  Created by 444ten on 2/12/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

// Создать метод для вывода битов числа в консоль и протестировать его.

#include <stdio.h>
#include "TENCharToBin.h"

#pragma mark - Public Implementations

void TENCharToBinOut(char valueChar) {
    int upperBit = sizeof(valueChar) * 8 - 1;
    
    printf("symbol '%c' = ", valueChar);
    for (int i = upperBit; i >= 0; i--) {
        printf("%d", (valueChar >> i) & 1);
    }
    printf("\n");
}

