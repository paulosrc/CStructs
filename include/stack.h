#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef List Stack; // Pilha é uma lista

#define StackInit(Ltype, Ntype) ListInit(Ltype, Ntype)
#define StackPush(L, N)         ListAddNode(L, N)
#define StackPop(L)             ListRemoveNode(L, ListSize(L) - 1)
#define StackTop(L)             ListBack(L)
#define StackBottom(L)          ListFront(L)
#define StackNext(N)            ListNext(N)
#define StackPrev(N)            ListPrev(N)
#define StackData(N)            ListData(N)
#define StackType(L)            ListType(L)
#define StackHead(L)            ListHead(L)
#define StackTail(L)            ListTail(L)
#define StackEmpty(L)           ListEmpty(L)

#define LINEAR_STACK    LINEAR_LIST
#define CIRCULAR_STACK  CIRCULAR_LIST

#endif