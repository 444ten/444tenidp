//
//  main.m
//  TENGCD
//
//  Created by Andrey Ten on 6/8/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "NSObject+TENExtensions.h"

#import "TENGCDEnterprise.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        [[ object] start];
        
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];
    }
    
    return 0;
}
