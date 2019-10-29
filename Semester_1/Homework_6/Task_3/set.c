#include <stdlib.h>
#include "set.h"

struct Set
{
    struct SetElmenet* root;
};

struct SetElement
{
    int value;
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

SetElement* createSetElement()
{
    SetElement* element = malloc(sizeof(SetElement));
    element->value = 0;
    element->leftChild = NULL;
    element->rightChild = NULL;

    return element;
}

SetElement* getSetElement(int number, Set* set)
{
    SetElement* current = set->root;
    while (current != NULL)
    {
        if (current->value == number)
        {
            return current;
        }
        else if (current->value < number)
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

bool isContained(int number, Set* set)
{
    return getSetElement(number, set) != NULL;
}