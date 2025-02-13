#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef List Queue; // Fila é uma lista

#define QUEUE_INIT(Ltype, Ntype) ListInit(Ltype, Ntype)
#define QUEUE_ENQUEUE(L, N)      ListAddNode(L, N)
#define QUEUE_DEQUEUE(L)         ListRemoveNode(L, 0)
#define QUEUE_FREE(L)            ListFree(L)
#define QUEUE_SIZE(L)            ListSize(L)

#define QUEUE_FRONT(L)           LIST_FRONT(L)
#define QUEUE_BACK(L)            LIST_BACK(L)
#define QUEUE_NEXT(N)            LIST_NEXT(N)
#define QUEUE_PREV(N)            LIST_PREV(N)
#define QUEUE_DATA(N)            LIST_DATA(N)
#define QUEUE_TYPE(L)            LIST_TYPE(L)
#define QUEUE_HEAD(L)            LIST_HEAD(L)
#define QUEUE_TAIL(L)            LIST_TAIL(L)
#define QUEUE_IS_EMPTY(L)        LIST_IS_EMPTY(L)

#define LINEAR_QUEUE LINEAR_LIST
#define CIRCULAR_QUEUE CIRCULAR_LIST

#endif