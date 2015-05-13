//
//  TENRetainReference.m
//  HomeworkC
//
//  Created by Andrey Ten on 5/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import "TENRetainReference.h"

@interface TENRetainReference ()
@property (nonatomic, retain)   id  target;

@end

@implementation TENRetainReference

@synthesize target = _target;

@end
