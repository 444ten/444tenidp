//
//  NSString+TENExtensions.m
//  HomeworkC
//
//  Created by 444ten on 4/20/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "NSString+TENExtensions.h"

static const NSUInteger kNSStringRandomSrtingDefaultLength = 10;

@implementation NSString (TENExtensions)

+ (id)uppercaseLetterAlphabet {
    return [self alphabetWithCharacterSet:[NSCharacterSet uppercaseLetterCharacterSet]];
}

+ (id)lowercaseLetterAlphabet {
    return [self alphabetWithCharacterSet:[NSCharacterSet lowercaseLetterCharacterSet]];
}

+ (id)decimalDigitAlphabet {
    return [self alphabetWithCharacterSet:[NSCharacterSet decimalDigitCharacterSet]];
}

+ (id)letterAlphabet {
    return [self alphabetWithCharacterSet:[NSCharacterSet letterCharacterSet]];
}

+ (id)alphanumericAlphabet {
    return [self alphabetWithCharacterSet:[NSCharacterSet alphanumericCharacterSet]];
}

+ (id)alphabetWithCharacterSet:(NSCharacterSet *)characterSet {
    return [self alphabetWithASCIIRange:NSMakeRange(' ', '~' - ' ' + 1) characterSet:characterSet];
}

+ (id)alphabetWithASCIIRange:(NSRange)range characterSet:(NSCharacterSet *)characterSet {
    NSMutableString *string = [NSMutableString string];

    for (unichar character = range.location; character < NSMaxRange(range); character++) {
        if ([characterSet characterIsMember:character]) {
            [string appendFormat:@"%c", character];
        }
    }
    
    return [self stringWithString:string];
}

+ (id)randomStringWithRange:(NSRange)range alphabet:(NSString *)alphabet {
    NSMutableString *string = [NSMutableString string];
    NSUInteger lengthAlphabet = [alphabet length];
    NSUInteger length = range.location + arc4random_uniform((u_int32_t)range.length);
    
    for (NSUInteger i = 0; i < length; i++) {
        NSUInteger index = arc4random_uniform((u_int32_t)lengthAlphabet);
        
        [string appendFormat:@"%c", [alphabet characterAtIndex:index]];
    }
    
    return [self stringWithString:string];
}

+ (id)randomStringWithLength:(NSUInteger)length alphabet:(NSString *)alphabet {
    return [self randomStringWithRange:NSMakeRange(length, 0) alphabet:alphabet];
}

+ (id)randomStringWithLength:(NSUInteger)length {
    return [self randomStringWithLength:length alphabet:[self alphanumericAlphabet]];
}

+ (id)randomString {
    return [self randomStringWithLength:kNSStringRandomSrtingDefaultLength];
}

- (NSArray *)symbols {
    NSUInteger length = [self length];
    NSMutableArray *mutableSymbols = [NSMutableArray arrayWithCapacity:length];

    for (NSUInteger i = 0; i < length; i++) {
        [mutableSymbols addObject:[NSString stringWithFormat:@"%c", [self characterAtIndex:i]]];
    }
    
    return [[mutableSymbols copy] autorelease];
}

@end
