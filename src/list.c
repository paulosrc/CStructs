#include "list.h"

/*
    Sumário de funções:
    1. Inicialização das Listas;
    2. Adição de Novos Nós;
    3. Remoção de Nós;
*/

/*
    1. Inicialização das Listas ----------
*/

List* ListInit()
{
    List *newList = (List*)malloc(sizeof(List));
    if (newList == NULL) 
    {
        // IMPRIMIR ERRO
        return NULL;
    }

    newList->type = SIMPLE_NODE;
    newList->node = NULL;
    newList->next = NULL;

    return newList;
}

DoubleList* DoubleListInit()
{
    DoubleList *newList = (DoubleList*)malloc(sizeof(DoubleList));
    if (newList == NULL) 
    {
        // IMPRIMIR ERRO
        return NULL;
    }

    newList->type = DOUBLE_NODE;
    newList->node = NULL;
    newList->next = NULL;
    newList->prev = NULL;

    return newList;
}

CircularList* CircularListInit()
{
    CircularList *newList = (CircularList*)malloc(sizeof(CircularList));
    if (newList == NULL) 
    {
        // IMPRIMIR ERRO
        return NULL;
    }

    newList->head = NULL;
    newList->tail = NULL;
    newList->tail->next = newList->head;

    return newList;
}

/*
    2. Adição de um Novo nó ----------
*/

void addNewNode(List *L)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        // IMPRIMIR ERRO
        return;
    }

    while (L->next != NULL)
        L = L->next;
    L->next = newNode;
}