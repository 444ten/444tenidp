//
//  TENString.c
//  HomeworkC
//
//  Created by 444ten on 2/18/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <string.h>

#include "TENString.h"

#pragma mark -
#pragma mark Public Implementations

void __TENStringDeallocate(TENString *string) {
    if (NULL != string->_data) {
        free(string->_data);
        string->_data = NULL;
    }
    
    __TENObjectDeallocate(string);
}

void TENStringSetData(TENString *string, char *newString) {
    if (NULL != string) {
        if (NULL != string->_data) {
            free(string->_data);
            string->_data = NULL;
        }
        
        if (NULL != newString) {
            TENStringSetLength(string, strlen(newString));
            strcpy(string->_data, newString);
        }
    }
}

char *TENStringGetData(TENString *string) {
    return (NULL != string) ? string->_data : NULL;
}

void TENStringSetLength(TENString *string, uint64_t length) {
    if (string->_length != length) {
        string->_data = realloc(string->_data, length * sizeof(*string->_data));
        
        if (string->_length < length) {
            memset(string->_data + string->_length, 0, length - string->_length);
        }
        
        string->_length = length;
    }
}
