//
//  TENBuilding.h
//  HomeworkC
//
//  Created by 444ten on 4/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TENBuilding : NSObject
@property (nonatomic, retain)   NSString        *name;
@property (nonatomic, retain)   NSMutableArray  *roomsArray;

+ (instancetype)buildingWithName:(NSString *)name;

- (id)roomWithSpecification:(NSArray *)specification;
- (void)buildWithMasterplan:(NSDictionary *)masterplan;

@end
