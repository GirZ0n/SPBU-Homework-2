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
    ListElement* newListElement = createListElement(value);
    if (list->current == NULL)
    {
        newListElement->left = newListElement;
        newListElement->right = newListElement;
        list->current = newListElement;
    }
    else
    {
        ListElement* currentListElement = list->current;
        ListElement* lastListElement = currentListElement->left;

        lastListElement->right = newListElement;
        currentListElement->left = newListElement;
        newListElement->left = lastListElement;
        newListElement->right = currentListElement;
    }
}

void nextElement(List* list)
{
    list->current = list->current->right;
}

void pop(List* list)
{
    ListElement* currentListElement = list->current;
    ListElement* leftListElement = currentListElement->left;
    ListElement* rightListElement = currentListElement->right;

    leftListElement->right = rightListElement;
    rightListElement->left = leftListElement;
    list->current = rightListElement;
    free(currentListElement);
}

void printList(int size, List* list)
{
    ListElement* currentListElement = list->current;
    for (int i = 0; i < size; i++) {
        printf("%d ", currentListElement->value);
        currentListElement = currentListElement->right;
    }
}