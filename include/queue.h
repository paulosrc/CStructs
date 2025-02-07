#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef List Queue; // Fila é uma lista

#define QueueInit(Ltype, Ntype) ListInit(Ltype, Ntype)
#define QueueEnqueue(L, N)      ListAddNode(L, N)
#define QueueDequeue(L)         ListRemoveNode(L, 0)
#define QueueFront(L)           ListFront(L)
#define QueueBack(L)            ListBack(L)
#define QueueNext(N)            ListNext(N)
#define QueuePrev(N)            ListPrev(N)
#define QueueData(N)            ListData(N)
#define QueueType(L)            ListType(L)
#define QueueHead(L)            ListHead(L)
#define QueueTail(L)            ListTail(L)
#define QueueEmpty(L)           ListEmpty(L)
#define QueueFree(L)            ListFree(L)
#define QueueSize(L)            ListSize(L)

#define LINEAR_QUEUE LINEAR_LIST
#define CIRCULAR_QUEUE CIRCULAR_LIST

#endif