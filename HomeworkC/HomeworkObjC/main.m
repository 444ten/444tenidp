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

int main(int argc, const char * argv[]) {
    @autoreleasepool {
//        TENObjCSyntax();
//        TENEntityPerformTests();
//        TENBuildingPerformTests();
//        TENCopyPerformTests();
//        [[NSStringTests object] performTests];
        
        TENEnterprise *enterprise = [TENEnterprise object];
        
        TENCar *car = [TENCar carWithModel:@"Lexus"];
        car.money = 100;
        car.clean = NO;
        [enterprise performWorkWithCar:car];
        
        TENCar *honda = [TENCar carWithModel:@"Honda"];
        honda.money = 75;
        honda.clean = NO;
        [enterprise performWorkWithCar:honda];
        
    }
    
    return 0;
}
