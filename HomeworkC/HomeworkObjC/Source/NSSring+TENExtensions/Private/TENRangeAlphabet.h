//
//  TENRangeAlphabet.h
//  HomeworkC
//
//  Created by Andrey Ten on 4/29/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENAlphabet.h"

@interface TENRangeAlphabet : TENAlphabet
@property (nonatomic, readonly) NSRange range;

- (instancetype)initWithRange:(NSRange)range;

@end
