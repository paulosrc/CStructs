#include <stdio.h>
#include <stdlib.h>
#include "../include/node.h"

void printQueue(Node *head)
{
    Node *aux = head;
    while (aux != NULL)
    {
        printf("%c ", *(char*)aux->data);
        
        if (aux->links[0] == head)
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
    // Criando uma lista encadeada simples circular manualmente usando a função nodeInit;
    Node *node1 = nodeInit(SIMPLY_LINKED, NULL);
    Node *node2 = nodeInit(SIMPLY_LINKED, NULL);
    Node *node3 = nodeInit(SIMPLY_LINKED, NULL);
    Node *node4 = nodeInit(SIMPLY_LINKED, NULL);

    // Realizando as ligações
    node1->links[0] = node2;
    node1->linkCount++;
    node1->data = dataToPointer(TYPE_CHAR, 'A');

    node2->links[0] = node3;
    node2->linkCount++;
    node2->data = dataToPointer(TYPE_CHAR, 'B');

    node3->links[0] = node4;
    node3->linkCount++;
    node3->data = dataToPointer(TYPE_CHAR, 'C');

    node4->links[0] = node1;
    node4->linkCount++;
    node4->data = dataToPointer(TYPE_CHAR, 'D');

    printQueue(node1); // saída: A -> B -> C -> D

    nodeFree(node1);
    nodeFree(node2);
    nodeFree(node3);
    nodeFree(node4);

    return 0;
}