#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

#define maxSize 256

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

int getNumber(char* input, int* index)
{
    char number[maxSize] = "\0";
    number[0] = input[*index];
    int numberLength = 1;

    int inputLength = strlen(input);
    while (*index + 1 < inputLength && isDigit(input[*index + 1]))
    {
        number[numberLength] = input[*index + 1];
        numberLength++;
        (*index)++;
    }

    int numberValue = 0;
    sscanf(number, "%d", &numberValue);
    return numberValue;
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


int main()
{
    Stack* stack = createStack();

    printf("Enter an expression in the infix notation:\n");
    char inputString[maxSize] = "\0";
    scanf("%[^\n]", inputString);

    int sizeOfOutput = 0;
    int outputNumbers[maxSize] = {0};
    char outputOperators[maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        outputOperators[i] = ' ';
    }

    int inputStringLength = strlen(inputString);
    for (int i = 0; i < inputStringLength; i++)
    {
        if (isOperator(inputString, i))
        {
            while (!isEmpty(stack) && isLessPriority(inputString[i], top(stack))
                && !isOpenBracket(top(stack)))
            {
                outputOperators[sizeOfOutput] = pop(stack);
                sizeOfOutput++;
            }

            push(inputString[i], stack);
        }
        else if (isCloseBracket(inputString[i]))
        {
            while (!isEmpty(stack) && !isOpenBracket(top(stack)))
            {
                outputOperators[sizeOfOutput] = pop(stack);
                sizeOfOutput++;
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
        else if (isOpenBracket(inputString[i]))
        {
            push(inputString[i], stack);
        }
        else if (isUnaryNegative(inputString, i) || isDigit(inputString[i]))
        {
            outputNumbers[sizeOfOutput] = getNumber(inputString, &i);
            sizeOfOutput++;
        }
        else if (inputString[i] == ' ')
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

        outputOperators[sizeOfOutput] = pop(stack);
        sizeOfOutput++;
    }



    for (int i = 0; i < sizeOfOutput; i++)
    {
        if (outputOperators[i] == ' ')
        {
            printf("%d ", outputNumbers[i]);
        }
        else
        {
            printf("%c ", outputOperators[i]);
        }
    }

    return 0;
}