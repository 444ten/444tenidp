//
//  TENDispatcher.h
//  HomeworkC
//
//  Created by Andrey Ten on 5/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENObservableObject.h"

@class TENQueue;

@interface TENDispatcher : TENObservableObject

+ (instancetype)dispatcherWithQueueCars:(TENQueue *)queueCars;

- (instancetype)initWithQueueCars:(TENQueue *)queueCars;

- (void)work;

@end
