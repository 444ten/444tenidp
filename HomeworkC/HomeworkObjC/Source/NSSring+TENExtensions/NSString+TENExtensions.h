//
//  NSString+TENExtensions.h
//  HomeworkC
//
//  Created by 444ten on 4/20/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (TENExtensions)

+ (id)uppercaseLetterAlphabet;
+ (id)lowercaseLetterAlphabet;
+ (id)decimalDigitAlphabet;
+ (id)letterAlphabet;
+ (id)alphanumericAlphabet;
+ (id)alphabetWithCharacterSet:(NSCharacterSet *)characterSet;
+ (id)alphabetWithASCIIRange:(NSRange)range characterSet:(NSCharacterSet *)characterSet;


+ (id)randomStringWithRange:(NSRange)range alphabet:(NSString *)alphabet;
+ (id)randomStringWithLength:(NSUInteger)length alphabet:(NSString *)alphabet;
+ (id)randomStringWithLength:(NSUInteger)length;
+ (id)randomString;

@end
