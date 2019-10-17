#include <stdlib.h>
#include "stack.h"

struct StackElement
{
    int value;
    StackElement *next;
};

struct Stack
{
    StackElement *first;
};

Stack *createStack()
{
    Stack *stack = malloc(sizeof(struct Stack));
    stack->first = NULL;
    return stack;
}

bool isEmpty(Stack *stack)
{
    return stack->first == NULL;
}

bool push(int value, Stack *stack)
{
    StackElement *stackElement = malloc(sizeof(struct StackElement));
    stackElement->value = value;
    stackElement->next = stack->first;

    stack->first = stackElement;
    return true;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }

    StackElement *poppedElement = stack->first;
    stack->first = poppedElement->next;
    int value = poppedElement->value;
    free(poppedElement);
    return value;
}