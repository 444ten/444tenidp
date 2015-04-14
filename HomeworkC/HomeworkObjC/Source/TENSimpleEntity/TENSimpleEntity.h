//
//  TENSimpleEntity.h
//  HomeworkC
//
//  Created by 444ten on 4/14/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    TENGenderFemale,
    TENGenderMale
} TENGender;

@interface TENSimpleEntity : NSObject

@property (nonatomic, assign)           uint16_t    age;
@property (nonatomic, retain, readonly) NSArray     *children;
@property (nonatomic, retain)           NSString    *name;
@property (nonatomic, assign)           double      weight;

+ (instancetype)entityWithName:(NSString *)name
                        gender:(TENGender)gender
                           age:(uint16_t)age
                        weight:(double)weight;

- (void)sayHi;
- (void)addChild:(TENSimpleEntity *)child;
- (void)removeChild:(TENSimpleEntity *)child;

@end
