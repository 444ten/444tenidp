//
//  main.m
//  lesson1
//
//  Created by 444ten on 2/10/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include "output.h"
#include "testOutput.h"

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
    
    return 0;
}
