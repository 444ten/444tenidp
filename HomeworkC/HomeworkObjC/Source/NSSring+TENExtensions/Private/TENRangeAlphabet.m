//
//  TENRangeAlphabet.m
//  HomeworkC
//
//  Created by Andrey Ten on 4/29/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENRangeAlphabet.h"

@interface TENRangeAlphabet ()
@property (nonatomic, assign) NSRange range;

@end

@implementation TENRangeAlphabet

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)initWithRange:(NSRange)range {
    self = [super init];
    if (self) {
        self.range = range;
    }

    return self;
}

#pragma mark -
#pragma mark Public

- (NSUInteger)count {
    return self.range.length;
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    NSRange range = self.range;
    
    NSAssert(index < range.length, NSRangeException);
    
    return [NSString stringWithFormat:@"%c", (unichar)(index + range.location)];
}

@end
