#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct ListElement ListElement;

struct List
{
    int size;
    ListElement* front;
    ListElement* back;
};

struct ListElement
{
    int value;
    ListElement* next;
};

List* createList()
{
    List* new = malloc(sizeof(List));
    new->size = 0;
    new->back = NULL;
    new->front = NULL;
}

ListElement* createListElement(int value)
{
    ListElement* new = malloc(sizeof(ListElement));
    new->value = value;
    new->next = NULL;
}

int getSize(List* list)
{
    if (list == NULL)
    {
        return 0;
    }
    else
    {
        return list->size;
    }
}

bool isEmpty(struct List* list)
{
    return getSize(list) == 0;
}

void pushBack(int value, struct List* list)
{
    if (list == NULL)
    {
        return;
    }

    ListElement* new = createListElement(value);
    if (isEmpty(list))
    {
        list->front = new;
        list->back = new;
    }
    else
    {
        list->back->next = new;
        list->back = new;
    }
    list->size++;
}

void pushFront(int value, struct List* list)
{
    if (list == NULL)
    {
        return;
    }

    ListElement* new = createListElement(value);
    if (isEmpty(list))
    {
        list->front = new;
        list->back = new;
    }
    else
    {
        new->next = list->front;
        list->front = new;
    }
    list->size++;
}

void popBack(struct List* list)
{
    if (list == NULL)
    {
        return;
    }

    ListElement* removable = list->back;
    if (removable == NULL)
    {
        return;
    }

    ListElement* newBack = list->front;
    for (int i = 0; i < list->size - 2; i++)
    {
        newBack = newBack->next;
    }

    list->back = newBack;

    if (getSize(list) == 1)
    {
        list->front = NULL;
    }

    list->size--;
    free(removable);
}

void popFront(struct List* list)
{
    if (list == NULL)
    {
        return;
    }

    ListElement* removable = list->front;
    if (removable == NULL)
    {
        return;
    }

    list->front = removable->next;
    if (getSize(list) == 1)
    {
        list->back = NULL;
    }

    list->size--;
    free(removable);
}

int getBack(List* list)
{
    if (list == NULL || list->back == NULL)
    {
        return -1;
    }
    return list->back->value;
}

int getFront(List* list)
{
    if (list == NULL || list->front == NULL)
    {
        return -1;
    }
    return list->front->value;
}

void deleteList(List* list)
{
    if (list == NULL)
    {
        return;
    }

    while (!isEmpty(list))
    {
        popBack(list);
    }

    free(list);
}

int getValue(int index, List* list)
{
    if (list == NULL)
    {
        return -1;
    }

    if (index < 0 || index >= getSize(list))
    {
        return -1;
    }

    ListElement* current = list->front;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->value;
}

ListElement* getElement(int index, List* list)
{
    if (list == NULL)
    {
        return NULL;
    }

    if (index < 0 || index >= getSize(list))
    {
        return NULL;
    }

    ListElement* current = list->front;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current;
}

void pop(int index, List* list)
{
    if (list == NULL)
    {
        return;
    }

    if (index < 0 || index >= getSize(list) || getSize(list) == 0)
    {
        return;
    }

    ListElement* prevCurrent = NULL;
    ListElement* current = list->front;
    for (int i = 0; i < index; i++)
    {
        prevCurrent = current;
        current = current->next;
    }

    if (prevCurrent != NULL)
    {
        prevCurrent->next = current->next;
    }
    else
    {
        list->front = current->next;
    }

    if (getSize(list) == 1)
    {
        list->front = NULL;
        list->back = NULL;
    }

    list->size--;
    free(current);
}

void push(int value, int index, List* list)
{
    if (list == NULL)
    {
        return;
    }

    if (index < 0 || index > getSize(list))
    {
        return;
    }

    ListElement* new = createListElement(value);

    ListElement* prevCurrent = NULL;
    ListElement* current = list->front;
    for (int i = 0; i < index; i++)
    {
        prevCurrent = current;
        current = current->next;
    }

    new->next = current;
    if (prevCurrent != NULL)
    {
        prevCurrent->next = new;
    }
    else
    {
        list->front = new;
    }
    list->size++;
}

void printList(List* list)
{
    ListElement* current = list->front;
    for (int i = 0; i < getSize(list); i++)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void sortList(List* list)
{
    for (int i = 1; i < list->size; i++)
    {
        int key = getValue(i, list);
        int j = i;
        ListElement* temp = NULL;
        while (j > 0 && getValue(j - 1, list) > key)
        {
            temp = getElement(j, list);
            temp->value = getValue(j - 1, list);
            j -= 1;
        }
        temp = getElement(j, list);
        temp->value = key;
    }
}