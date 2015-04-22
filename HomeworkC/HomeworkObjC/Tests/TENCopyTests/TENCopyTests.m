//
//  TENCopyTests.m
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENCopyTests.h"

#import "TENCopy.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

void TENCopyPerformTests() {    
    NSMutableString *nameString = [NSMutableString stringWithString:@"nnn"];
    TENCopy *object = [TENCopy objectWithName:nameString];
    
    NSLog(@"%@", object);
    
    [nameString appendString:@"bbb"];
    
    NSLog(@"%@", object);
    
    NSMutableString *aString = [object backDoorGetter];
    
    NSLog(@"aString - %@", aString);
//    aString =@"ccc";

    NSLog(@"%@", object);
    
}

#pragma mark -
#pragma mark Private Implementations
