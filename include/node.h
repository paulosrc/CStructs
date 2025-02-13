#ifndef NODE_H
#define NODE_H

#include "pointer.h"

typedef enum
{
    SIMPLY_LINKED = 1,  // Nó que se liga a apenas um nó diferente
    DOUBLY_LINKED = 2,  // Nó que se liga a até dois nós diferentes
    TRIPLY_LINKED = 3,  // Nó que se liga a até três nós diferentes
    TYPE_COUNT          // Contagem dos tipos de nós
} NodeType;

typedef struct Node
{
    Pointer data;       // Ponteiro para os dados armazenados
    Pointer* links;     // Array de ponteiros para conexões
    int linkCount;      // Número de conexões ativas
    NodeType type;      // Número de conexões possíveis
} Node;

Node* nodeInit(NodeType type, Pointer newData);
void nodeFree(Node* node);

#endif