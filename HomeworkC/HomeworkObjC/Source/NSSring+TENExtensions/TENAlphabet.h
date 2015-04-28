//
//  TENAlphabet.h
//  HomeworkC
//
//  Created by Andrey Ten on 4/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

extern
NSRange TENMakeAlphabetRange(unichar value1, unichar value2);

@interface TENAlphabet : NSObject <NSFastEnumeration>

+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets;
+ (instancetype)alphabetWithRange:(NSRange)range;
+ (instancetype)alphabetWithStrings:(NSArray *)strings;
+ (instancetype)alphabetWithSymbols:(NSString *)string;

- (instancetype)initWithAlphabets:(NSArray *)alphabets;
- (instancetype)initWithRange:(NSRange)range;
- (instancetype)initWithStrings:(NSArray *)strings;
- (instancetype)initWithSymbols:(NSString *)string;

//the method should be overriden
- (NSUInteger)count;

//the method should be overriden
- (NSString *)stringAtIndex:(NSUInteger)index;

- (NSString *)objectAtIndexedSubscript:(NSUInteger)index;

- (NSString *)string;

@end
