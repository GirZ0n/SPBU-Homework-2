#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct Stack;
struct StackElement;

bool isEmpty(struct Stack* stack);
bool push(double value, struct Stack* stack);
double pop(struct Stack* stack);
int stackSize(struct Stack* stack);
struct Stack* createStack();

#endif