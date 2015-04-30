//
//  TENEnterpriseSpec.m
//  HomeworkC
//
//  Created by Andrey Ten on 4/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "Kiwi.h"

#import "TENAlphabet.h"
#import "TENClusterAlphabet.h"
#import "TENRangeAlphabet.h"
#import "TENStringsAlphabet.h"

SPEC_BEGIN(TENAlphabetSpec)

describe(@"TENAlphabet", ^{
    __block TENAlphabet *alphabet = nil;
    
    afterAll(^{
        alphabet = nil;
    });

#pragma mark -
#pragma Strings Alphabet
    
    context(@"when initialized with +alphabetWithStrings:@[@\"And\",@\"rey\"]", ^{
        beforeAll(^{
            alphabet = [TENAlphabet alphabetWithStrings:@[@"And",@"rey"]];
        });
        
        it(@"should be of class TENStringsAlphabet", ^{
            [[alphabet should] beKindOfClass:[TENStringsAlphabet class]];
        });
        
        it(@"should be of count 2", ^{
            [[alphabet should] haveCountOf:2];
        });
        
        it(@"should contain @\"And\" at index 0", ^{
            [[alphabet[0] should] equal:@"And"];
        });
        
        it(@"should contain @\"rey\" at index 1", ^{
            [[[alphabet stringAtIndex:1] should] equal:@"rey"];
        });
        
        it(@"should raise, when requesting object at index 2", ^{
            [[theBlock(^{
                [alphabet[2] description];
            }) should] raise];
        });
        
        it(@"should return @\"Andrey\" from -string", ^{
            [[[alphabet string] should] equal:@"Andrey"];
        });
    });

    context(@"when initialized with -initWithStrings:@[@\"And\",@\"rey\"]", ^{
        beforeAll(^{
            alphabet = [[TENAlphabet alloc] initWithStrings:@[@"And",@"rey"]];
        });
        
        it(@"should be of class TENStringsAlphabet", ^{
            [[alphabet should] beKindOfClass:[TENStringsAlphabet class]];
        });
    });

    context(@"when initialized with -initWithStrings:strings", ^{
        NSArray *strings = @[@"Andrey", @"Ten", @"IDAP"];
        
        beforeEach (^{
//            alphabet = [[TENAlphabet alloc] initWithStrings:strings];
            alphabet = [TENAlphabet alphabetWithStrings:strings];
        });
        
        it(@"should not raise", ^{
            
            [[theBlock(^{
                for (id symbol in alphabet) {
                    [symbol description];
                }
            }) shouldNot] raise];
        });
        
        it(@"should return right symbols", ^{
            NSUInteger index = 0;
            
            for (NSString *symbol in alphabet) {
                [[symbol should] equal:strings[index]];
                index += 1;
            }
        });
    });
    
#pragma mark -
#pragma Range Alphabet

    context(@"when initialized with +alphabetWithRange:'A' - 'B'", ^{
        beforeAll(^{
            alphabet = [TENAlphabet alphabetWithRange:TENMakeAlphabetRange('A', 'B')];
        });
        
        it(@"should be of class TENRangeAlphabet", ^{
            [[alphabet should] beKindOfClass:[TENRangeAlphabet class]];
        });
        
        it(@"should be of count 2", ^{
            [[alphabet should] haveCountOf:2];
        });
        
        it(@"should contain @\"A\" at index 0", ^{
            [[alphabet[0] should] equal:@"A"];
        });
        
        it(@"should contain @\"B\" at index 1", ^{
            [[[alphabet stringAtIndex:1] should] equal:@"B"];
        });
        
        it(@"should raise, when requesting object at index 2", ^{
            [[theBlock(^{
                [alphabet[2] description];
            }) should] raise];
        });
        
        it(@"should return @\"AB\" from -string", ^{
            [[[alphabet string] should] equal:@"AB"];
        });
    });
    
    context(@"when initialized with -initWithRange:'A' - 'B'", ^{
        beforeAll(^{
            alphabet = [[TENAlphabet alloc] initWithRange:TENMakeAlphabetRange('A', 'B')];
        });
        
        it(@"should be of class TENRangeAlphabet", ^{
            [[alphabet should] beKindOfClass:[TENRangeAlphabet class]];
        });
    });
    
    context(@"when initialized with +alphabetWithRange:'A' - 'z' when enumerated", ^{
        NSRange range = TENMakeAlphabetRange('A', 'z');
        
        beforeAll(^{
            alphabet = [[TENAlphabet alloc] initWithRange:range];
//            alphabet = [TENAlphabet alphabetWithRange:range];
        });
        
        it(@"should not raise", ^{
            [[theBlock(^{
                for (id symbol in alphabet) {
                    [symbol description];
                }
            }) shouldNot] raise];
        });
        
        it(@"should return count equal range.length ", ^{
            NSUInteger count = 0;
            for (id symbol in alphabet) {
                [symbol description];
                count += 1;
            }
            
            [[@(count) should] equal:@(range.length)];
        });

        it(@"should return right character", ^{
            unichar character = range.location;
            for (NSString * symbol in alphabet) {
                [[symbol should] equal:[NSString stringWithFormat:@"%c", character]];
                character += 1;
            }
        });
        
    });
    
#pragma mark -
#pragma Cluster Alphabet
 
    context(@"when initialized with +alphabetWithAlphabets", ^{
        TENAlphabet *capitalizedAlphabet =[TENAlphabet alphabetWithRange:TENMakeAlphabetRange('A', 'Z')];
        TENAlphabet *lowercaseAlphabet =[TENAlphabet alphabetWithRange:TENMakeAlphabetRange('a', 'z')];
        
        beforeAll(^{
            alphabet = [TENAlphabet alphabetWithAlphabets:@[capitalizedAlphabet,lowercaseAlphabet]];
        });
        
        it(@"should be of class TENClusterAlphabet", ^{
            [[alphabet should] beKindOfClass:[TENClusterAlphabet class]];
        });
        
        it(@"should be of count 52", ^{
            [[alphabet should] haveCountOf:52];
        });
        
        it(@"should contain @\"A\" at index 0", ^{
            [[alphabet[0] should] equal:@"A"];
        });
        
        it(@"should contain @\"a\" at index 26", ^{
            [[[alphabet stringAtIndex:26] should] equal:@"a"];
        });
        
        it(@"should raise, when requesting object at index 52", ^{
            [[theBlock(^{
                [alphabet[52] description];
            }) should] raise];
        });
    });
    
    context(@"when initialized with -initWithAlphabets", ^{
        TENAlphabet *capitalizedAlphabet =[TENAlphabet alphabetWithRange:TENMakeAlphabetRange('A', 'Z')];
        TENAlphabet *lowercaseAlphabet =[TENAlphabet alphabetWithRange:TENMakeAlphabetRange('a', 'z')];
        
        beforeAll(^{
            alphabet = [[TENAlphabet alloc] initWithAlphabets:@[capitalizedAlphabet,lowercaseAlphabet]];
        });
        
        it(@"should be of class TENClusterAlphabet", ^{
            [[alphabet should] beKindOfClass:[TENClusterAlphabet class]];
        });
    });

    context(@"when initialized with -initWithAlphabets", ^{
        TENAlphabet *capitalizedAlphabet =[TENAlphabet alphabetWithRange:TENMakeAlphabetRange('A', 'Z')];
        TENAlphabet *lowercaseAlphabet =[TENAlphabet alphabetWithRange:TENMakeAlphabetRange('a', 'z')];
        
        beforeAll(^{
            alphabet = [[TENAlphabet alloc] initWithAlphabets:@[capitalizedAlphabet,lowercaseAlphabet]];
        });
        
        it(@"should not raise", ^{
            [[theBlock(^{
                for (id symbol in alphabet) {
                    [symbol description];
                }
            }) shouldNot] raise];
        });
        
        it(@"should return count equal count of range A-Z + a-z", ^{
            NSUInteger count = 0;
            for (id symbol in alphabet) {
                [symbol description];
                count += 1;
            }
            
            [[@(count) should] equal:@([capitalizedAlphabet count] + [lowercaseAlphabet count])];
        });

        it(@"should return right character", ^{
            NSMutableString *string = [NSMutableString stringWithString:[capitalizedAlphabet string]];
            [string appendString:[lowercaseAlphabet string]];
            
            NSUInteger index = 0;
            for (NSString * symbol in alphabet) {
                [[symbol should] equal:[NSString stringWithFormat:@"%c", [string characterAtIndex:index]]];
                index += 1;
            }
        });
    });
});

SPEC_END
