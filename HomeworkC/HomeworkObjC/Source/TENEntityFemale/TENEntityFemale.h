//
//  TENEntityFemale.h
//  HomeworkC
//
//  Created by 444ten on 4/14/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENSimpleEntity.h"
#import "TENSimpleEntityProtocol.h"

@class TENEntityMale;

@interface TENEntityFemale : TENSimpleEntity <TENSimpleEntityProtocol>

- (TENEntityMale *)makeEntityMaleWithName:(NSString *)name
                                weight:(double)weight;

- (instancetype)makeEntityFemaleWithName:(NSString *)name
                                  weight:(double)weight;

@end
