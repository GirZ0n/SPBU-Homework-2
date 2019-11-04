#include <stdlib.h>
#include "stack.h"

struct Stack
{
    struct StackElement* first;
};

struct StackElement
{
    char value;
    struct StackElement* next;
};

typedef struct Stack Stack;
typedef struct StackElement StackElement;

Stack* createStack()
{
    Stack* stack = malloc(sizeof(struct Stack));
    stack->first = NULL;
    return stack;
}

bool isEmpty(Stack* stack)
{
    return stack->first == NULL;
}

bool push(char value, Stack* stack)
{
    StackElement* current = malloc(sizeof(struct StackElement));
    current->value = value;
    current->next = stack->first;
    stack->first = current;

    return true;
}

char pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }

    StackElement* popped = stack->first;
    stack->first = popped->next;
    char value = popped->value;
    free(popped);
    return value;
}

char top(Stack* stack)
{
    return stack->first->value;
}