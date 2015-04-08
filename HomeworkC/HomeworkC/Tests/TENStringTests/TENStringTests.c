//
//  TENStringTests.c
//  HomeworkC
//
//  Created by 444ten on 3/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <assert.h>
#include <string.h>

#include "TENString.h"
#include "TENStringTests.h"

#pragma mark -
#pragma mark Private Declarations


#pragma mark -
#pragma mark Public Implementations

void TENStringPerformTest() {
    char *name = "mama";
    
    //TENString
    //  after being created with name
    TENString *string = TENStringCreateWithData(name);

    //      string length should equal 5;
    assert(5 == string->_length);
    
    //      pointer of data shouldn't equal pointer of name
    assert(string->_data != name);
    
    //      string data should equal name
    assert(strcmp(string->_data, name) == 0);
    
    //  after string set data "mamapapa"
    TENStringSetData(string, "mamapapa");
    
    //      length should equal 9
    assert(9 == string->_length);
    
    //      string data should equal "mamapapa"
    assert(strcmp(string->_data, "mamapapa") == 0);
    
    //  after string set data ""
    TENStringSetData(string, "");
    
    //      length should equal 1
    assert(1 == string->_length);

    //      string data should equal ""
    assert(strcmp(string->_data, "") == 0);
    
    //  after string set data NULL
    TENStringSetData(string, NULL);
    
    //      length should equal 0
    assert(0 == string->_length);
    
    //      string data should equal NULL
    assert(NULL == string->_data);
    
    TENObjectRelease(string);
}

#pragma mark -
#pragma mark Private Implementations
