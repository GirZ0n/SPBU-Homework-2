#ifndef SET_H
#define SET_H

#include <stdbool.h>

struct Set;

struct Set* createSet();
bool isContained(int value, struct Set* set);
void addElement(int value, struct Set* set);
bool removeElement(int value, struct Set* set);
void printInAscendingOrder(struct Set* set);
void printInDescendingOrder(struct Set* set);
void printSet(struct Set* set);

#endif
