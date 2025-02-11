#include "../include/tree.h"

Tree* TreeInit(TreeType Ttype, NodeType Ntype, DataType Dtype)
{
    Tree *T = (Tree*)malloc(sizeof(Tree));
    assert(T != NULL); // Erro de alocação de memória
    
    T->root = NodeInit(Ntype, NULL);
    assert(T->root != NULL); // Erro de alocação de memória

    T->type = Ttype;
    
    return T;
}

void TreeAddNode(Tree *T, Node *newNode, DataType type)
{
    if (T->root == NULL)
    {
        T->root = newNode;
        return;
    }

    Node *current = T->root;
    
    while (1)
    {
        if (CompareData(newNode->data, current->data, type) < 0)
        {
            if (current->left == NULL)
            {
                current->left = newNode;
                break;
            }
            current = current->left;
        }
        else if (CompareData(newNode->data, current->data, type) > 0)
        {
            if (current->right == NULL)
            {
                current->right = newNode;
                break;
            }
            current = current->right;
        }
        else
        {
            // Nó já está presente na árvore
            break;
        }
    }
}

