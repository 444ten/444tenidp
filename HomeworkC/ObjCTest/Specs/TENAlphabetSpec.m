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
    });
});

SPEC_END
