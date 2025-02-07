#include <stdio.h>
#include <stdlib.h>
#include "../include/node.h"

void imprimir_fila(Node *head)
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

    // Realizando as ligações
    node1->links[0] = node2;
    node1->linkCount++;
    node1->data = DataToPointer(TYPE_CHAR, 'A');

    node2->links[0] = node3;
    node2->linkCount++;
    node2->data = DataToPointer(TYPE_CHAR, 'B');

    node3->links[0] = node1;
    node3->linkCount++;
    node3->data = DataToPointer(TYPE_CHAR, 'C');

    imprimir_fila(node1); // saída: A -> B -> C

    NodeFree(node1);
    NodeFree(node2);
    NodeFree(node3);

    return 0;
}