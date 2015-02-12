//
//  output.c
//  lesson1
//
//  Created by 444ten on 2/10/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdio.h>
#include "output.h"

int sayParent(int value) {
    static int divisor_mama     =  3;
    static int divisor_papa     =  5;
    static int divisor_mamapapa = 15;
    
    if ( value % divisor_mamapapa == 0 ) {
        printf("%d mamapapa\n", value);
        return result_mamapapa;
    }
    if ( value % divisor_mama     == 0 ) {
        printf("%d mama\n",     value);
        return result_mama;
    }
    if ( value % divisor_papa     == 0 ) {
        printf("%d papa\n",     value);
        return result_papa;
    }
    return result_zero;
}
