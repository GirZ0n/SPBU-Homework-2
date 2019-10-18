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

bool isOperation(char input)
{
    return input == '+' || input == '-' || input == '*' || input == '/';
}

int charToInt (char digit)
{
    return digit - '0';
}

int main() {
    Stack* stack = createStack();

    printf("Enter an expression in the reverse Polish notation:\n");
    char inputString[maxSize] = "\0";
    scanf("%[^\n]", inputString);

    int inputStringLength = strlen(inputString);
    for (int i = 0; i < inputStringLength; i++)
    {
        if(inputString[i] == ' ')
        {
            continue;
        }

        if (isOperation(inputString[i]))
        {
            double operandB = pop(stack);
            double operandA = pop(stack);
            double result = getResultOfOperation(operandA, operandB, inputString[i]);
            push(result, stack);
        }
        else
        {
            push((double)charToInt(inputString[i]), stack);
        }
    }

    double answer = pop(stack);
    if (isEmpty(stack))
    {
        printf("Result: %lf", answer);
    }
    else
    {
        printf("The stack is not empty. Enter the correct expression.");
    }

    return 0;
}