#include <stdlib.h>
#include "stack.h"

typedef struct Stack Stack;
typedef struct StackElement StackElement;

struct StackElement
{
    double value;
    StackElement* next;
};

struct Stack
{
    int size;
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

bool push(double value, Stack* stack)
{
    stack->size++;
    StackElement* stackElement = malloc(sizeof(struct StackElement));
    stackElement->value = value;
    stackElement->next = stack->first;

    stack->first = stackElement;
    return true;
}

double pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }

    stack->size--;
    StackElement* poppedElement = stack->first;
    stack->first = poppedElement->next;
    double value = poppedElement->value;
    free(poppedElement);
    return value;
}

int stackSize(Stack* stack)
{
    return stack->size;
}