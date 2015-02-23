//
//  TENOutputMacrosTest.h
//  HomeworkC
//
//  Created by 444ten on 2/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef __HomeworkC__TENOutputMacrosTest__
#define __HomeworkC__TENOutputMacrosTest__

#define TENOutputValueGenerate(type, specifier)     \
    void TENOutput_##type(type value) {             \
        printf("("#type") %"#specifier"\n", value); \
    }

#define TENOutputValue(type, value) \
    TENOutput_##type(value);

#endif /* defined(__HomeworkC__TENOutputMacrosTest__) */
