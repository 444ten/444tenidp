//
//  TENObjectWithName.h
//  HomeworkC
//
//  Created by 444ten on 4/20/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TENObjectWithName : NSObject
@property (nonatomic, copy, readonly)           NSString    *name;

+ (instancetype)objectWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name;


@end
