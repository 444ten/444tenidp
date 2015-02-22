//
//  output.c
//  lesson1
//
//  Created by 444ten on 2/10/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdio.h>
#include "TENOutputParent.h"

#pragma mark -
#pragma mark Public Implementations

TENResult TENSayParent(int value) {
    TENResult result = TENResultNone;
    const int divisorMama = 3;
    const int divisorPapa = 5;

    printf("%4d ", value);
    
    if (0 == (value % divisorMama)) {
        printf("mama");
        result += TENResultMama;
    }
    
    if (0 == (value % divisorPapa)) {
        printf("papa");
        result += TENResultPapa;
    }
    
    printf("\n");
    
    return result;
}

void TENOutputParentFromStartToEnd(int startValue, int endValue) {
    for (int i = startValue; i <= endValue; i++) {
        TENSayParent(i);
    }
}
