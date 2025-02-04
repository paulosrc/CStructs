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
void  ListInsertNode(List *L, Node *newNode, int index);
void  ListRemoveNode(List *L, int index);
Node* ListFetchNode(List *L, int index);

#endif