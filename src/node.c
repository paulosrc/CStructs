#include <stdlib.h>
#include <assert.h>
#include "node.h"

Node* nodeInit(NodeType type, Pointer newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    assert(newNode != NULL); // Erro de alocação de memória

    newNode->data = newData;

    // Inicializa os links de acordo com o tipo de nó
    newNode->type = type;
    newNode->linkCount = 0;
    newNode->links = (Pointer*)malloc(sizeof(Pointer) * type);
    assert(newNode->links != NULL);

    return newNode;
}

void nodeFree(Node* node)
{
    if (node == NULL) return;                       // Caso node seja NULL

    freePointer(node->data);                        // Libera memória 
    if (node->links != NULL)
    {
        for (int i = 0; i < node->linkCount; i++)
            nodeFree((Node*)node->links[i]);        // Chama nodeFree recursivamente se necessário
        free(node->links);                          // Libera o array de links
    }
    
    free(node);                                     // Libera a memória do nó
}