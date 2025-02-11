#include "../include/queue.h"

void print_queue(Queue *fila)
{
    Node *aux = QueueFront(fila);
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        if (aux == QueueBack(fila))
        {
            break;
        }
        printf("-> ");
        aux = aux->next;
    }
    printf("\n");
}

int main()
{
    Queue *fila = QueueInit(LINEAR_QUEUE, SIMPLY_LINKED);
    
    QueueEnqueue(fila, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_INT, 1)));
    QueueEnqueue(fila, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_INT, 2)));
    QueueEnqueue(fila, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_INT, 3)));
    QueueEnqueue(fila, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_INT, 4)));
    QueueEnqueue(fila, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_INT, 5)));
    
    print_queue(fila);

    Node *no = QueueDequeue(fila);
    printf("Elemento removido: %d\n", no->data);
    free(no);

    print_queue(fila);

    QueueFree(fila);
    return 0;
}