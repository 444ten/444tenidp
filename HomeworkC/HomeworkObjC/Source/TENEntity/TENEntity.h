//
//  TENEntity.h
//  HomeworkC
//
//  Created by 444ten on 4/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    TENGenderFemale,
    TENGenderMale
} TENGender;

@interface TENEntity : NSObject

@property (nonatomic, assign)   uint16_t        age;
@property (nonatomic, retain)   NSMutableArray  *children;
@property (nonatomic, assign)   TENGender       gender;
@property (nonatomic, retain)   NSString        *name;
@property (nonatomic, assign)   double          weight;

+ (instancetype)entityWithName:(NSString *)name
                        gender:(TENGender)gender
                           age:(uint16_t)age
                        weight:(double)weight;

- (void)sayHi;
- (void)fighting;
- (instancetype)makeEntityWithName:(NSString *)name
                    gender:(TENGender)gender
                    weight:(double)weight;
- (void)addChild:(TENEntity *)child;
- (void)removeChild:(TENEntity *)child;

@end
