#include "list.h"

List* listInit(ListType Ltype, NodeType Ntype)
{
    List *newList = (List*)malloc(sizeof(List));    // Aloca memória para Lista
    assert(newList != NULL);                        // Erro de alocação de memória

    newList->type = Ltype;                          // Define o tipo da Lista
    newList->head = nodeInit(Ntype, NULL);          // Inicializa o Nó head
    newList->tail = nodeInit(Ntype, NULL);          // Inicializa o Nó tail

    // Define conexões para listas encadeadas
    newList->head->NEXT = newList->tail;  

    if (Ntype == DOUBLY_LINKED)
        newList->tail->PREV = newList->head;

    // Configuração para lista circular
    if (Ltype == CIRCULAR_LIST)
    {
        newList->tail->NEXT = newList->head;     

        if (Ntype == DOUBLY_LINKED)
            newList->head->PREV = newList->tail; 
    }

    return newList;
}

void listAddNode(List *L, Node *newNode)
{
    Node *aux = L->head;
    while (aux->NEXT != L->tail)
    {
        aux = aux->NEXT;        
    }

    aux->NEXT = newNode;
    newNode->NEXT = L->tail;
    
    if (L->head->type == DOUBLY_LINKED)
    {
        newNode->PREV = aux;
        L->tail->PREV = newNode;
    }
}

void listInsertNode(List *L, Node *newNode, size_t index)
{
    Node* aux = L->head;
    for (size_t i = 0; i < index; i++)
    {
        if (aux->NEXT == L->tail)
        {
            aux->NEXT = newNode;
            newNode->NEXT = L->tail;
            if (L->head->type == DOUBLY_LINKED)
            {
                L->tail->PREV = newNode;
                newNode->PREV = aux;
            }
            return;
        }
        aux = aux->NEXT;
    }

    Node* auxn = aux->NEXT;
    aux->NEXT = newNode;
    newNode->NEXT = auxn;

    if (L->head->type == DOUBLY_LINKED)
    {
        auxn->PREV = newNode;
        newNode->PREV = aux;
    }
}

Node* listRemoveNode(List *L, size_t index)
{
    if (L == NULL || L->head->NEXT == L->tail) return NULL; // Lista vazia, nada a remover

    Node* aux = L->head;
    
    for (size_t i = 0; i < index && aux->NEXT != L->tail; i++)
    {
        aux = aux->NEXT;
    }

    Node *toRemove = aux->NEXT;

    if (toRemove != L->tail) 
    {
        aux->NEXT = toRemove->NEXT;

        if (L->head->type == DOUBLY_LINKED && toRemove->NEXT != NULL)
        {
            ((Node*)toRemove->NEXT)->PREV = aux;
        }

        toRemove->NEXT = NULL;
        toRemove->PREV = NULL;
        return toRemove;
    }

    return NULL;
}

Node* listFetchNode(List *L, size_t index)
{
    if (L == NULL || L->head->NEXT == L->tail) return L->head;  // Lista vazia, retorna head

    Node *aux = L->head;

    for (size_t i = 0; i < index; i++)
    {
        if (aux->NEXT == NULL || aux->NEXT == L->tail)
        {
            return aux;
        }

        aux = aux->NEXT;
    }

    return aux;    
}

void listFree(List *L)
{
    if (L == NULL) return;      // Lista vazia, nada a liberar

    Node *current = L->head;    // Começa pelo primeiro nó
    while (current != NULL)     
    {
        Node *next = current->NEXT; // Salva o próximo nó
        nodeFree(current);          // Libera o nó atual
        current = next;             // Avança para o próximo nó
    }

    free(L); // Libera a estrutura da lista
}