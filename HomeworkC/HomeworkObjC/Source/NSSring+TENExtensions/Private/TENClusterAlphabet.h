//
//  TENClusterAlphabet.h
//  HomeworkC
//
//  Created by Andrey Ten on 4/29/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENAlphabet.h"

@interface TENClusterAlphabet : TENAlphabet
@property (nonatomic, readonly) NSArray *alphabets;

- (instancetype)initWithAlphabets:(NSArray *)alphabets;

@end
