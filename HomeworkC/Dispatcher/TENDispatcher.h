//
//  TENDispatcher.h
//  HomeworkC
//
//  Created by Andrey Ten on 5/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENObservableObject.h"

@class TENQueue;
@class TENDispatcherEmployee;

@interface TENDispatcher : TENObservableObject

- (void)addHandler:(TENDispatcherEmployee *)handler;
- (void)removeHandler:(TENDispatcherEmployee *)handler;

- (void)addObjectToProcess:(id)object;

@end
