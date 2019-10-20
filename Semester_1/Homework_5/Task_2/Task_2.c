#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

#define maxSize 256

double getResultOfOperation(double valueA, double valueB, char operation)
{
    switch (operation)
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

bool isOperation(char* input)
{
    if (strlen(input) > 1)
    {
        return false;
    }

    return input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/';
}

bool isDigit(char input)
{
    return input - '0' >= 0 && input - '0' <= 9;
}

bool isNumber(char* input)
{
    if (input[0] == '-' && strlen(input) == 1)
    {
        return false;
    }

    int startIndex = (input[0] == '-' ? 1 : 0);
    int inputLength = strlen(input);
    for (int i = startIndex; i < inputLength; i++)
    {
        if (!isDigit(input[i]))
        {
            return false;
        }
    }

    return true;
}

int main() {
    Stack* stack = createStack();

    printf("Enter an expression in the postfix notation (with spaces):\n");
    char inputString[maxSize] = "\0";
    scanf("%[^\n]", inputString);

    char input[maxSize] = "\0";
    char other[maxSize] = "\0";
    while (true)
    {
        sscanf(inputString, "%s %[^\n]", input, other);

        if(inputString[0] == '\0')
        {
            break;
        }

        if (isOperation(input) && stackSize(stack) >= 2)
        {
            double operandB = pop(stack);
            double operandA = pop(stack);
            double result = getResultOfOperation(operandA, operandB, input[0]);
            push(result, stack);
        }
        else if (isNumber(input))
        {
            double inputValue = 0;
            sscanf(input, "%lf", &inputValue);
            push(inputValue, stack);
        }
        else
        {
            printf("Incorrect input.");
            return 0;
        }

        strcpy(inputString, other);
        other[0] = '\0';
    }

    double answer = pop(stack);
    if (isEmpty(stack))
    {
        printf("Result: %lf", answer);
    }
    else
    {
        printf("Something went wrong. The stack is not empty. Maybe you missed the operation.");
    }

    return 0;
}