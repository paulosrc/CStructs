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

void treeAddNode(Tree *T, Node *newNode, DataType type)
{
    if (T->root == NULL)
    {
        T->root = newNode;
        return;
    }

    Node *current = T->root;
    
    while (1)
    {
        if (compareData(newNode->data, current->data, type) < 0)
        {
            if (current->LEFT == NULL)
            {
                current->LEFT = newNode;
                break;
            }
            current = current->LEFT;
        }
        else if (compareData(newNode->data, current->data, type) > 0)
        {
            if (current->RIGHT == NULL)
            {
                current->RIGHT = newNode;
                break;
            }
            current = current->RIGHT;
        }
        else
        {
            // Nó já está presente na árvore
            break;
        }
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
