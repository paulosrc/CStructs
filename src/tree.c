#include "../include/tree.h"

Tree* treeInit(TreeType Ttype, NodeType Ntype, DataType Dtype)
{
    Tree *T = (Tree*)malloc(sizeof(Tree));
    assert(T != NULL); // Erro de alocação de memória
    
    T->root = nodeInit(Ntype, NULL);
    assert(T->root != NULL); // Erro de alocação de memória

    T->type = Ttype;
    
    return T;
}

void binTreeAddNode(Node *root, Node *newNode, DataType type)
{
    if (newNode == NULL) return;
    if (root == NULL) root = newNode; // Se a árvore estiver vazia, o novo nó é a raiz

    if (compareData(newNode->data, root->data, type) < 0)
    {
        if (root->LEFT == NULL) root->LEFT = newNode;
        else binTreeAddNode(root->LEFT, newNode, type);
    }
    else if (compareData(newNode->data, root->data, type) > 0)
    {
        if (root->RIGHT == NULL) root->RIGHT = newNode;
        else binTreeAddNode(root->RIGHT, newNode, type);
    }
    else
    {
        // Árvore Binária não acomoda chaves duplicadas
        return;
    }
}

void avlTreeAddNode(Node *root, Node *newNode, DataType type)
{

}

void rbTreeAddNode(Node *root, Node *newNode, DataType type)
{

}

void treeAddNode(Tree *T, Node *newNode, DataType type)
{
    if (newNode == NULL) return;
    if (T == NULL) T->root = newNode; // Se a árvore estiver vazia, o novo nó é a raiz

    Node *current = T->root;

    if (T->type == BINARY_TREE)
    {
        // Implementar adição de nó para árvore de busca binária
        // https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
    }
    else if (T->type == AVL_TREE)
    {
        // Implementar adição de nó para árvore AVL
        // https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
    }
    else if (T->type == RED_BLACK_TREE)
    {
        // Implementar adição de nó para árvore rubro-negra
        // https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/
    }
    else
    {
        // Tipo de árvore não suportado
        return;
    }
}

void treeFreeNodes(Node *root, DataType type)
{
    if (root == NULL) return;

    // Primeiro libera os filhos (recursivamente)
    treeFreeNodes(root->LEFT, type);
    treeFreeNodes(root->RIGHT, type);

    // Libera os dados armazenados no nó
    freePointer(root->data);

    // Libera o próprio nó
    nodeFree(root);
}

void treeFree(Tree *T)
{
    if (T == NULL) return;
    treeFreeNodes(T->root, TREE_TYPE(T)); // Libera os nós da árvore
    free(T); // Libera a árvore
}