//
//  TENReference.h
//  HomeworkC
//
//  Created by Andrey Ten on 5/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TENReference : NSObject <NSCopying>
@property (nonatomic, readonly) id  target;

+ (instancetype)referenceWithTarget:(id)target;

- (instancetype)initWithTarget:(id)target;

- (BOOL)isEqualToReference:(TENReference *)reference;

@end
