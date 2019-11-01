#include <stdlib.h>
#include <stdio.h>
#include "set.h"

struct Set
{
    struct SetElement* root;
};

struct SetElement
{
    int value;
    struct SetElement* parent;
    struct SetElement* leftChild;
    struct SetElement* rightChild;
};

typedef struct Set Set;
typedef struct SetElement SetElement;

Set* createSet()
{
    Set* set = malloc(sizeof(Set));
    set->root = NULL;

    return set;
}

SetElement* createSetElement(int value, SetElement* parent)
{
    SetElement* element = malloc(sizeof(SetElement));
    element->value = value;
    element->parent = parent;
    element->leftChild = NULL;
    element->rightChild = NULL;

    return element;
}

SetElement* getSetElement(int value, Set* set)
{
    SetElement* current = set->root;
    while (current != NULL)
    {
        if (current->value == value)
        {
            return current;
        }
        else if (current->value < value)
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }

    return NULL;
}

bool isContained(int value, Set* set)
{
    return getSetElement(value, set) != NULL;
}

void addElement(int value, Set* set)
{
    SetElement* current = set->root;
    while (current != NULL)
    {
        if (current->value > value)
        {
            if (current->leftChild == NULL)
            {
                current->leftChild = createSetElement(value, current);
                return;
            }
            else
            {
                current = current->leftChild;
            }
        }
        else if (current->value < value)
        {
            if (current->rightChild == NULL)
            {
                current->rightChild = createSetElement(value, current);
                return;
            }
            else
            {
                current = current->rightChild;
            }
        }
        else
        {
            return;
        }
    }

    set->root = createSetElement(value, NULL);
}

void printSubtreeInAscendingOrder(SetElement* root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        printf("%d ", root->value);
        return;
    }

    printSubtreeInAscendingOrder(root->leftChild);
    printf("%d ", root->value);
    printSubtreeInAscendingOrder(root->rightChild);
}

void printInAscendingOrder(Set* set)
{
    printSubtreeInAscendingOrder(set->root);
}

void printSubtreeInDescendingOrder(SetElement* root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        printf("%d ", root->value);
        return;
    }

    printSubtreeInDescendingOrder(root->rightChild);
    printf("%d ", root->value);
    printSubtreeInDescendingOrder(root->leftChild);
}

void printInDescendingOrder(Set* set)
{
    printSubtreeInDescendingOrder(set->root);
}

void printSubtree(SetElement* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }

    printf("(%d ", root->value);
    printSubtree(root->leftChild);
    printSubtree(root->rightChild);
    printf(") ");
}

void printSet(Set* set)
{
    printSubtree(set->root);
}