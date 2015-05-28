//
//  TENDispatcher.h
//  HomeworkC
//
//  Created by Andrey Ten on 5/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENObservableObject.h"

#import "TENStateProtocol.h"

@class TENQueue;
@class TENObservableObject;

@interface TENDispatcher : TENObservableObject <TENStateProtocol>

- (void)addHandler:(TENObservableObject *)handler;
- (void)removeHandler:(TENObservableObject *)handler;

- (void)addObjectToProcess:(id)object;

@end
