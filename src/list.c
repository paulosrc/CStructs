#include "list.h"

List* ListInit(ListType Ltype, NodeType Ntype)
{
    List *newList = (List*)malloc(sizeof(List));    // Aloca memória para Lista
    assert(newList != NULL);                        // Erro de alocação de memória

    newList->type = Ltype;                          // Define o tipo da Lista
    newList->head = NodeInit(Ntype, NULL);          // Inicializa o Nó head
    newList->tail = NodeInit(Ntype, NULL);          // Inicializa o Nó tail

    // Define conexões para listas encadeadas
    newList->head->next = newList->tail;  

    if (Ntype == DOUBLY_LINKED)
        newList->tail->prev = newList->head;

    // Configuração para lista circular
    if (Ltype == CIRCULAR_LIST)
    {
        newList->tail->next = newList->head;     

        if (Ntype == DOUBLY_LINKED)
            newList->head->prev = newList->tail; 
    }

    return newList;
}

void ListAddNode(List *L, Node *newNode)
{
    Node *aux = L->head;
    while (aux->next != L->tail)
    {
        aux = aux->next;        
    }

    aux->next = newNode;
    newNode->next = L->tail;
    
    if (L->head->type == DOUBLY_LINKED)
    {
        newNode->prev = aux;
        L->tail->prev = newNode;
    }
}

void ListInsertNode(List *L, Node *newNode, size_t index)
{
    Node* aux = L->head;
    for (size_t i = 0; i < index; i++)
    {
        if (aux->next == L->tail)
        {
            aux->next = newNode;
            newNode->next = L->tail;
            if (L->head->type == DOUBLY_LINKED)
            {
                L->tail->prev = newNode;
                newNode->prev = aux;
            }
            return;
        }
        aux = aux->next;
    }

    Node* auxn = aux->next;
    aux->next = newNode;
    newNode->next = auxn;

    if (L->head->type == DOUBLY_LINKED)
    {
        auxn->prev = newNode;
        newNode->prev = aux;
    }
}

Node* ListRemoveNode(List *L, size_t index)
{
    if (L == NULL || L->head->next == L->tail) return NULL; // Lista vazia, nada a remover

    Node* aux = L->head;
    
    for (size_t i = 0; i < index && aux->next != L->tail; i++)
    {
        aux = aux->next;
    }

    Node *toRemove = aux->next;

    if (toRemove != L->tail) 
    {
        aux->next = toRemove->next;

        if (L->head->type == DOUBLY_LINKED && toRemove->next != NULL)
        {
            ((Node*)toRemove->next)->prev = aux;
        }

        toRemove->next = NULL;
        toRemove->prev = NULL;
        return toRemove;
    }

    return NULL;
}

Node* ListFetchNode(List *L, size_t index)
{
    if (L == NULL || L->head->next == L->tail) return L->head;  // Lista vazia, retorna head

    Node *aux = L->head;

    for (size_t i = 0; i < index; i++)
    {
        if (aux->next == NULL || aux->next == L->tail)
        {
            return aux;
        }

        aux = aux->next;
    }

    return aux;    
}

void ListFree(List *L)
{
    if (L == NULL) return;      // Lista vazia, nada a liberar

    Node *current = L->head;    // Começa pelo primeiro nó
    while (current != NULL)     
    {
        Node *next = current->next; // Salva o próximo nó
        NodeFree(current);          // Libera o nó atual
        current = next;             // Avança para o próximo nó
    }

    free(L); // Libera a estrutura da lista
}