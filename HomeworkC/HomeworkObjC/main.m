//
//  main.m
//  HomeworkObjC
//
//  Created by 444ten on 4/9/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "NSObject+TENExtensions.h"
#import "NSStringTests.h"
#import "TENBuildingTests.h"
#import "TENCar.h"
#import "TENCopyTests.h"
#import "TENEnterprise.h"
#import "TENEntityTests.h"
#import "TENObject.h"
#import "TENObjCSyntax.h"
#import "TENWasher.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
//        TENObjCSyntax();
//        TENEntityPerformTests();
//        TENBuildingPerformTests();
//        TENCopyPerformTests();
//        [[NSStringTests object] performTests];
        
        TENEnterprise *enterprise = [TENEnterprise object];
        
        TENCar *lexus = [TENCar carWithModel:@"Lexus"];
        lexus.money = 10;
        [enterprise addCar:lexus];
        
        TENCar *honda = [TENCar carWithModel:@"Honda"];
        honda.money = 20;
        [enterprise addCar:honda];

        TENCar *kia = [TENCar carWithModel:@"Kia"];
        kia.money = 30;
        [enterprise addCar:kia];
        
        TENCar *mers = [TENCar carWithModel:@"Mers"];
        mers.money = 40;
        [enterprise addCar:mers];
        
        TENCar *opel = [TENCar carWithModel:@"opel"];
        opel.money = 50;
        [enterprise addCar:opel];
        
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];
        
        
    }
    
    
    return 0;
}
