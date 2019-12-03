#pragma once

#include <stdbool.h>

typedef struct Set Set;

struct Set;

Set* createSet();
void deleteSet(Set* set);
bool isContained(int value, Set* set);
bool addElement(int value, Set* set);
bool removeElement(int value, Set* set);
void printInAscendingOrder(Set* set);
void printInDescendingOrder(Set* set);
void printSet(Set* set);