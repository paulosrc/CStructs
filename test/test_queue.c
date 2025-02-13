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
    
    printQueue(fila);

    Node *no = QUEUE_DEQUEUE(fila);
    printf("Elemento removido: %d\n", no->data);
    free(no);

    printQueue(fila);

    QUEUE_FREE(fila);
    return 0;
}