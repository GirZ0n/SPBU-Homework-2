#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

const int maxSize = 256;

bool isOpenBracket(char input)
{
    return input == '(';
}

bool isCloseBracket(char input)
{
    return input == ')';
}

bool isLessPriority(char operatorA, char operatorB)
{
    int priorityA = 0;
    if (operatorA == '/' || operatorA == '*')
    {
        priorityA = 1;
    }

    int priorityB = 0;
    if (operatorB == '/' || operatorB == '*')
    {
        priorityB = 1;
    }

    return priorityA <= priorityB;
}

bool isDigit(char input)
{
    return input - '0' >= 0 && input - '0' <= 9;
}

char* getNumber(char* input, int* indexOfStart)
{
    char* number = calloc(maxSize, sizeof(char));
    number[0] = input[*indexOfStart];
    int numberLength = 1;

    int inputLength = strlen(input);
    while (*indexOfStart + 1 < inputLength && isDigit(input[*indexOfStart + 1]))
    {
        number[numberLength] = input[*indexOfStart + 1];
        numberLength++;
        (*indexOfStart)++;
    }

    return number;
}

bool isUnaryNegative(char* input, int index)
{
    if (input[index] == '-' && index + 1 < strlen(input))
    {
        return isDigit(input[index + 1]);
    }

    return false;
}

bool isOperator(char* input, int index)
{
    if (isUnaryNegative(input, index))
    {
        return false;
    }

    return input[index] == '+' || input[index] == '-' || input[index] == '*' || input[index] == '/';
}

char* charToString(char input)
{
    char* string = calloc(1, sizeof(char));
    sprintf(string, "%c", input);
    return string;
}

int main()
{
    struct Stack* stack = createStack();

    printf("Enter an expression in the infix notation:\n");
    char* inputString = calloc(maxSize, sizeof(char));
    scanf("%[^\n]", inputString);
    char* outputString = calloc(maxSize, sizeof(char));

    int inputStringLength = strlen(inputString);
    for (int i = 0; i < inputStringLength; i++)
    {
        if (isOperator(inputString, i))
        {
            while (!isEmpty(stack) && isLessPriority(inputString[i], top(stack))
                && !isOpenBracket(top(stack)))
            {
                strcat(outputString, charToString(pop(stack)));
                strcat(outputString, " ");
            }

            push(inputString[i], stack);
        }
        else if (isCloseBracket(inputString[i]))
        {
            while (!isEmpty(stack) && !isOpenBracket(top(stack)))
            {
                strcat(outputString, charToString(pop(stack)));
                strcat(outputString, " ");
            }

            if (!isEmpty(stack))
            {
                pop(stack);
            }
            else
            {
                printf("Missing bracket.");
                return 0;
            }
        }
        else if (isOpenBracket(inputString[i]))
        {
            push(inputString[i], stack);
        }
        else if (isUnaryNegative(inputString, i) || isDigit(inputString[i]))
        {
            strcat(outputString, getNumber(inputString, &i));
            strcat(outputString, " ");
        }
        else if (inputString[i] == ' ')
        {
            continue;
        }
        else
        {
            printf("Invalid character.");
            return 0;
        }
    }

    while (!isEmpty(stack))
    {
        if (isOpenBracket(top(stack)))
        {
            printf("Missing bracket.");
            return 0;
        }

        strcat(outputString, charToString(pop(stack)));
        strcat(outputString, " ");
    }

    printf("Expression in postfix notation:\n%s", outputString);
    return 0;
}