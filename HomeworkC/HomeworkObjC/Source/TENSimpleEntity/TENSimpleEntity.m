//
//  TENSimpleEntity.m
//  HomeworkC
//
//  Created by 444ten on 4/14/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENSimpleEntity.h"


@interface TENSimpleEntity ()
@property (nonatomic, retain)   NSMutableArray  *childrenMutableArray;

@end

@implementation TENSimpleEntity

@dynamic children;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)entityWithName:(NSString *)name
                           age:(uint16_t)age
                        weight:(double)weight
{
    return [[[self alloc] initWithName:name
                                   age:age
                                weight:weight] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithName:(NSString *)name
                         age:(uint16_t)age
                      weight:(double)weight
{
    self = [super init];
    if (self) {
        [self setName:name];
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
    
    for (TENSimpleEntity *child in [self childrenMutableArray]) {
        [child sayHi];
    }
}

- (void)addChild:(TENSimpleEntity *)child {
    if ([self isEqualTo:child] || [[self childrenMutableArray] containsObject:child ]) {
        NSLog(@"dublicate\n");
        
        return;
    }
    
    [[self childrenMutableArray] addObject:child];
}

- (void)removeChild:(TENSimpleEntity *)child {
    if ([[self childrenMutableArray] containsObject:child]) {
        [[self childrenMutableArray] removeObject:child];
    } else {
        NSLog(@"%@ not contains in %@'s children\n", [child name], [self name]);
    }
}

- (void)performGenderSpecificOperation {
}
@end
