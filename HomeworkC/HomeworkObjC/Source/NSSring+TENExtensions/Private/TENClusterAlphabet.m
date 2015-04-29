//
//  TENClusterAlphabet.m
//  HomeworkC
//
//  Created by Andrey Ten on 4/29/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENClusterAlphabet.h"

@interface TENClusterAlphabet ()
@property (nonatomic, retain) NSArray       *alphabets;
@property (nonatomic, assign) NSUInteger    count;

- (NSUInteger)countWithAlphabets:(NSArray *)alphabets;

@end

@implementation TENClusterAlphabet

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.alphabets = nil;
    
    [super dealloc];
}

- (instancetype)initWithAlphabets:(NSArray *)alphabets {
    self = [super init];
    if (self) {
        self.alphabets = alphabets;
        self.count = [self countWithAlphabets:alphabets];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (NSString *)stringAtIndex:(NSUInteger)index {
    NSAssert(index < self.count, NSRangeException);

    for (TENAlphabet *alphabet in self.alphabets) {
        NSUInteger count = [alphabet count];
        if (index < count) {
            return alphabet[index];
        }
        
        index -= count;
    }
    
    return nil;
}

- (NSString *)string {
    NSMutableString *string = [NSMutableString stringWithCapacity:self.count];
    for (TENAlphabet *alphabet in self.alphabets) {
        [string appendString:[alphabet string]];
    }
    
    return [[string copy] autorelease];
}

#pragma mark -
#pragma mark Private

- (NSUInteger)countWithAlphabets:(NSArray *)alphabets {
    NSUInteger count = 0;
    
    for (TENAlphabet *alphabet in alphabets) {
        count += [alphabet count];
    }
    
    return count;
}

@end
