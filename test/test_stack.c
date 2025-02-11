#include "../include/stack.h"

void print_stack(Stack *pilha)
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

    print_stack(pilha); // saída: 1 -> 2 -> 3 -> 4 -> 5

    StackPop(pilha);

    printf("Elemento desempilhado.\n");

    print_stack(pilha); // saída: 1 -> 2 -> 3 -> 4

    QueueFree(pilha);
    return 0;
}