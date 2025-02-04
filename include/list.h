#ifndef LIST_H
#define LIST_H

#include "node.h"

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


#endif