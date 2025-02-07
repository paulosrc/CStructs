#ifndef LIST_H
#define LIST_H

#include "node.h"

#define next links[0]
#define prev links[1]

#define ListFront(L)    L->head->next
#define ListBack(L)     L->tail->prev
#define ListNext(N)     N->next
#define ListPrev(N)     N->prev
#define ListData(N)     N->data
#define ListType(L)     L->type
#define ListHead(L)     L->head
#define ListTail(L)     L->tail
#define ListEmpty(L)    (L->head->next == L->tail)

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

List*   ListInit(ListType Ltype, NodeType Ntype);
void    ListAddNode(List *L, Node *newNode);
void    ListInsertNode(List *L, Node *newNode, size_t index);
Node*   ListRemoveNode(List *L, size_t index);
Node*   ListFetchNode(List *L, size_t index);
void    ListFree(List *L);
size_t  ListSize(List *L);

#endif