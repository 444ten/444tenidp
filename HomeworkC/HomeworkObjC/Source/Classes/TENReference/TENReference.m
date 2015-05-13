//
//  TENReference.m
//  HomeworkC
//
//  Created by Andrey Ten on 5/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENReference.h"
@interface TENReference ()
@property (nonatomic, assign)   id  target;

@end

@implementation TENReference

@dynamic target;

#pragma mark -
#pragma mark - Class methods

+ (instancetype)referenceWithTarget:(id)target {
    return [[[self alloc] initWithTarget:target] autorelease];
}

#pragma mark -
#pragma mark - Initializations and Deallocations

- (void)dealloc {
    self.target = nil;
    
    [super dealloc];
}

- (instancetype)initWithTarget:(id)target {
    self = [super init];
    if (self) {
        self.target = target;
    }
    
    return self;
}

#pragma mark -
#pragma mark - Overload

- (NSUInteger)hash {
    return (NSUInteger)[self class] ^ (NSUInteger)self.target;
}

- (BOOL)isEqual:(id)object {
    if (nil == object) {
        return NO;
    }
    
    if (self == object) {
        return YES;
    }
    
    if ([object isMemberOfClass:[self class]]) {
        return [self isEqualToReference:object];
    }
    
    return NO;
}

#pragma mark -
#pragma mark - Public

- (BOOL)isEqualToReference:(TENReference *)reference {
    return self.target == reference.target;
}

#pragma mark -
#pragma mark - NSCopying

- (id)copyWithZone:(NSZone *)zone {
    return [[[self class] alloc] initWithTarget:self.target];
}

@end
