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
#import "TENCopyTests.h"
#import "TENObjCSyntax.h"
#import "TENEntityTests.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
//        TENObjCSyntax();
//        TENEntityPerformTests();
//        TENBuildingPerformTests();
//        TENCopyPerformTests();
        
        [[NSStringTests object] performTests];
        
    }
    
    return 0;
}
