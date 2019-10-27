#include <stdlib.h>
#include "stack.h"

// Stack of char
typedef struct StackOfChar StackOfChar;
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
    StackOfCharElement* stackElement = malloc(sizeof(struct StackOfCharElement));
    stackElement->value = value;
    stackElement->next = stack->first;

    stack->first = stackElement;
    stack->size++;
    return true;
}

char popChar(StackOfChar* stack)
{
    if (stackOfCharIsEmpty(stack))
    {
        return 0;
    }

    StackOfCharElement* poppedElement = stack->first;
    stack->first = poppedElement->next;
    stack->size--;
    char value = poppedElement->value;
    free(poppedElement);
    return value;
}

char stackOfCharTop(StackOfChar* stack)
{
    return stack->first->value;
}



// Stack of double
typedef struct StackOfDouble StackOfDouble;
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
    StackOfDoubleElement* stackElement = malloc(sizeof(struct StackOfDoubleElement));
    stackElement->value = value;
    stackElement->next = stack->first;

    stack->size++;
    stack->first = stackElement;
    return true;
}

double popDouble(StackOfDouble* stack)
{
    if (stackOfDoubleIsEmpty(stack))
    {
        return 0;
    }

    StackOfDoubleElement* poppedElement = stack->first;
    stack->size--;
    stack->first = poppedElement->next;
    double value = poppedElement->value;
    free(poppedElement);
    return value;
}
