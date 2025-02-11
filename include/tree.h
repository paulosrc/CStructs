#ifndef TREE_H
#define TREE_H

#include "node.h"

#define left  links[0]
#define right links[1]

#define TreeRoot(T) T->root
#define TreeType(T) T->type
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

Tree* TreeInit(TreeType Ttype, NodeType Ntype, DataType Dtype); // Inicializa árvore vazia
void TreeAddNode(Tree *T, Node *newNode, DataType type);        // Adiciona nó à árvore
void TreeFreeNodes(Node *root, DataType type);                  // Libera memória alocada para nós da árvore
void TreeFree(Tree *T);                                         // Libera memória alocada para a árvore

#endif