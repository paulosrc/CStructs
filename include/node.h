#ifndef NODE_H
#define NODE_H

#include "pointer.h"

#define MAX_KEYS 100

typedef struct node
{
    Pointer data;                           // Ponteiro genérico para dados
    struct node *next;                      // Ponteiro para o próximo nó
} Node;

typedef struct doublenode
{
    Pointer data;                           // Ponteiro genérico para dados
    struct doublenode *prev;                // Ponteiro para o próximo nó                      
    struct doublenode *next;                // Ponteiro para o nó anterior
} DoubleNode;

typedef struct triplenode
{
    Pointer data;                           // Ponteiro genérico para dados
    struct triplenode *left;                // Ponteiro para o nó da esquerda
    struct triplenode *middle;              // Ponteiro para o nó do meio
    struct triplenode *right;               // Ponteiro para o nó da direita
} TripleNode;

typedef struct TreeNode 
{
    Pointer data;                           // Ponteiro genérico para dados
    struct TreeNode* left;                  // Ponteiro para a subárvore da esquerda
    struct TreeNode* right;                 // Ponteiro para a subárvore da direita
} TreeNode;


typedef struct NTreeNode 
{
    Pointer data;                           // Ponteiro genérico para dados
    struct NTreeNode* firstChild;           // Ponteiro para a primeira subárvore
    struct NTreeNode* nextSibling;          // Ponteiro para as subárvores seguintes
} NTreeNode;

typedef struct GraphNode 
{
    Pointer data;                           // Ponteiro genérico para dados
    struct GraphNode** adjList;             // Lista de adjacência do grafo
    int adjCount;                           // Contagem para elementos adjacentes
} GraphNode;


Node* NodeInit(Pointer newData);         // Inicializa Nó de lista simplesmente encadeada
DoubleNode* DoubleNodeInit(Pointer newData);   // Inicializa Nó de lista duplamente encadeada
TripleNode* TripleNodeInit(Pointer newData);   // Inicializa Nó de árvore ternária
TreeNode* TreeNodeInit(Pointer newData);     // Inicializa Nó de árvore binária
NTreeNode* NTreeNodeInit(Pointer newData);    // Inicializa Nó de árvore "N"ária
GraphNode* GraphNodeInit(Pointer newData);    // Inicializa Nó de Grafo

#endif