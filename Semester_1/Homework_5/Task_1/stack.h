#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct Stack;
struct StackElement;

struct Stack* createStack();
bool isEmpty(struct Stack* stack);
bool push(char value, struct Stack* stack);
char pop(struct Stack* stack);
char top(struct Stack* stack);

#endif 