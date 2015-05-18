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
        lexus.money = 100;
        [enterprise addCar:lexus];
        
        TENCar *honda = [TENCar carWithModel:@"Honda"];
        honda.money = 75;
        [enterprise addCar:honda];
    }
    
    return 0;
}
