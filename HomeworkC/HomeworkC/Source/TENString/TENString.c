//
//  TENString.c
//  HomeworkC
//
//  Created by 444ten on 2/18/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>
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
    assert(NULL != string);
    
    if (NULL == data) {
        
        TENStringSetLength(string, 0);
    
    } else {

        TENStringSetLength(string, strlen(data) + 1);
        strcpy(string->_data, data);
        
    }
}

char *TENStringGetData(TENString *string) {
    return (NULL != string) ? string->_data : NULL;
}

#pragma mark -
#pragma mark Private Implementations

void TENStringSetLength(TENString *string, uint64_t length) {
    assert(NULL != string);

    if (length == string->_length) {
        return;
    }
    
    string->_length = length;

    if (0 == string->_length) {

        if (NULL != string->_data) {
            free(string->_data);
            string->_data = NULL;
        }
        
    } else {
        
        string->_data = realloc(string->_data, string->_length * sizeof(*string->_data));
        assert(NULL != string->_data);
        
    }
}
