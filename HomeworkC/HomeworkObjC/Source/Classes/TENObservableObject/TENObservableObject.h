//
//  TENObservableObject.h
//  HomeworkC
//
//  Created by Andrey Ten on 5/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TENObservableObject : NSObject
@property (atomic, assign)      NSUInteger  state;
@property (nonatomic, readonly) NSSet       *observerSet;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (BOOL)isObsevedByObserver:(id)observer;

- (SEL)selectorForState:(NSUInteger)state;

@end
