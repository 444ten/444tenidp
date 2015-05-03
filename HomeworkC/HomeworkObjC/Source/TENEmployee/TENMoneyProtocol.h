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

@optional

- (void)transferMoney:(NSUInteger)money toPayee:(id<TENMoneyProtocol>)payee;
- (void)takeMoney:(NSUInteger)money fromPayer:(id<TENMoneyProtocol>)payer;

@end
