#pragma once

#include <stdbool.h>

typedef struct List List;
struct List;

List* createList();
bool isListEmpty(List* list);
bool insertToList(List *list, int value, int index);
bool deleteFromList(List* list, int index);
int locateOfListElement(List *list, int value);
int retrieveValueFromList(List* list, int index);
int getListSize(List* list);
void deleteList(List* list);
void insertionSort(List* list);
void printList(List* list);