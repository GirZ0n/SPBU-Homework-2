#include <stdlib.h>
#include "stack.h"

// Stack of char
struct StackOfChar
{
    int size;
    struct StackOfCharElement* first;
};

struct StackOfCharElement
{
    char value;
    struct StackOfCharElement* next;
};

typedef struct StackOfChar StackOfChar;
typedef struct StackOfCharElement StackOfCharElement;

StackOfChar* createStackOfChar()
{
    StackOfChar* stack = malloc(sizeof(struct StackOfChar));
    stack->size = 0;
    stack->first = NULL;
    return stack;
}

int stackOfCharSize(StackOfChar* stack)
{
    return stack->size;
}

bool stackOfCharIsEmpty(StackOfChar* stack)
{
    return stackOfCharSize(stack) == 0;
}

bool pushChar(char value, StackOfChar* stack)
{
    StackOfCharElement* pushed = malloc(sizeof(struct StackOfCharElement));
    pushed->value = value;
    pushed->next = stack->first;
    stack->first = pushed;
    stack->size++;

    return true;
}

char popChar(StackOfChar* stack)
{
    if (stackOfCharIsEmpty(stack))
    {
        return 0;
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
    return stack->first->value;
}



// Stack of double
struct StackOfDouble
{
    int size;
    struct StackOfDoubleElement* first;
};

struct StackOfDoubleElement
{
    double value;
    struct StackOfDoubleElement* next;
};

typedef struct StackOfDouble StackOfDouble;
typedef struct StackOfDoubleElement StackOfDoubleElement;

StackOfDouble* createStackOfDouble()
{
    StackOfDouble* stack = malloc(sizeof(struct StackOfDouble));
    stack->size = 0;
    stack->first = NULL;
    return stack;
}

int stackOfDoubleSize(StackOfDouble* stack)
{
    return stack->size;
}

bool stackOfDoubleIsEmpty(StackOfDouble* stack)
{
    return stackOfDoubleSize(stack) == 0;
}

bool pushDouble(double value, StackOfDouble* stack)
{
    StackOfDoubleElement* pushed = malloc(sizeof(struct StackOfDoubleElement));
    pushed->value = value;
    pushed->next = stack->first;
    stack->size++;
    stack->first = pushed;

    return true;
}

double popDouble(StackOfDouble* stack)
{
    if (stackOfDoubleIsEmpty(stack))
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
