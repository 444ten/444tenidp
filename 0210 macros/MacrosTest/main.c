//
//  main.c
//  MacrosTest
//
//  Created by 444ten on 2/11/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include <stdio.h>

#define TENOutputValueGenerate(type, specifier) \
    void TENOutput_##type(type value) {         \
        printf("%"#specifier"\n", value);       \
    }

#define TENOutputValue(type, value) \
    TENOutput_##type(value);

TENOutputValueGenerate(int, d)
TENOutputValueGenerate(float, 5.2f)
TENOutputValueGenerate(char, c)

int main(int argc, const char * argv[]) {
    
//    TENOutput_int(42);
//    TENOutput_float(42);
//    TENOutput_char(42);
    
    TENOutputValue(int, 45);
    TENOutputValue(int, 45);

    return 0;
}
