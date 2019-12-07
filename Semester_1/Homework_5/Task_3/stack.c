#include <stdlib.h>
#include "stack.h"

typedef struct StackOfCharElement StackOfCharElement;

// Stack of char
struct StackOfChar
{
    int size;
    StackOfCharElement* first;
};

struct StackOfCharElement
{
    char value;
    StackOfCharElement* next;
};

StackOfChar* createStackOfChar()
{
    StackOfChar* stack = malloc(sizeof(struct StackOfChar));
    stack->size = 0;
    stack->first = NULL;
    return stack;
}

int stackOfCharSize(StackOfChar* stack)
{
    if (stack == NULL)
    {
        return 0;
    }

    return stack->size;
}

bool stackOfCharIsEmpty(StackOfChar* stack)
{
    if (stack == NULL)
    {
        return true;
    }

    return stackOfCharSize(stack) == 0;
}

bool pushChar(char value, StackOfChar* stack)
{
    if (stack == NULL)
    {
        return false;
    }

    StackOfCharElement* pushed = malloc(sizeof(struct StackOfCharElement));
    pushed->value = value;
    pushed->next = stack->first;
    stack->first = pushed;
    stack->size++;

    return true;
}

char popChar(StackOfChar* stack)
{
    if (stack == NULL || stackOfCharIsEmpty(stack))
    {
        return -1;
    }

    StackOfCharElement* popped = stack->first;
    stack->first = popped->next;
    stack->size--;
    char value = popped->value;

    free(popped);
    return value;
}

char stackOfCharTop(StackOfChar* stack)
{
    if (stack == NULL || stack->first == NULL)
    {
        return -1;
    }

    return stack->first->value;
}

void deleteStackOfChar(StackOfChar* stack)
{
    if (stack == NULL)
    {
        return;
    }

    while (!stackOfCharIsEmpty(stack))
    {
        popChar(stack);
    }

    free(stack);
}



typedef struct StackOfDoubleElement StackOfDoubleElement;

// Stack of double
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
    StackOfDouble* stack = malloc(sizeof(struct StackOfDouble));
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

    StackOfDoubleElement* pushed = malloc(sizeof(struct StackOfDoubleElement));
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