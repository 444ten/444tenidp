//
//  TENEntity.m
//  HomeworkC
//
//  Created by 444ten on 4/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENEntity.h"

@interface TENEntity ()
@property (nonatomic, retain)   NSMutableArray  *childrenMutableArray;

@end

@implementation TENEntity

@dynamic children;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)entityWithName:(NSString *)name
                        gender:(TENGender)gender
                           age:(uint16_t)age
                        weight:(double)weight
{
    return [[[self alloc] initWithName:name
                                gender:gender
                                   age:age
                                weight:weight] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithName:(NSString *)name
                      gender:(TENGender)gender
                         age:(uint16_t)age
                      weight:(double)weight
{
    self = [super init];
    if (self) {
        [self setName:name];
        [self setGender:gender];
        [self setAge:age];
        [self setWeight:weight];
        [self setChildrenMutableArray:[[NSMutableArray new] autorelease]];
    }
    
    return self;
}

- (void)dealloc {
    [self setName:nil];
    [self setChildrenMutableArray:nil];

    [super dealloc];
}

#pragma mark - 
#pragma mark Accessors Methods

- (NSArray *)children {
    return [[[self childrenMutableArray] copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)sayHi {
    NSLog(@"%@ say Hi", [self name]);
    
    for (TENEntity *child in [self childrenMutableArray]) {
        [child sayHi];
    }
}

- (void)fighting {
    NSLog(@"%@ fighting", [self name]);
}

- (instancetype)makeEntityWithName:(NSString *)name
                            gender:(TENGender)gender
                            weight:(double)weight
{
   return [TENEntity entityWithName:name gender:gender age:0 weight:weight];
}

- (void)addChild:(TENEntity *)child {
    if ([self isEqualTo:child] || [[self childrenMutableArray] containsObject:child ]) {
        NSLog(@"dublicate\n");
        
        return;
    }
    
    [[self childrenMutableArray] addObject:child];
}

- (void)removeChild:(TENEntity *)child {
    if ([[self childrenMutableArray] containsObject:child]) {
        [[self childrenMutableArray] removeObject:child];
    } else {
        NSLog(@"%@ not contains in %@'s children\n", [child name], [self name]);
    }
}

@end
