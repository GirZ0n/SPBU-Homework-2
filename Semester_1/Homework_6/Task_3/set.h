#ifndef SET_H
#define SET_H

#include <stdbool.h>

struct Set;
struct SetElement;

struct Set* createSet();
struct SetElement* createSetElement();
bool isContained(int value, struct Set* set);
void add(int value, struct Set* set);
bool remove(int value, struct Set* set);
void printInAscendingOrder(struct Set* set);
void printInDescendingOrder(struct Set* set);

#endif
