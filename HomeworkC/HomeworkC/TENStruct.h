//
//  TENStruct.h
//  Structure
//
//  Created by 444ten on 2/12/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __Structure__TENStruct__
#define __Structure__TENStruct__

#include <stdbool.h>

struct TENPaddingStruct {
    bool boolValue1;
    long long longLongValue;
    int intValue;
    bool boolValue2;
    short shortValue1;
    bool boolValue3;
    bool boolValue4;
    char *stringRef;
    bool boolValue5;
    bool boolValue6;
    double doubleValue;
    short shortValue2;
    float floatValue;
    short shortValue3;
};
typedef struct TENPaddingStruct TENPaddingStruct;

struct TENOptimalStruct {
    long long longLongValue;
    double doubleValue;
    char *stringRef;
    int intValue;
    float floatValue;
    short shortValue1;
    short shortValue2;
    short shortValue3;
    bool boolValue1;
    bool boolValue2;
    bool boolValue3;
    bool boolValue4;
    bool boolValue5;
    bool boolValue6;
};
typedef struct TENOptimalStruct TENOptimalStruct;

struct TENBitFieldStruct {
    long long longLongValue;
    double doubleValue;
    char *stringRef;
    int intValue;
    float floatValue;
    short shortValue1;
    short shortValue2;
    short shortValue3;
    union {
        struct {
            bool boolValue1 : 1;
            bool boolValue2 : 1;
            bool boolValue3 : 1;
            bool boolValue4 : 1;
            bool boolValue5 : 1;
            bool boolValue6 : 1;
        };
        char flag;
    };
};
typedef struct TENBitFieldStruct TENBitFieldStruct;

#endif /* defined(__Structure__TENStruct__) */
