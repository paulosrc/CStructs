#include "../include/queue.h"

void printQueue(Queue *fila)
{
    Node *aux = QUEUE_FRONT(fila);
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        if (aux ==  QUEUE_BACK(fila))
        {
            break;
        }
        printf("-> ");
        aux = aux->NEXT;
    }
    printf("\n");
}

int main()
{
    Queue *fila = QUEUE_INIT(LINEAR_QUEUE, SIMPLY_LINKED);
    
    QUEUE_ENQUEUE(fila, nodeInit(SIMPLY_LINKED, dataToPointer(TYPE_INT, 1)));
    QUEUE_ENQUEUE(fila, nodeInit(SIMPLY_LINKED, dataToPointer(TYPE_INT, 2)));
    QUEUE_ENQUEUE(fila, nodeInit(SIMPLY_LINKED, dataToPointer(TYPE_INT, 3)));
    QUEUE_ENQUEUE(fila, nodeInit(SIMPLY_LINKED, dataToPointer(TYPE_INT, 4)));
    QUEUE_ENQUEUE(fila, nodeInit(SIMPLY_LINKED, dataToPointer(TYPE_INT, 5)));
    
    printQueue(fila);   // saída: 1 -> 2 -> 3 -> 4 -> 5

    Node *no = QUEUE_DEQUEUE(fila);
    printf("Elemento removido: %d\n", no->data); // Primeiro elemento a sair é: 1
    nodeFree(no);

    printQueue(fila);   // saída: 2 -> 3 -> 4 -> 5

    QUEUE_FREE(fila);
    return 0;
}