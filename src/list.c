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

void ListFree(List* list)
{
    if (list == NULL) return;

    Node* current = list->head;
    Node* next;

    while (current != NULL)
    {
        next = current->links[0];         

        if (current->data != NULL)
            free(current->data);

        free(current->links);           // Liberar os links do nó
        free(current);                  // Liberar o nó em si

        current = next;
    }

    free(list);                         // Libera a memória de Lista
}
