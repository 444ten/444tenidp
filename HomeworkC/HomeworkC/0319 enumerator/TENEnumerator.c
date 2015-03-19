//
//  TENEnumerator.c
//  HomeworkC
//
//  Created by 444ten on 3/19/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#include "TENEnumerator.h"

//have: set with countOfNotNullObject and mutationCount
//task: output nonNULLObject of set
//
//
//after call outputMethodSet
//  create TENEnumerator *enumarator with set, countOfNotNullObject, mutationCount
//      retaining set
//
//      call enumerator
//          enumerator->_mutationCount should equal set->_mutationCount
//
//          if currentCount == countOfNULLObject
//              releasing set
//              return NULL
//          esle
//              return nextObject
//
//          currentCount increment
//
//      if returning object == NULL
//          releasing enumerator
