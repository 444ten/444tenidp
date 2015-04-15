//
//  TENEntityFemale.h
//  HomeworkC
//
//  Created by 444ten on 4/14/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEntity.h"
#import "TENSimpleEntity.h"

@interface TENEntityFemale : TENSimpleEntity

- (id)makeChildWithGender:(TENGender)gender
                     name:(NSString *)name
                   weight:(double)weight;

@end
