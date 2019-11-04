#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

#define maxSize 256

double getResultOfOperation(double valueA, double valueB, char operator)
{
    switch (operator)
    {
        case '+':
        {
            return valueA + valueB;
        }
        case '-':
        {
            return valueA - valueB;
        }
        case '*':
        {
            return valueA * valueB;
        }
        case '/':
        {
            return valueA / valueB;
        }
    }
}

bool isDigit(char input)
{
    return input - '0' >= 0 && input - '0' <= 9;
}

bool isUnaryNegative(char* input, int indexOfCheck)
{
    if (input[indexOfCheck] == '-' && indexOfCheck + 1 < strlen(input))
    {
        return isDigit(input[indexOfCheck + 1]);
    }

    return false;
}

bool isOperator(char* input, int indexOfCheck)
{
    if (isUnaryNegative(input, indexOfCheck))
    {
        return false;
    }

    return input[indexOfCheck] == '+' || input[indexOfCheck] == '-' || input[indexOfCheck] == '*' || input[indexOfCheck] == '/';
}

double getNumber(char* input, int* indexOfStart)
{
    char number[maxSize] = "\0";
    number[0] = input[*indexOfStart];
    int numberLength = 1;

    int inputLength = strlen(input);
    while (*indexOfStart + 1 < inputLength && isDigit(input[*indexOfStart + 1]))
    {
        number[numberLength] = input[*indexOfStart + 1];
        numberLength++;
        (*indexOfStart)++;
    }

    double numberValue = 0;
    sscanf(number, "%lf", &numberValue);
    return numberValue;
}

int main()
{
    struct Stack* stack = createStack();

    printf("Enter an expression in the postfix notation (with spaces):\n");
    char inputString[maxSize] = "\0";
    scanf("%[^\n]", inputString);

    int inputStringLength = strlen(inputString);
    for (int i = 0; i < inputStringLength; i++)
    {
        if (isOperator(inputString, i) && stackSize(stack) >= 2)
        {
            double operandB = pop(stack);
            double operandA = pop(stack);
            double result = getResultOfOperation(operandA, operandB, inputString[i]);
            push(result, stack);
        }
        else if (isUnaryNegative(inputString, i) || isDigit(inputString[i]))
        {
            push(getNumber(inputString, &i), stack);
        }
        else if (inputString[i] == ' ')
        {
            continue;
        }
        else
        {
            printf("Incorrect input.");
            return 0;
        }
    }

    double answer = pop(stack);
    if (isEmpty(stack))
    {
        printf("Result: %lf", answer);
    }
    else
    {
        printf("Something went wrong. The stack is not empty. Maybe you missed the operator.");
    }

    return 0;
}