//
//  TENEmployee.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TENObjectWithName.h"

@interface TENEmployee : TENObjectWithName
@property (nonatomic, assign)           NSUInteger  experience;
@property (nonatomic, assign)           NSUInteger  money;
@property (nonatomic, assign)           NSUInteger  salary;

- (void)transferMoney:(NSUInteger)money toEmployee:(TENEmployee *)employee;

@end
