#ifndef TREE_H
#define TREE_H

#include "node.h"

#define LEFT  links[0]
#define RIGHT links[1]

#define TREE_ROOT(T) T->root
#define TREE_TYPE(T) T->type
#define TREE_IS_EMPTY(T) (T->root == NULL)
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

Tree* treeInit(TreeType Ttype, NodeType Ntype, DataType Dtype); // Inicializa árvore vazia
void treeAddNode(Tree *T, Node *newNode, DataType type);        // Adiciona nó à árvore
void treeFreeNodes(Node *root, DataType type);                  // Libera memória alocada para nós da árvore
void treeFree(Tree *T);                                         // Libera memória alocada para a árvore

#endif