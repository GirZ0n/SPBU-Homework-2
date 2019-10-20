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

bool isOperator(char* input, int index)
{
    if (input[index] == '-')
    {
        if (index + 1 < strlen(input))
        {
            return input[index + 1] == ' ';
        }

        return true;
    }

    return input[index] == '+' || input[index] == '*' || input[index] == '/';
}

bool isDigit(char input)
{
    return input - '0' >= 0 && input - '0' <= 9;
}

double getNumber(char* input, int* index)
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

    double numberValue = 0;
    sscanf(number, "%lf", &numberValue);
    return numberValue;
}

int main() {
    Stack* stack = createStack();

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
        else if (isDigit(inputString[i]))
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