#include "../include/list.h"

void printList(List *list)
{
    Node *aux = list->head;
    while (aux != NULL)
    {
        printf("%c ", *(char*)aux->data);
        
        if (aux->links[0] == list->head)
        {
            break;
        }
        printf("-> ");

        aux = aux->links[0];
    }
    printf("\n");
}

int main()
{
    List *list = listInit(CIRCULAR_LIST, SIMPLY_LINKED);
    
    listAddNode(list, nodeInit(SIMPLY_LINKED, dataToPointer(TYPE_CHAR, 'A')));
    listAddNode(list, nodeInit(SIMPLY_LINKED, dataToPointer(TYPE_CHAR, 'B')));
    listAddNode(list, nodeInit(SIMPLY_LINKED, dataToPointer(TYPE_CHAR, 'C')));
    listAddNode(list, nodeInit(SIMPLY_LINKED, dataToPointer(TYPE_CHAR, 'D')));

    printList(list); // saída: A -> B -> C -> D

    listFree(list);

    return 0;
}