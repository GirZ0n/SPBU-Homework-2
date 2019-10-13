#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct List
{
    ListElement* first;
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
    list->first = NULL;

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
    ListElement* firstListElement = list->first;
    if(firstListElement == NULL)
    {
        firstListElement = createListElement(value);
        firstListElement->left = firstListElement;
        firstListElement->right = firstListElement;
        list->first = firstListElement;
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

void pop(ListElement* listElement, List* list)
{
    if (list->first = listElement)
    {
        list->first = listElement->right;
    }

    ListElement* leftListElement = listElement->left;
    ListElement* rightListElement = listElement->right;
    leftListElement->right = rightListElement;
    rightListElement->left = leftListElement;
}

void print(int size, List* list)
{
    ListElement* currentListElement = list->first;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", currentListElement->value);
        currentListElement = currentListElement->right;
    }
}