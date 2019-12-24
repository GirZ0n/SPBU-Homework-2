#include <stdlib.h>
#include "stackOfDouble.h"

typedef struct StackOfDoubleElement StackOfDoubleElement;

struct StackOfDouble
{
    int size;
    StackOfDoubleElement* first;
};
struct StackOfDoubleElement
{
    double value;
    StackOfDoubleElement* next;
};

StackOfDouble* createStackOfDouble()
{
    StackOfDouble* stack = malloc(sizeof(StackOfDouble));
    stack->size = 0;
    stack->first = NULL;
    return stack;
}

int stackOfDoubleSize(StackOfDouble* stack)
{
    if (stack == NULL)
    {
        return 0;
    }

    return stack->size;
}

bool stackOfDoubleIsEmpty(StackOfDouble* stack)
{
    if (stack == NULL)
    {
        return true;
    }

    return stackOfDoubleSize(stack) == 0;
}

bool pushDouble(double value, StackOfDouble* stack)
{
    if (stack == NULL)
    {
        return false;
    }

    StackOfDoubleElement* pushed = malloc(sizeof(StackOfDoubleElement));
    pushed->value = value;
    pushed->next = stack->first;
    stack->size++;
    stack->first = pushed;

    return true;
}

double popDouble(StackOfDouble* stack)
{
    if (stack == NULL || stackOfDoubleIsEmpty(stack))
    {
        return 0;
    }

    StackOfDoubleElement* popped = stack->first;
    stack->size--;
    stack->first = popped->next;
    double value = popped->value;

    free(popped);
    return value;
}

void deleteStackOfDouble(StackOfDouble* stack)
{
    if (stack == NULL)
    {
        return;
    }

    while (!stackOfDoubleIsEmpty(stack))
    {
        popDouble(stack);
    }

    free(stack);
}