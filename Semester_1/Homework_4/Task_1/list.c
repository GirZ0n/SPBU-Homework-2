#include "list.h"
#include <stdlib.h>
#include <stdio.h>

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
    ListElement* listElement = malloc(sizeof(ListElement));
    listElement->value = value;
    listElement->left = NULL;
    listElement->right = NULL;

    return listElement;
}

void pushBack(int value, List* list)
{
    ListElement* newElement = createListElement(value);
    if (list->current == NULL)
    {
        newElement->left = newElement;
        newElement->right = newElement;
        list->current = newElement;
    }
    else
    {
        ListElement* current = list->current;
        ListElement* last = current->left;

        last->right = newElement;
        current->left = newElement;
        newElement->left = last;
        newElement->right = current;
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
    for (int i = 0; i < size; i++) {
        printf("%d ", current->value);
        current = current->right;
    }
}