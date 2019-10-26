#include <stdlib.h>
#include "charStack.h"

typedef struct CharStack CharStack;
typedef struct CharStackElement CharStackElement;

struct CharStackElement
{
    char value;
    CharStackElement* next;
};

struct CharStack
{
    CharStackElement* first;
};

CharStack* charStackCreate()
{
    CharStack* stack = malloc(sizeof(struct CharStack));
    stack->first = NULL;
    return stack;
}

bool charStackIsEmpty(CharStack* stack)
{
    return stack->first == NULL;
}

bool charStackPush(char value, CharStack* stack)
{
    CharStackElement* stackElement = malloc(sizeof(struct CharStackElement));
    stackElement->value = value;
    stackElement->next = stack->first;

    stack->first = stackElement;
    return true;
}

char charStackPop(CharStack* stack)
{
    if (charStackIsEmpty(stack))
    {
        return 0;
    }

    CharStackElement* poppedElement = stack->first;
    stack->first = poppedElement->next;
    char value = poppedElement->value;
    free(poppedElement);
    return value;
}

char charStackTop(CharStack* stack)
{
    return stack->first->value;
}