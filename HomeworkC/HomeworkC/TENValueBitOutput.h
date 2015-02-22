//
//  TENValueBitOutput.h
//  HomeworkC
//
//  Created by 444ten on 2/15/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENValueBitOutput__
#define __HomeworkC__TENValueBitOutput__

typedef enum {
    TENBigEndian,
    TENLittleEndian
} TENEndian;

extern
void TENValueBitOutput(void *valueRef, uint64_t size);

extern
TENEndian TENEndianDetect();

extern
void TENEndianConvert(void *valueRef, uint64_t size, TENEndian endian);

#endif /* defined(__HomeworkC__TENValueBitOutput__) */
