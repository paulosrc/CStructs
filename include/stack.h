#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef List Stack; // Pilha é uma lista

#define STACK_INIT(Ltype, Ntype) ListInit(Ltype, Ntype)
#define STACK_PUSH(L, N)         ListAddNode(L, N)
#define STACK_POP(L)             ListRemoveNode(L, ListSize(L) - 1)
#define STACK_FREE(L)            ListFree(L)
#define STACK_SIZE(L)            ListSize(L)

#define STACK_BOTTOM(L)          LIST_FRONT(L)
#define STACK_TOP(L)             LIST_BACK(L)
#define STACK_NEXT(N)            LIST_NEXT(N)
#define STACK_PREV(N)            LIST_PREV(N)
#define STACK_DATA(N)            LIST_DATA(N)
#define STACK_DATA(L)            LIST_TYPE(L)
#define STACK_HEAD(L)            LIST_HEAD(L)
#define STACK_TAIL(L)            LIST_TAIL(L)
#define STACK_IS_EMPTY(L)        LIST_IS_EMPTY(L)

#define LINEAR_STACK    LINEAR_LIST
#define CIRCULAR_STACK  CIRCULAR_LIST

#endif