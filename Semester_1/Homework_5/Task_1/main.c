#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

#define maxSize 256

bool isOperation(char input)
{
    return input == '+' || input == '-' || input == '*' || input == '/';
}

bool isOpenBracket(char input)
{
    return input == '(';
}

bool isCloseBracket(char input)
{
    return input == ')';
}

bool isLessPriority(char operationA, char operationB)
{
    int priorityA = 0;
    if (operationA == '/' || operationA == '*')
    {
        priorityA = 1;
    }

    int priorityB = 0;
    if (operationB == '/' || operationB == '*')
    {
        priorityB = 1;
    }

    return priorityA <= priorityB;
}

bool isNumber(char input)
{
    return input - '0' >= 0 && input - '0' <= 9;
}

int main()
{
    Stack* stack = createStack();

    printf("Enter an expression in the infix notation:\n");
    char infixNotation[maxSize] = "\0";
    scanf("%[^\n]", infixNotation);

    char postfixNotation[maxSize] = "\0";
    int postfixNotationSize = 0;

    int infixNotationLength = strlen(infixNotation);
    char token = ' ';
    for (int i = 0; i < infixNotationLength; i++)
    {
        token = infixNotation[i];
        if (isOperation(token))
        {
            while (!isEmpty(stack) && isLessPriority(token, top(stack)) && !isOpenBracket(top(stack)))
            {
                 postfixNotation[postfixNotationSize] = pop(stack);
                 postfixNotationSize++;
            }

            push(token, stack);
        }
        else if (isCloseBracket(token))
        {
            while (!isEmpty(stack) && !isOpenBracket(top(stack)))
            {
                postfixNotation[postfixNotationSize] = pop(stack);
                postfixNotationSize++;
            }

            if (!isEmpty(stack))
            {
                pop(stack);
            }
            else
            {
                printf("Missing bracket");
                return 0;
            }
        }
        else if (isOpenBracket(token))
        {
            push(token, stack);
        }
        else if (isNumber(token))
        {
            postfixNotation[postfixNotationSize] = token;
            postfixNotationSize++;
        }
        else if (token == ' ')
        {
            continue;
        }
        else
        {
            printf("Invalid character");
            return 0;
        }
    }

    while (!isEmpty(stack))
    {
        if (isOpenBracket(top(stack)))
        {
            printf("Missing bracket");
            return 0;
        }

        postfixNotation[postfixNotationSize] = pop(stack);
        postfixNotationSize++;
    }

    for (int i = 0; i < postfixNotationSize; i++)
    {
        printf("%c ", postfixNotation[i]);
    }

    return 0;
}