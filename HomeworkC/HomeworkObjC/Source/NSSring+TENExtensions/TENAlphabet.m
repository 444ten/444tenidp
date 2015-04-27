//
//  TENAlphabet.m
//  HomeworkC
//
//  Created by Andrey Ten on 4/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENAlphabet.h"

#import <math.h>

#import "NSString+TENExtensions.h"
#import "TENStringsAlphabet.h"

NSRange TENMakeAlphabetRange(unichar value1, unichar value2) {
    unichar maxValue = MAX(value1, value2);
    unichar minValue = MIN(value1, value2);
    
    return NSMakeRange(minValue, maxValue - minValue + 1);
}

@implementation TENAlphabet

#pragma mark -
#pragma mark Class Methods

+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets {
    return nil;
}

+ (instancetype)alphabetWithRange:(NSRange)range {
    return nil;
}

+ (instancetype)alphabetWithStrings:(NSArray *)strings {
    return [[[TENStringsAlphabet alloc] initWithStrings:strings] autorelease];
}

+ (instancetype)alphabetWithSymbols:(NSString *)string {
    return [self alphabetWithStrings:[string symbols]];
}

#pragma mark -
#pragma mark Deallocations and Initializations

- (void)dealloc {
    [super dealloc];
}

- (instancetype)initWithAlphabets:(NSArray *)alphabets {
    return nil;
}

- (instancetype)initWithRange:(NSRange)range {
    return nil;
}

- (instancetype)initWithStrings:(NSArray *)strings {
    [self release];
    
    return [[TENStringsAlphabet alloc] initWithStrings:strings];
}

- (instancetype)initWithSymbols:(NSString *)string {
    return [self initWithStrings:[string symbols]];

}

#pragma mark -
#pragma mark Public Methods

- (NSUInteger)count {
    [self doesNotRecognizeSelector:_cmd];
    
    return 0;
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    [self doesNotRecognizeSelector:_cmd];
    
    return nil;
}

@end
