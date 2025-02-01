#include "list.h"

List* ListInit(ListType Ltype, NodeType Ntype)
{
    List *newList = (List*)malloc(sizeof(List));
    assert(newList != NULL);

    newList->head = NULL;
    newList->tail = NULL;

    // Inicializa os nós conforme o tipo
    if (Ntype > 0) 
    {
        newList->head = (Node*)NodeInit(sizeof(Node), NULL);            // Aloca o primeiro nó
        newList->head->links = (void**)malloc(Ntype * sizeof(void*));   // Aloca memória para links
        newList->head->linkCount = 0;
        newList->head->type = Ntype;

        if (Ltype == CIRCULAR_LIST) 
            newList->head->links[0] = newList->head; // Faz a circularidade
    }
    return newList;
}

void FreeList(List* list)
{
    if (list != NULL)
    {
        Node* current = list->head;
        Node* next;

        while (current != NULL)
        {
            next = (Node*)current->links[0]; // Ou outro método de acessar o próximo nó, dependendo da estrutura
            FreeNode(current); // Libera o nó atual
            current = next; // Move para o próximo nó
        }

        free(list); // Libera a estrutura da lista
    }
}