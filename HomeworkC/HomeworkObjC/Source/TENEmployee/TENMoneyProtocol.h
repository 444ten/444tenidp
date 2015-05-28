//
//  TENMoneyProtocol.h
//  HomeworkC
//
//  Created by 444ten on 5/3/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TENMoneyProtocol <NSObject>
@property (nonatomic, assign) NSUInteger money;

- (NSUInteger)giveMoney;
- (void)takeMoney:(NSUInteger)money;

@end
