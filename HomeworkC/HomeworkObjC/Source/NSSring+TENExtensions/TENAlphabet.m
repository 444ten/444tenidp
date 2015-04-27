//
//  TENAlphabet.m
//  HomeworkC
//
//  Created by Andrey Ten on 4/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENAlphabet.h"

#import <math.h>

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
    return nil;
}

+ (instancetype)alphabetWithSymbols:(NSString *)string {
    return nil;
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
    return nil;
}

- (instancetype)initWithSymbols:(NSString *)string {
    return nil;

}

#pragma mark -
#pragma mark Public Methods

- (NSUInteger)count {
    return 0;
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    return nil;
}

@end
