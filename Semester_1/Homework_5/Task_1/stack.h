#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct Stack;
struct StackElement;

typedef struct Stack Stack;
typedef struct StackElement StackElement;

bool isEmpty(Stack* stack);
bool push(char value, Stack* stack);
char pop(Stack* stack);
Stack* createStack();

#endif 