#include <stdlib.h>
#include <stdio.h>
#include "set.h"

typedef struct SetElement SetElement;

struct Set
{
    SetElement* root;
};

struct SetElement
{
    int value;
    SetElement* parent;
    SetElement* leftChild;
    SetElement* rightChild;
};

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
        else if (current->value > value)
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
    if (set == NULL)
    {
        return false;
    }

    return getSetElement(value, set) != NULL;
}

void addElement(int value, Set* set)
{
    if (set == NULL)
    {
        return;
    }

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
    if (set == NULL)
    {
        return;
    }

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
    if (set == NULL)
    {
        return;
    }

    printSubtreeInDescendingOrder(set->root);
}

void printSubtree(SetElement* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }

    printf("( %d ", root->value);
    printSubtree(root->leftChild);
    printSubtree(root->rightChild);
    printf(") ");
}

void printSet(Set* set)
{
    if (set == NULL)
    {
        return;
    }

    printSubtree(set->root);
}

int popMinimumValueFromRightSubtree(SetElement* root)
{
    SetElement* minimum = root;
    while (minimum->leftChild != NULL)
    {
        minimum = minimum->leftChild;
    }

    if (minimum->parent->leftChild == minimum)
    {
        if (minimum->rightChild != NULL)
        {
            minimum->parent->leftChild = minimum->rightChild;
            minimum->rightChild->parent = minimum->parent;
        }
        else
        {
            minimum->parent->leftChild = NULL;
        }
    }
    else
    {
        if (minimum->rightChild != NULL)
        {
            minimum->parent->rightChild = minimum->rightChild;
            minimum->rightChild->parent = minimum->parent;
        }
        else
        {
            minimum->parent->rightChild = NULL;
        }
    }

    int valueOfMinimum = minimum->value;
    free(minimum);
    return valueOfMinimum;
}

void removeLeaf(bool isLeftChild, Set* set, SetElement* leaf)
{
    if (leaf->parent != NULL)
    {
        if (isLeftChild)
        {
            leaf->parent->leftChild = NULL;
        }
        else
        {
            leaf->parent->rightChild = NULL;
        }
    }
    else
    {
        set->root = NULL;
    }
    free(leaf);
}

void removeNodeWithLeftChild(bool isLeftChild, Set* set, SetElement* removable)
{
    if (removable->parent != NULL)
    {
        if (isLeftChild)
        {
            removable->parent->leftChild = removable->leftChild;
            removable->leftChild->parent = removable->parent;
        }
        else
        {
            removable->parent->rightChild = removable->leftChild;
            removable->leftChild->parent = removable->parent;
        }
    }
    else
    {
        set->root = removable->leftChild;
        removable->leftChild->parent = NULL;
    }
    free(removable);
}

void removeNodeWithRightChild(bool isLeftChild, Set* set, SetElement* removable)
{
    if (removable->parent != NULL)
    {
        if (isLeftChild)
        {
            removable->parent->leftChild = removable->rightChild;
            removable->rightChild->parent = removable->parent;
        }
        else
        {
            removable->parent->rightChild = removable->rightChild;
            removable->rightChild->parent = removable->parent;
        }
    }
    else
    {
        set->root = removable->rightChild;
        removable->rightChild->parent = NULL;
    }
    free(removable);
}

bool removeElement(int value, struct Set* set)
{
    SetElement* removable = getSetElement(value, set);
    if (set == NULL || removable == NULL)
    {
        return false;
    }

    bool isLeftChild = false;
    if (removable->parent != NULL)
    {
        isLeftChild = (removable->parent->leftChild == removable);
    }

    if (removable->leftChild != NULL && removable->rightChild != NULL)
    {
        removable->value = popMinimumValueFromRightSubtree(removable->rightChild);
    }
    else if (removable->leftChild != NULL)
    {
        removeNodeWithLeftChild(isLeftChild, set, removable);
    }
    else if (removable->rightChild != NULL)
    {
        removeNodeWithRightChild(isLeftChild, set, removable);
    }
    else
    {
        removeLeaf(isLeftChild, set, removable);
    }

    return true;
}

void deleteSubtree(SetElement* root)
{
    if (root == NULL)
    {
        return;
    }

    deleteSubtree(root->leftChild);
    deleteSubtree(root->rightChild);
    free(root);
}

void deleteSet(Set* set)
{
    if (set == NULL)
    {
        return;
    }

    deleteSubtree(set->root);
    free(set);
}