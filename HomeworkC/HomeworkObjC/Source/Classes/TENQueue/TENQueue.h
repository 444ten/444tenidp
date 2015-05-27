//
//  TENQueue.h
//  HomeworkC
//
//  Created by Andrey Ten on 5/26/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TENQueue : NSObject
@property (nonatomic, readonly) NSArray *queue;

- (BOOL)isEmpty;
- (BOOL)isNonEmpty;

- (void)enqueueObject:(id)object;
- (id)dequeueObject;

@end
