#include "../include/stack.h"

void imprimir_pilha(Stack *pilha)
{
    Node *aux = StackTop(pilha);
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        if (aux == StackBottom(pilha))
        {
            break;
        }
        printf("-> ");
        aux = aux->prev;
    }
    printf("\n");
}

int main()
{
    Stack *pilha = StackInit(LINEAR_STACK, SIMPLY_LINKED);

    StackPush(pilha, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_INT, 1)));
    StackPush(pilha, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_INT, 2)));
    StackPush(pilha, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_INT, 3)));
    StackPush(pilha, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_INT, 4)));
    StackPush(pilha, NodeInit(SIMPLY_LINKED, DataToPointer(TYPE_INT, 5)));

    imprimir_pilha(pilha);

    StackPop(pilha);

    printf("Elemento desempilhado.\n");

    imprimir_pilha(pilha);

    QueueFree(pilha);
    return 0;
}