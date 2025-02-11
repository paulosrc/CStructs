#include <stdio.h>
#include <stdlib.h>
#include "../include/node.h"

void print_queue(Node *head)
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
    // Criando uma lista encadeada simples circular manualmente usando a função NodeInit;
    Node *node1 = NodeInit(SIMPLY_LINKED, NULL);
    Node *node2 = NodeInit(SIMPLY_LINKED, NULL);
    Node *node3 = NodeInit(SIMPLY_LINKED, NULL);
    Node *node4 = NodeInit(SIMPLY_LINKED, NULL);

    // Realizando as ligações
    node1->links[0] = node2;
    node1->linkCount++;
    node1->data = DataToPointer(TYPE_CHAR, 'A');

    node2->links[0] = node3;
    node2->linkCount++;
    node2->data = DataToPointer(TYPE_CHAR, 'B');

    node3->links[0] = node4;
    node3->linkCount++;
    node3->data = DataToPointer(TYPE_CHAR, 'C');

    node4->links[0] = node1;
    node4->linkCount++;
    node4->data = DataToPointer(TYPE_CHAR, 'D');

    print_queue(node1); // saída: A -> B -> C -> D

    NodeFree(node1);
    NodeFree(node2);
    NodeFree(node3);
    NodeFree(node4);

    return 0;
}