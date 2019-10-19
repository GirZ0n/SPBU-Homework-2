#include <stdlib.h>
#include "stack.h"

struct StackElement
{
    char value;
    StackElement* next;
};

struct Stack
{
    StackElement* first;
};

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
    StackElement* stackElement = malloc(sizeof(struct StackElement));
    stackElement->value = value;
    stackElement->next = stack->first;

    stack->first = stackElement;
    return true;
}

char pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }

    StackElement* poppedElement = stack->first;
    stack->first = poppedElement->next;
    char value = poppedElement->value;
    free(poppedElement);
    return value;
} 