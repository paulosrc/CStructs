#ifndef LIST_H
#define LIST_H

#include "node.h"

#define next links[0]
#define prev links[1]

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

List* ListInit(ListType Ltype, NodeType Ntype);
void  ListAddNode(List *L, Node *newNode);
void  ListInsertNode(List *L, Node *newNode, size_t index);
void  ListRemoveNode(List *L, size_t index);
Node* ListFetchNode(List *L, size_t index);
void  ListFree(List *L);

#endif