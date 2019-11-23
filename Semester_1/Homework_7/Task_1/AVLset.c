#include <stdlib.h>
#include <stdio.h>
#include "AVLset.h"

struct Set
{
    struct Node* root;
};

struct Node
{
    int value;
    int height;
    struct Node* leftChild;
    struct Node* rightChild;
};

typedef struct Set Set;
typedef struct Node Node;

int getHeight(Node* node)
{
    return node ? node->height : -1;
}

int getBalanceFactor(Node* node)
{
    return getHeight(node->rightChild) - getHeight(node->leftChild);
}

int max(int elementA, int elementB)
{
    return elementA > elementB ? elementA : elementB;
}

void updateHeight(Node* node)
{
    int heightLeftChild = getHeight(node->leftChild);
    int heightRightChild = getHeight(node->rightChild);
    node->height = max(heightLeftChild, heightRightChild) + 1;
}

Set* createSet()
{
    Set* set = malloc(sizeof(Set));
    set->root = NULL;

    return set;
}

Node* createNode(int value)
{
    Node* element = malloc(sizeof(Node));
    element->value = value;
    element->height = 0;
    element->leftChild = NULL;
    element->rightChild = NULL;

    return element;
}

Node* getSetElement(int value, Set* set)
{
    Node* current = set->root;
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
    return getSetElement(value, set) != NULL;
}

void printSubtreeInAscendingOrder(Node* root)
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

void printSubtreeInDescendingOrder(Node* root)
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

void printSubtree(Node* root)
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
    printSubtree(set->root);
}

Node* rotateRight(Node* root)
{
    Node* pivot = root->leftChild;
    root->leftChild = pivot->rightChild;
    pivot->rightChild = root;
    updateHeight(root);
    updateHeight(pivot);

    return pivot;
}

Node* rotateLeft(Node* root)
{
    Node* pivot = root->rightChild;
    root->rightChild = pivot->leftChild;
    pivot->leftChild = root;
    updateHeight(root);
    updateHeight(pivot);

    return pivot;
}

Node* balance(Node* root)
{
    updateHeight(root);

    if (getBalanceFactor(root) == 2)
    {
        if (getBalanceFactor(root->rightChild) < 0)
        {
            root->rightChild = rotateRight(root->rightChild);
        }

        return rotateLeft(root);
    }

    if (getBalanceFactor(root) == -2)
    {
        if (getBalanceFactor(root->leftChild) > 0)
        {
            root->leftChild = rotateLeft(root->leftChild);
        }

        return rotateRight(root);
    }

    return root;
}

Node* addElementInSubtree(int value, Node* root)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->value)
    {
        root->leftChild = addElementInSubtree(value, root->leftChild);
    }
    else if (value > root->value)
    {
        root->rightChild = addElementInSubtree(value, root->rightChild);
    }

    return balance(root);
}

bool addElement(int value, Set* set)
{
    if (!isContained(value, set))
    {
        set->root = addElementInSubtree(value, set->root);
        return true;
    }
    return false;
}

Node* getMinimumNodeFromRightSubtree(Node* root)
{
    if (root->leftChild != NULL)
    {
        return getMinimumNodeFromRightSubtree(root->leftChild);
    }

    return root;
}

Node* removeMinimumNodeFromRightSubtree(Node* root)
{
    if (root->leftChild == NULL)
    {
        return root->rightChild;
    }

    root->leftChild = removeMinimumNodeFromRightSubtree(root->leftChild);
    return balance(root);
}

Node* removeElementFromSubtree(int value, Node* root)
{
    if (value < root->value)
    {
        root->leftChild = removeElementFromSubtree(value, root->leftChild);
    }
    else if (value > root->value)
    {
        root->rightChild = removeElementFromSubtree(value, root->rightChild);
    }
    else
    {
        Node* leftChild = root->leftChild;
        Node* rightChild = root->rightChild;

        if (rightChild == NULL)
        {
            return leftChild;
        }

        Node* minimum = getMinimumNodeFromRightSubtree(rightChild);
        minimum->rightChild = removeMinimumNodeFromRightSubtree(rightChild);
        minimum->leftChild = leftChild;
        free(root);
        return balance(minimum);
    }

    return balance(root);
}

bool removeElement(int value, Set* set)
{
    if (isContained(value, set))
    {
        set->root = removeElementFromSubtree(value, set->root);
        return true;
    }
    return false;
}