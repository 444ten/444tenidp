//
//  TENStructTest.c
//  Structure
//
//  Created by 444ten on 2/12/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

//Требования:
//- создать тестовый метод, который бы с помощью offsetof выводил расположение каждого из элементов;
//- создать тестовый метод, который бы выводил размер всей структуры;
//- перекомпоновать структуру так, чтобы она занимала наименьшее количество места;
//- поместить bool значения в битовое поле и создать union;

#include <stdio.h>
#include <stddef.h>
#include "TENStructTest.h"
#include "TENStruct.h"

#pragma mark - Private Definitions

static
void TENPaddingStructOffsetTest();

static
void TENPaddingStructSizeTest();

static
void TENOptimalStructSizeTest();

static
void TENBitFieldStructSizeTest();

#pragma mark - Public Implementations

void TENStructPerformTest() {
    TENPaddingStructOffsetTest();
    TENPaddingStructSizeTest();
    TENOptimalStructSizeTest();
    TENBitFieldStructSizeTest();

}

#pragma mark - Private Implementations

void TENPaddingStructOffsetTest() {
    printf("offset intValue = %lu\n", offsetof(TENPaddingStruct, intValue));
    printf("offset stringRef = %lu\n", offsetof(TENPaddingStruct, stringRef));
//    printf("offset  = %lu\n", offsetof(TENOptimalStruct, shortValue3));
//    printf("offset  = %lu\n", offsetof(TENOptimalStruct, boolValue6));

}

void TENPaddingStructSizeTest() {
    printf("size of PaddingStruct = %lu\n", sizeof(TENPaddingStruct));
}

void TENOptimalStructSizeTest() {
    printf("size of OptimalStruct = %lu\n", sizeof(TENOptimalStruct));
}

void TENBitFieldStructSizeTest() {
    TENBitFieldStruct structure = {1, 2 , "aa", 4 , 5 , 6 , 7 , 0 , 1, 1};
    
    printf("flag = %d\n", structure.flag);
    printf("size of BitFieldStruct = %lu\n", sizeof(TENBitFieldStruct));
}
