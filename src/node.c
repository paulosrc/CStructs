#include <stdlib.h>
#include <assert.h>
#include "node.h"

Node* NodeInit(size_t structSize, Pointer newData)
{
    Node* newNode = (Node*)malloc(structSize);
    assert(newNode != NULL);

    newNode->data = newData; // Acessa diretamente o campo 'data' do nó

    // Inicializa os links
    newNode->links = (void**)malloc(sizeof(void*) * TYPE_COUNT);
    newNode->linkCount = 0;
    newNode->type = (NodeType)(structSize / sizeof(Node));

    return newNode;
}

void FreeNode(Node* node)
{
    if (node != NULL)
    {
        FreePointer(node->data); // Libera os dados armazenados no nó

        if (node->links != NULL)
        {
            for (int i = 0; i < node->linkCount; i++)
            {
                // Libere cada conexão se necessário, se você estiver usando o mesmo esquema de liberação
                FreeNode((Node*)node->links[i]); // Chame FreeNode recursivamente se necessário
            }
            free(node->links); // Libera o array de links
        }

        free(node); // Libera a memória do nó
    }
}
