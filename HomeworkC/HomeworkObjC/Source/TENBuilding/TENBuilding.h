//
//  TENBuilding.h
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TENBuilding : NSObject
@property (nonatomic, copy, readonly)   NSString    *name;
@property (nonatomic, readonly)         NSArray     *rooms;

+ (instancetype)buildingWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name;
- (void)addRoom:(id)room;
- (void)removeRoom:(id)room;

@end
