//
//  main.m
//  Dispatcher
//
//  Created by 444ten on 6/2/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "NSObject+TENExtensions.h"

//#import "NSStringTests.h"
//#import "TENBuildingTests.h"
//#import "TENCar.h"
//#import "TENCopyTests.h"
//#import "TENEnterprise.h"
//#import "TENEntityTests.h"
//#import "TENObject.h"
//#import "TENObjCSyntax.h"
//#import "TENWasher.h"

#import "TENDispatcherEnterprise.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        [[TENDispatcherEnterprise object] start];
        
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];
    }
    
    return 0;
}
