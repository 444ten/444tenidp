//
//  TENDispatcher.m
//  HomeworkC
//
//  Created by Andrey Ten on 5/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENDispatcher.h"

#import "TENCar.h"
#import "TENQueue.h"

static const NSUInteger TENTotalCars = 20;

@interface TENDispatcher ()
@property (nonatomic, retain)   TENQueue    *queueCars;

- (void)performWorkInBackground;

@end

@implementation TENDispatcher

#pragma mark -
#pragma mark Class

+ (instancetype)dispatcherWithQueueCars:(TENQueue *)queueCars {
    return [[[self alloc] initWithQueueCars:queueCars] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.queueCars = nil;
    
    [super dealloc];
}

- (instancetype)initWithQueueCars:(TENQueue *)queueCars {
    self = [super init];
    if (self) {
        self.queueCars = queueCars;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (void)work {
    [self performSelectorInBackground:@selector(performWorkInBackground) withObject:nil];
}


#pragma mark -
#pragma mark Overload


#pragma mark -
#pragma mark Private

- (void)performWorkInBackground {
    NSUInteger carsCount = 0;
    
    while (carsCount < TENTotalCars) {
        for (NSUInteger iterator = 0; iterator < 5; iterator++) {
            carsCount += 1;
            NSMutableString *model = [NSMutableString stringWithString:@"car_"];
            [model appendString:[NSString stringWithFormat:@"_%lu", carsCount]];
            
            TENCar *car = [TENCar carWithModel:model];
            car.money = carsCount;
            [self.queueCars enqueueObject:car];
        }
        NSLog(@"%lu car enqueued", carsCount);
        sleep(1);
    }
}

@end
