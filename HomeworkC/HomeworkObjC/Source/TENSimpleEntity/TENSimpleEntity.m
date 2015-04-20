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
        self.name = name;
        self.age = age;
        self.weight = weight;
        self.childrenMutableArray = [NSMutableArray array];
    }
    
    return self;
}

- (void)dealloc {
    self.name = nil;
    self.childrenMutableArray = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors Methods

- (NSArray *)children {
    return [[self.childrenMutableArray copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)sayHi {
    NSLog(@"%@ say Hi", [self name]);
    
    for (TENSimpleEntity *child in self.childrenMutableArray) {
        [child sayHi];
    }
}

- (void)addChild:(TENSimpleEntity *)child {
    NSMutableArray *array = self.childrenMutableArray;
    
    if ([self isEqualTo:child] || [array containsObject:child ]) {
        NSLog(@"dublicate\n");
        
        return;
    }
    
    [array addObject:child];
}

- (void)removeChild:(TENSimpleEntity *)child {
    NSMutableArray *array = self.childrenMutableArray;
    
    if ([array containsObject:child]) {
        [array removeObject:child];
    } else {
        NSLog(@"%@ not contains in %@'s children\n", child.name, self.name);
    }
}

- (void)performGenderSpecificOperation {
    
}

@end
