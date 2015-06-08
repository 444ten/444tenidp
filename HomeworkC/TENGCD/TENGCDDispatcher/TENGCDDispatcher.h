//
//  TENGCDDispatcher.h
//  HomeworkC
//
//  Created by Andrey Ten on 5/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENGCDObservableObject.h"

@class TENQueue;
@class TENGCDEmployee;

@interface TENGCDDispatcher : NSObject

- (void)addHandler:(TENGCDEmployee *)handler;
- (void)removeHandler:(TENGCDEmployee *)handler;

- (void)processObject:(id)object;

@end
