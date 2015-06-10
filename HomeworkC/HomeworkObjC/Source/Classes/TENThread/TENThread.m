//
//  TENThread.m
//  HomeworkC
//
//  Created by Andrey Ten on 6/10/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENThread.h"

void TENPerformOnMainThreadWithBlock(dispatch_block_t block) {
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_sync(dispatch_get_main_queue(), block);
    }   
}
