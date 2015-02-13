//
//  main.c
//  HomeworkC
//
//  Created by 444ten on 2/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include "TENCharToBin.h"
#include "TENOutputMacros.h"
#include "TENOutputParent.h"
#include "TENOutputParentTest.h"
#include "TENStructTest.h"

int main(int argc, const char * argv[]) {
    TENOutputParentPerformTest();
    TENOutputParentFromStartToEnd(0, 1000);
    
    TENOutputMacrosPerformTest();

    TENStructPerformTest();

    TENCharToBinOutPerformTest();

    return 0;
}
