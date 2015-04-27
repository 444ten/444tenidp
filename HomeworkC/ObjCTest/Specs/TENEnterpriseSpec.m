//
//  TENEnterpriseSpec.m
//  HomeworkC
//
//  Created by Andrey Ten on 4/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "Kiwi.h"

#import "TENEntity.h"

SPEC_BEGIN(TENEnterpriseSpec)

describe(@"TENEntity.h", ^{
    __block TENEntity *john = nil;
    
    afterAll(^{
        john = nil;
    });
    
    context(@"when initialized with +entityWithName:@\"John\" gender:TENGenderMale age:16 weight:70.6", ^{
        beforeAll(^{
            john = [TENEntity entityWithName:@"John" gender:TENGenderMale age:16 weight:70.6];
        });

        it(@"should be of class TENEntity", ^{
            [[john should] beKindOfClass:[TENEntity class]];
        });

        it(@"should be of count 2", ^{
            [[theValue([john retainCount]) should] equal:@(2)];
        });
//
//        it(@"should contain @\"A\" at index = 0", ^{
//            [[[alphabet stringAtIndex:0] should] equal:@"A"];
//        });
//        
//        it(@"should contain @\"B\" at index = 1", ^{
//            [[alphabet[1] should] equal:@"B"];
//        });
//        
//        it(@"should raise, when requesting object at index 3", ^{
//            [[theBlock(^{
//                [alphabet stringAtIndex:3];
//            }) should] raise];
//            
//            [[theBlock(^{
//                id a = alphabet[3];
//                [a description];
//            }) should] raise];
        });
//
//        it(@"should return @\"AB\" from -string", ^{
//            [[[alphabet string] should] equal:@"AB"];
//        });
//    });
//    
//    context(@"when initialized with -initWithRange:  with range 'A'-'B'", ^{
//        beforeAll(^{
//            alphabet = [[IDPAlphabet alloc] initWithRange:IDPMakeAlphabetRange('A', 'B')];
//        });
//        
//        it(@"should be of class IDPRangeAlphabet", ^{
//            [[alphabet should] beKindOfClass:[IDPRangeAlphabet class]];
//        });
//    });
//    
//    context(@"when initialized with +alphabetWithRange: with range 'A'-'z' when enumerated", ^{
//        NSRange range = IDPMakeAlphabetRange('A', 'z');
//        
//        beforeAll(^{
//            alphabet = [[IDPAlphabet alloc] initWithRange:range];
//        });
//        
//        it(@"shouldn't raise", ^{
//            [[theBlock(^{
//                for (id symbol in alphabet) {
//                    [symbol description];
//                }
//            }) shouldNot] raise];
//        });
//        
//        it(@"should return count of symbols equal to 'A'-'z' range", ^{
//            NSUInteger count = 0;
//            for (NSString *symbol in alphabet) {
//                [symbol description];
//                count++;
//            }
//            
//            [[theValue(count) should] equal:@(range.length)];
//        });
//        
//        it(@"should return symbols in range 'A'-'z'", ^{
//            unichar character = 'A';
//            for (NSString *symbol in alphabet) {
//                [[symbol should] equal:[NSString stringWithFormat:@"%c", character]];
//                character++;
//            }
//        });
//    });
});

SPEC_END
