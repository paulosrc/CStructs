#ifndef TREE_H
#define TREE_H

#include "node.h"

#define left  links[0]
#define right links[1]

#define TreeRoot(T)     T->root
#define TreeType(T)     T->type

typedef enum
{
    BINARY_TREE,        // Árvore de busca binária
    AVL_TREE,           // Árvore auto-balanceada
    RED_BLACK_TREE,     // Árvore rubro-negra
    TREE_TYPE_COUNT     // Número de tipos de árvores
} TreeType;

typedef struct tree
{
    Node *root;
    TreeType type;
} Tree;

Tree* TreeInit(NodeType type);
void TreeInsert(Tree *T, Node *node);
#endif