//
//  NSStringTests.m
//  HomeworkC
//
//  Created by 444ten on 4/20/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "NSStringTests.h"

#import "NSString+TENExtensions.h"

@implementation NSStringTests

- (void)performTests {
    NSLog(@"%@ run...", [self className]);
    
    NSLog(@"%@", [NSString alphanumericAlphabet]);
    NSLog(@"%@", [NSString alphabetWithCharacterSet:[NSCharacterSet punctuationCharacterSet]]);
    NSLog(@"%@", [NSString alphabetWithASCIIRange:NSMakeRange('0', '9' - '0' + 1)
                                     characterSet:[NSCharacterSet alphanumericCharacterSet]]);
    NSLog(@"%@", [NSString alphabetWithASCIIRange:NSMakeRange('a', 'z' - 'a' + 1)
                                     characterSet:[NSCharacterSet alphanumericCharacterSet]]);

    
//    for (NSUInteger i = 0; i < 20; i++) {
//        NSLog(@"%@", [NSString randomString]);
//    }
    
    
}

@end
