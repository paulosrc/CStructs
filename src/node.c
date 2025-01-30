#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "node.h"

Node* NodeInit(Pointer newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    assert(newNode != NULL);

    newNode->data = newData;
    newNode->next = NULL;

    return newNode;
}

DoubleNode* DoubleNodeInit(Pointer newData)
{
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    assert(newNode != NULL);

    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

TripleNode* TripleNodeInit(Pointer newData)
{
    TripleNode* newNode = (TripleNode*)malloc(sizeof(TripleNode));
    assert(newNode != NULL);

    newNode->data = newData;
    newNode->left = NULL;
    newNode->middle = NULL;
    newNode->right = NULL;

    return newNode;
}

TreeNode* TreeNodeInit(Pointer newData)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    assert(newNode != NULL);

    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

NTreeNode* NTreeNodeInit(Pointer newData)
{
    NTreeNode* newNode = (NTreeNode*)malloc(sizeof(NTreeNode));
    assert(newNode != NULL);

    newNode->data = newData;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;

    return newNode;
}

GraphNode* GraphNodeInit(Pointer newData)
{
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    assert(newNode != NULL);

    newNode->data = newData;
    newNode->adjList = NULL;
    newNode->adjCount = 0;

    return newNode; 
}