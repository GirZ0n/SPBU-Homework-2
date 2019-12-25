#include <stdlib.h>
#include "stackOfChar.h"

typedef struct StackOfCharElement StackOfCharElement;

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
    StackOfChar* stack = malloc(sizeof(StackOfChar));
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

    StackOfCharElement* pushed = malloc(sizeof(StackOfCharElement));
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