#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "pointer.h"

/*
---------------------------------------------------------------------------------------------------
Structs
---------------------------------------------------------------------------------------------------
*/

typedef enum 
{
    SIMPLE_NODE,            // Nó de lista simplesmente encadeada
    DOUBLE_NODE             // Nó de lista duplamente encadeada
} NodeType;

typedef struct Node 
{
    NodeType type;          // Tipo do nó (simples ou duplo)
    Pointer node;           // Ponteiro para o nó específico
    struct Node *next;      // Próximo nó na lista genérica
} Node;

typedef struct DoubleNode
{
    NodeType type;
    Pointer node; 
    struct DoubleNode *next;
    struct DoubleNode *prev;
} DoubleNode;

typedef struct CircularList
{
    Node *head;
    Node *tail;
} CircularList;

typedef Node List;              // Define List como alias para o tipo Node
typedef DoubleNode DoubleList;  // Define DoubleList como alias para o tipo DoubleNode

/*
---------------------------------------------------------------------------------------------------
Assinatura de Funções
---------------------------------------------------------------------------------------------------
*/

List* ListInit();
DoubleList* DoubleListInit();
CircularList* CircularListInit();

void addNewNode(List *L);
void addNewDoubleNode(DoubleList *D);
void addNewNodeCircular(CircularList *C);

#endif