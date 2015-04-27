//
//  TENEnterprise.h
//  HomeworkC
//
//  Created by 444ten on 4/22/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TENBuilding;

@interface TENEnterprise : NSObject
@property (nonatomic, copy, readonly)   NSString    *name;
@property (nonatomic, readonly)         NSArray     *employees;
@property (nonatomic, readonly)         TENBuilding *staffBuilding;
@property (nonatomic, readonly)         TENBuilding *carwashBuilding;

+ (instancetype)enterpriseWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name;


@end
