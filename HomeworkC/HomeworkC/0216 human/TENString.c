//
//  TENString.c
//  HomeworkC
//
//  Created by 444ten on 2/18/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <string.h>

#include "TENProperty.h"
#include "TENString.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENStringSetLength(TENString *string, uint64_t length);

#pragma mark -
#pragma mark Public Implementations

TENString *TENStringCreateWithData(char *data) {
    TENString *string = TENObjectCreate(TENString);
    
    TENStringSetData(string, data);
    
    return string;
}

void __TENStringDeallocate(TENString *string) {
    TENStringSetData(string, NULL);
    __TENObjectDeallocate(string);
}

void TENStringSetData(TENString *string, char *data) {
    if (NULL != string) {
        if (NULL != string->_data) {
            free(string->_data);
            string->_data = NULL;
            string->_length = 0;
        }
        
        if (NULL != data) {
            TENStringSetLength(string, strlen(data) + 1);
            strcpy(string->_data, data);
        }
    }
}

char *TENStringGetData(TENString *string) {
    return (NULL != string) ? string->_data : NULL;
}

#pragma mark -
#pragma mark Private Implementations

void TENStringSetLength(TENString *string, uint64_t length) {
    if (string->_length != length) {
        string->_data = realloc(string->_data, length * sizeof(*string->_data));
        
        if (string->_length < length) {
            memset(string->_data + string->_length, 0, length - string->_length);
        }
        
        string->_length = length;
    }
}
