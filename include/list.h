#ifndef LIST_H
#define LIST_H

#include "node.h"

#define NEXT links[0]
#define PREV links[1]

#define LIST_FRONT(L)     L->head->NEXT
#define LIST_BACK(L)      L->tail->PREV
#define LIST_NEXT(N)      N->NEXT
#define LIST_PREV(N)      N->PREV
#define LIST_DATA(N)      N->data
#define LIST_TYPE(L)      L->type
#define LIST_HEAD(L)      L->head
#define LIST_TAIL(L)      L->tail
#define LIST_IS_EMPTY(L) (L->head->NEXT == L->tail)

typedef enum 
{
    LINEAR_LIST,
    CIRCULAR_LIST
} ListType;

typedef struct
{
    Node *head;
    Node *tail;
    ListType type;
} List;

List*   listInit(ListType Ltype, NodeType Ntype);
void    listAddNode(List *L, Node *newNode);
void    listInsertNode(List *L, Node *newNode, size_t index);
Node*   listRemoveNode(List *L, size_t index);
Node*   listFetchNode(List *L, size_t index);
void    listFree(List *L);
size_t  listSize(List *L);

#endif