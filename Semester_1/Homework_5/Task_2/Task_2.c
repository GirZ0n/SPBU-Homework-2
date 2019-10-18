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
    return input[0] == '+' || input[0] == '*' || input[0] == '/' ||
          (input[0] == '-' && (input[1] == ' ' || input[1] == '\0'));
}

int main() {
    Stack* stack = createStack();

    printf("Enter an expression in the reverse Polish notation:\n");
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

        if (isOperation(input))
        {
            double operandB = pop(stack);
            double operandA = pop(stack);
            double result = getResultOfOperation(operandA, operandB, input[0]);
            push(result, stack);
        }
        else
        {
            double inputValue = 0;
            sscanf(input, "%lf", &inputValue);
            push(inputValue, stack);
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
        printf("Something went wrong. The stack is not empty.");
    }

    return 0;
}