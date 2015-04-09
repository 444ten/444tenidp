//
//  TENObjCSyntax.m
//  HomeworkC
//
//  Created by 444ten on 4/9/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENObjCSyntax.h"

#pragma mark -
#pragma mark Private Declarations

static
void TENObjCLiterarls();

static
void TENObjCTollFreeBridging();

#pragma mark -
#pragma mark Public Implementations

void TENObjCSyntax() {
    TENObjCLiterarls();
    TENObjCTollFreeBridging();
}

#pragma mark -
#pragma mark Private Declarations

void TENObjCLiterarls() {
    NSNumber *number = @(42.1);
    NSLog(@"number literal = %@, class = %@", number, [number class]);
    
    NSArray *array = @[number, @(42), @(42.2)];
    NSLog(@"array literal = %@, class = %@, %@", array, [array class], array[2]);
    
    NSString *string = @"mama";
    NSLog(@"string literal = %@, class = %@", string, [string class]);
    
    NSDictionary *dictionary = @{string : number, @"papa" :@(45)};
    NSLog(@"dictionary literal = %@, class = %@", dictionary, [dictionary class]);
    NSLog(@"all keys = %@", [dictionary allKeys]);
    NSLog(@"all values = %@", [dictionary allValues]);
}

void TENObjCTollFreeBridging() {
//    CFStringRef stringRef = (CFStringRef)[[NSString alloc] initWithString: @"toll free"];
}
