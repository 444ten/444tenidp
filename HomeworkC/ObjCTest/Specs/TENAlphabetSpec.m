//
//  TENEnterpriseSpec.m
//  HomeworkC
//
//  Created by Andrey Ten on 4/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "Kiwi.h"

#import "TENAlphabet.h"
#import "TENStringsAlphabet.h"

SPEC_BEGIN(TENAlphabetSpec)

describe(@"TENAlphabet", ^{
    __block TENAlphabet *alphabet = nil;
    
    afterAll(^{
        alphabet = nil;
    });
    
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
});

SPEC_END
