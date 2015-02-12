//
//  testOutput.c
//  lesson1
//
//  Created by 444ten on 2/10/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>
#include "testOutput.h"
#include "output.h"

void testDivisorMama() {
    int value_correct1 = -12;
    int value_correct2 =  -6;
    int value_correct3 =   3;
    int value_correct4 =  42;

    int value_invalid1 = -43;
    int value_invalid2 =   0;
    int value_invalid3 =   2;
    int value_invalid4 =  45;

    assert(sayParent(value_correct1) == result_mama);
    assert(sayParent(value_correct2) == result_mama);
    assert(sayParent(value_correct3) == result_mama);
    assert(sayParent(value_correct4) == result_mama);
    
    assert(sayParent(value_invalid1) != result_mama);
    assert(sayParent(value_invalid2) != result_mama);
    assert(sayParent(value_invalid3) != result_mama);
    assert(sayParent(value_invalid4) != result_mama);
}

void testDivisorPapa() {
    int value_correct1 = -100;
    int value_correct2 =   -5;
    int value_correct3 =   20;
    int value_correct4 =  400;
    
    int value_invalid1 = -43;
    int value_invalid2 =   0;
    int value_invalid3 =   2;
    int value_invalid4 =  45;
    
    assert(sayParent(value_correct1) == result_papa);
    assert(sayParent(value_correct2) == result_papa);
    assert(sayParent(value_correct3) == result_papa);
    assert(sayParent(value_correct4) == result_papa);
    
    assert(sayParent(value_invalid1) != result_papa);
    assert(sayParent(value_invalid2) != result_papa);
    assert(sayParent(value_invalid3) != result_papa);
    assert(sayParent(value_invalid4) != result_papa);
}

void testDivisorMamapapa() {
    int value_correct1 = -45;
    int value_correct2 =   0;
    int value_correct3 =  15;
    int value_correct4 = 900;
    
    int value_invalid1 = -43;
    int value_invalid2 =   3;
    int value_invalid3 =  10;
    int value_invalid4 =  46;
    
    assert(sayParent(value_correct1) == result_mamapapa);
    assert(sayParent(value_correct2) == result_mamapapa);
    assert(sayParent(value_correct3) == result_mamapapa);
    assert(sayParent(value_correct4) == result_mamapapa);
    
    assert(sayParent(value_invalid1) != result_mamapapa);
    assert(sayParent(value_invalid2) != result_mamapapa);
    assert(sayParent(value_invalid3) != result_mamapapa);
    assert(sayParent(value_invalid4) != result_mamapapa);
}

void testDivisorZero() {
    int value_correct1 = -43;
    int value_correct2 = -11;
    int value_correct3 =   1;
    int value_correct4 =  52;
    
    int value_invalid1 = -45;
    int value_invalid2 =   0;
    int value_invalid3 =  10;
    int value_invalid4 =  12;
    
    assert(sayParent(value_correct1) == result_zero);
    assert(sayParent(value_correct2) == result_zero);
    assert(sayParent(value_correct3) == result_zero);
    assert(sayParent(value_correct4) == result_zero);

    assert(sayParent(value_invalid1) != result_zero);
    assert(sayParent(value_invalid2) != result_zero);
    assert(sayParent(value_invalid3) != result_zero);
    assert(sayParent(value_invalid4) != result_zero);
}

