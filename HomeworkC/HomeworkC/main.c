//
//  main.c
//  HomeworkC
//
//  Created by 444ten on 2/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include "output.h"
#include "testOutput.h"

#include "TENStructTest.h"

int main(int argc, const char * argv[]) {
    int value_start =    1;
    int value_end   = 1000;
    
    testDivisorMama();
    testDivisorPapa();
    testDivisorMamapapa();
    testDivisorZero();
    
    for ( int i = value_start; i <= value_end; i++ ) {
        sayParent(i);
    }

    TENStructPerformTest();

    return 0;
}
