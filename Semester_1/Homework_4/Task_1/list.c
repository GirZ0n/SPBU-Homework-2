#include "list.h"
#include <stdlib.h>
#include <stdio.h>

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
    ListElement* firstListElement = list->current;
    if(firstListElement == NULL)
    {
        firstListElement = createListElement(value);
        firstListElement->left = firstListElement;
        firstListElement->right = firstListElement;
        list->current = firstListElement;
    }
    else
    {
        ListElement* lastListElement = firstListElement->left;
        ListElement* listElement = createListElement(value);

        listElement->left = lastListElement;
        listElement->right = firstListElement;
        lastListElement->right = listElement;
        firstListElement->left = listElement;
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
}

void printList(int size, List* list)
{
    ListElement* currentListElement = list->current;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", currentListElement->value);
        currentListElement = currentListElement->right;
    }
}