//
//  TENLinkedListEnumeratorPrivate.h
//  HomeworkC
//
//  Created by 444ten on 4/2/15.
//  Copyright (c) 2015 444ten. All rights reserved.
//

#ifndef HomeworkC_TENLinkedListEnumeratorPrivate_h
#define HomeworkC_TENLinkedListEnumeratorPrivate_h

typedef struct TENLinkedList TENLinkedList;
typedef struct TENLinkedListEnumerator TENLinkedListEnumerator;
typedef struct TENNode TENNode;

#pragma mark -
#pragma mark Private Declarations

extern
TENNode *TENLinkedListEnumeratorNextNode(TENLinkedListEnumerator *enumerator);

extern
void TENLinkedListEnumeratorSetList(TENLinkedListEnumerator *enumerator, TENLinkedList *list);

extern
TENLinkedList *TENLinkedListEnumeratorGetList(TENLinkedListEnumerator *enumerator);

extern
void TENLinkedListEnumeratorSetNode(TENLinkedListEnumerator *enumerator, TENNode *node);

extern
TENNode *TENLinkedListEnumeratorGetNode(TENLinkedListEnumerator *enumerator);

extern
void TENLinkedListEnumeratorSetMutationCount(TENLinkedListEnumerator *enumerator, uint64_t mutationCount);

extern
uint64_t TENLinkedListEnumeratorGetMutationCount(TENLinkedListEnumerator *enumerator);

extern
void TENLinkedListEnumeratorSetValid(TENLinkedListEnumerator *enumerator, bool valid);

extern
void TENLinkedListEnumeratorCheckMutations(TENLinkedListEnumerator *enumerator);

#endif
