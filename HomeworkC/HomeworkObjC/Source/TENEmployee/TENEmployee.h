//
//  TENEmployee.h
//  HomeworkC
//
//  Created by 444ten on 4/16/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TENMoneyProtocol.h"

@interface TENEmployee : NSObject <TENMoneyProtocol>
@property (nonatomic, copy, readonly)   NSString    *name;
@property (nonatomic, assign)           NSUInteger  experience;
//@property (nonatomic, assign)           NSUInteger  money;
@property (nonatomic, assign)           NSUInteger  salary;

+ (instancetype)employeeWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name;

@end
