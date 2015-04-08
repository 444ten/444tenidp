//
//  output.h
//  lesson1
//
//  Created by 444ten on 2/10/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __lesson1__output__
#define __lesson1__output__

typedef enum {
    TENResultNone,
    TENResultMama,
    TENResultPapa,
    TENResultMamaPapa
} TENResult;

extern
TENResult TENSayParent(int value);

extern
void TENOutputParentFromStartToEnd(int startValue, int endValue);

#endif /* defined(__lesson1__output__) */
