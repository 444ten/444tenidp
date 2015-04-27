//
//  TENStringsAlphabet.m
//  HomeworkC
//
//  Created by Andrey Ten on 4/27/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENStringsAlphabet.h"

@interface TENStringsAlphabet ()
@property (nonatomic, retain) NSArray *strings;

@end

@implementation TENStringsAlphabet

#pragma mark -
#pragma mark  Deallocations and Initializations

- (void)dealloc {
    self.strings = nil;
    
    [super dealloc];
}

- (instancetype)initWithStrings:(NSArray *)strings {
    self = [super init];
    if (self) {
        self.strings = strings;
    }

    return self;
    
}


@end
