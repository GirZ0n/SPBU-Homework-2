#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct List List;
typedef struct ListElement ListElement;

struct List
{
    ListElement* current;
};

struct ListElement
{
    int value;
    ListElement* left;
    ListElement* right;
};

List* createList()
{
    List* list = malloc(sizeof(struct List));
    list->current = NULL;

    return list;
}

ListElement* createListElement(int value)
{
    ListElement* newElement = malloc(sizeof(ListElement));
    newElement->value = value;
    newElement->left = NULL;
    newElement->right = NULL;

    return newElement;
}

void pushBack(int value, List* list)
{
    ListElement* pushed = createListElement(value);
    if (list->current == NULL)
    {
        pushed->left = pushed;
        pushed->right = pushed;
        list->current = pushed;
    }
    else
    {
        ListElement* current = list->current;
        ListElement* last = current->left;

        last->right = pushed;
        current->left = pushed;
        pushed->left = last;
        pushed->right = current;
    }
}

void nextElement(List* list)
{
    list->current = list->current->right;
}

void pop(List* list)
{
    ListElement* current = list->current;
    ListElement* left = current->left;
    ListElement* right = current->right;

    left->right = right;
    right->left = left;
    list->current = right;
    free(current);
}

void printList(int size, List* list)
{
    ListElement* current = list->current;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", current->value);
        current = current->right;
    }
}