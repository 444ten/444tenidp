//
//  testOutput.c
//  lesson1
//
//  Created by 444ten on 2/10/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>
#include <stdio.h>
#include "TENOutputParent.h"
#include "TENOutputParentTest.h"

#pragma mark -
#pragma mark Private Definitions

void TENDivisorNoneTest();
void TENDivisorMamaTest();
void TENDivisorPapaTest();
void TENDivisorMamaPapaTest();

#pragma mark -
#pragma mark Public Implementations

void TENOutputParentPerformTest() {
    TENDivisorMamaTest();
    TENDivisorPapaTest();
    TENDivisorMamaPapaTest();
    TENDivisorNoneTest();
}

#pragma mark -
#pragma mark Private Implementations

void TENDivisorNoneTest() {
    int valueCorrect1 = -43;
    int valueCorrect2 = -11;
    int valueCorrect3 =   1;
    int valueCorrect4 =  52;
    
    int valueInvalid1 = -45;
    int valueInvalid2 =   0;
    int valueInvalid3 =  10;
    int valueInvalid4 =  12;
    
    printf("*** start TENDivisorNoneTest ***\n");
    
    assert(TENSayParent(valueCorrect1) == TENResultNone);
    assert(TENSayParent(valueCorrect2) == TENResultNone);
    assert(TENSayParent(valueCorrect3) == TENResultNone);
    assert(TENSayParent(valueCorrect4) == TENResultNone);
    
    assert(TENSayParent(valueInvalid1) != TENResultNone);
    assert(TENSayParent(valueInvalid2) != TENResultNone);
    assert(TENSayParent(valueInvalid3) != TENResultNone);
    assert(TENSayParent(valueInvalid4) != TENResultNone);
    
    printf("*** end TENDivisorNoneTest ***\n\n");
}

void TENDivisorMamaTest() {
    int valueCorrect1 = -12;
    int valueCorrect2 =  -6;
    int valueCorrect3 =   3;
    int valueCorrect4 =  42;

    int valueInvalid1 = -43;
    int valueInvalid2 =   0;
    int valueInvalid3 =   2;
    int valueInvalid4 =  45;

    printf("*** start TENDivisorMamaTest ***\n");
    
    assert(TENSayParent(valueCorrect1) == TENResultMama);
    assert(TENSayParent(valueCorrect2) == TENResultMama);
    assert(TENSayParent(valueCorrect3) == TENResultMama);
    assert(TENSayParent(valueCorrect4) == TENResultMama);
    
    assert(TENSayParent(valueInvalid1) != TENResultMama);
    assert(TENSayParent(valueInvalid2) != TENResultMama);
    assert(TENSayParent(valueInvalid3) != TENResultMama);
    assert(TENSayParent(valueInvalid4) != TENResultMama);
    
    printf("*** end TENDivisorMamaTest ***\n\n");
}

void TENDivisorPapaTest() {
    int valueCorrect1 = -100;
    int valueCorrect2 =   -5;
    int valueCorrect3 =   20;
    int valueCorrect4 =  400;
    
    int valueInvalid1 = -43;
    int valueInvalid2 =   0;
    int valueInvalid3 =   2;
    int valueInvalid4 =  45;

    printf("*** start TENDivisorPapaTest ***\n");
    
    assert(TENSayParent(valueCorrect1) == TENResultPapa);
    assert(TENSayParent(valueCorrect2) == TENResultPapa);
    assert(TENSayParent(valueCorrect3) == TENResultPapa);
    assert(TENSayParent(valueCorrect4) == TENResultPapa);
    
    assert(TENSayParent(valueInvalid1) != TENResultPapa);
    assert(TENSayParent(valueInvalid2) != TENResultPapa);
    assert(TENSayParent(valueInvalid3) != TENResultPapa);
    assert(TENSayParent(valueInvalid4) != TENResultPapa);
    
    printf("*** end TENDivisorPapaTest ***\n\n");
}

void TENDivisorMamaPapaTest() {
    int valueCorrect1 = -45;
    int valueCorrect2 =   0;
    int valueCorrect3 =  15;
    int valueCorrect4 = 900;
    
    int valueInvalid1 = -43;
    int valueInvalid2 =   3;
    int valueInvalid3 =  10;
    int valueInvalid4 =  46;
    
    printf("*** start TENDivisorMamaPapaTest ***\n");
    
    assert(TENSayParent(valueCorrect1) == TENResultMamaPapa);
    assert(TENSayParent(valueCorrect2) == TENResultMamaPapa);
    assert(TENSayParent(valueCorrect3) == TENResultMamaPapa);
    assert(TENSayParent(valueCorrect4) == TENResultMamaPapa);
    
    assert(TENSayParent(valueInvalid1) != TENResultMamaPapa);
    assert(TENSayParent(valueInvalid2) != TENResultMamaPapa);
    assert(TENSayParent(valueInvalid3) != TENResultMamaPapa);
    assert(TENSayParent(valueInvalid4) != TENResultMamaPapa);
    
    printf("*** end TENDivisorMamaPapaTest ***\n\n");
}
