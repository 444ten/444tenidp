//
//  TENStateProtocol.h
//  HomeworkC
//
//  Created by Andrey Ten on 5/28/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef  NS_ENUM(NSUInteger, TENState) {
    TENStateFree,
    TENStateBusy,
    TENStateReadyForHandler
};

@class TENObservableObject;

@protocol TENStateProtocol <NSObject>

@optional

- (void)handlerDidBecomeFree:(TENObservableObject *)handler;
- (void)handlerDidBecomeBusy:(TENObservableObject *)handler;
- (void)handlerDidBecomeReadyForHandler:(TENObservableObject *)handler;

@end
