#pragma once

#include "stdbool.h"

struct List;
typedef struct List List;

List* createList();
void deleteList(List* list);
bool isEmpty(List* list);
void pushBack(int value, List* list);
void pushFront(int value, List* list);
void popBack(List* list);
void popFront(List* list);
int getBack(List* list);
int getFront(List* list);
int getSize(List* list);
int getValue(int index, List* list);
void pop(int index, List* list);
void push(int value, int index, List* list);
void printList(List* list);
void sortList(List* list);