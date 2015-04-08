//
//  main.c
//  HomeworkC
//
//  Created by 444ten on 2/13/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include "TENAutoreleasePoolTests.h"
#include "TENCharBitTests.h"
#include "TENHumanTests.h"
#include "TENLinkedListTests.h"
#include "TENMutableSetTests.h"
#include "TENNodeTests.h"
#include "TENObjectTests.h"
#include "TENOutputMacrosTests.h"
#include "TENOutputParentTest.h"
#include "TENStackTests.h"
#include "TENStringTests.h"
#include "TENStructTest.h"
#include "TENValueBitOutputTest.h"

int main(int argc, const char * argv[]) {
//    TENOutputParentPerformTest();
//    
//    TENOutputMacrosPerformTests();
//
//    TENCharBitPerformTests();
//
//    TENStructPerformTest();
//
//    TENValueBitOutputPerformTest();

    TENHumanPerformTests();

    TENObjectPerformTest();
    
    TENStringPerformTest();
    
    TENMutableSetPerformTests();
    
    TENStackPerformTest();
    
    TENNodePerformTests();
    
    TENLinkedListPerformTests();
    
    TENAutoreleasePoolPerformTests();
    
    return 0;
}
