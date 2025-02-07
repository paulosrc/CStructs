#include "../include/list.h"

void imprimir_lista(List *list)
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
    List *list = ListInit(CIRCULAR_LIST, SIMPLY_LINKED);
    
    ListAddNode(list, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_CHAR, 'A')));
    ListAddNode(list, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_CHAR, 'B')));
    ListAddNode(list, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_CHAR, 'C')));
    ListAddNode(list, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_CHAR, 'D')));

    imprimir_lista(list); // saída: A -> B -> C -> D

    ListFree(list);

    return 0;
}