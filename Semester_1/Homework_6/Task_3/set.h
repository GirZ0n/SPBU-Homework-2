#ifndef SET_H
#define SET_H

#include <stdbool.h>

struct Set;
struct SetElement;

struct Set* createSet();
struct SetElement* createSetElement();
bool isContained(int number);
void add(int number, struct Set*);
bool remove(int number, struct Set*);
void printInAscendingOrder(struct Set*);
void printInDescendingOrder(struct Set*);

#endif
