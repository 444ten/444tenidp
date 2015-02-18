//
//  TENString.c
//  HomeworkC
//
//  Created by 444ten on 2/18/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <string.h>

#include "TENString.h"

struct TENString {
    char *_data;
    uint64_t _length;
    
    uint64_t _referenceCount;
};

#pragma mark -
#pragma mark Private Declarations

static
void TENStringDealloc(TENString *string);

#pragma mark -
#pragma mark Public Implementations

TENString *TENStringCreate(char *source) {
    TENString *string = malloc(sizeof(*string));
    
    TENStringSetData(string, source);

    string->_referenceCount = 1;
    
    return string;
}

void TENStringRetain(TENString *string) {
    string->_referenceCount += 1;
}

void TENStringRelease(TENString *string) {
    string->_referenceCount -= 1;
    
    if (0 == string->_referenceCount) {
        TENStringDealloc(string);
    }
}

void TENStringSetLength(TENString *string, uint64_t length) {
    if (string->_length != length) {
        string->_data = realloc(string->_data, length * sizeof(*string->_data));
        memset(string->_data + string->_length, 0, length - string->_length);
        
        string->_length = length;
    }
}

char *TENStringGetData(TENString *string) {
    return string->_data;
}

void TENStringSetData(TENString *string, char *newString) {
    TENStringSetLength(string, strlen(newString));
    strcpy(string->_data, newString);
}

#pragma mark -
#pragma mark Private Implementations

void TENStringDealloc(TENString *string) {
    if (NULL != string->_data) {
        free(string->_data);
    }
    free(string);
}
