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
