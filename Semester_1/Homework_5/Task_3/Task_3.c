#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "stringAndCharOparations.h"

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

bool fillingPostfixNotation(char* postfixNotation, int* sizeOfPostfix, StackOfChar* stack)
{
    while (!stackOfCharIsEmpty(stack))
    {
        if (isOpenBracket(stackOfCharTop(stack)))
        {
            return false;
        }

        postfixNotation[*sizeOfPostfix] = popChar(stack);
        (*sizeOfPostfix)++;
        postfixNotation[*sizeOfPostfix] = ' ';
        (*sizeOfPostfix)++;
    }

    return true;
}

char* convertInfixToPostfix(char* infixNotation, bool* isError)
{
    StackOfChar* stack = createStackOfChar();
    int sizeOfPostfix = 0;
    char* postfixNotation = calloc(strlen(infixNotation) * 2, sizeof(char));

    int inputStringLength = (int) strlen(infixNotation);
    for (int i = 0; i < inputStringLength; i++)
    {
        if (isOperator(infixNotation, i))
        {
            while (!stackOfCharIsEmpty(stack) && isLessPriority(infixNotation[i], stackOfCharTop(stack))
                   && !isOpenBracket(stackOfCharTop(stack)))
            {
                postfixNotation[sizeOfPostfix++] = popChar(stack);
                postfixNotation[sizeOfPostfix++] = ' ';
            }

            pushChar(infixNotation[i], stack);
        }
        else if (isCloseBracket(infixNotation[i]))
        {
            while (!stackOfCharIsEmpty(stack) && !isOpenBracket(stackOfCharTop(stack)))
            {
                postfixNotation[sizeOfPostfix++] = popChar(stack);
                postfixNotation[sizeOfPostfix++] = ' ';
            }

            if (!stackOfCharIsEmpty(stack))
            {
                popChar(stack);
            }
            else
            {
                printf("Missing bracket.");
                *isError = true;
                return " ";
            }
        }
        else if (isOpenBracket(infixNotation[i]))
        {
            pushChar(infixNotation[i], stack);
        }
        else if (isUnaryNegative(infixNotation, i) || isDigit(infixNotation[i]))
        {
            writeNumberToString(infixNotation, &i, postfixNotation, &sizeOfPostfix);
        }
        else if (infixNotation[i] == ' ')
        {
            continue;
        }
        else
        {
            printf("Invalid character.");
            *isError = true;
            return " ";
        }
    }

    if (fillingPostfixNotation(postfixNotation, &sizeOfPostfix, stack) == false)
    {
        printf("Missing bracket.");
        *isError = true;
        return " ";
    }

    deleteStackOfChar(stack);
    return postfixNotation;
}

double calculatePostfixNotation(char* postfixNotation)
{
    struct StackOfDouble* stack = createStackOfDouble();
    int inputStringLength = (int) strlen(postfixNotation);
    for (int i = 0; i < inputStringLength; i++)
    {
        if (isOperator(postfixNotation, i))
        {
            double operandB = popDouble(stack);
            double operandA = popDouble(stack);
            double result = getResultOfOperation(operandA, operandB, postfixNotation[i]);
            pushDouble(result, stack);
        }
        else if (isUnaryNegative(postfixNotation, i) || isDigit(postfixNotation[i]))
        {
            pushDouble(getNumberAsDouble(postfixNotation, &i), stack);
        }
        else
        {
            continue;
        }
    }

    double result = popDouble(stack);
    deleteStackOfDouble(stack);
    return result;
}

char* getStringFromConsole()
{
    int length = 0;
    int capacity = 2;
    char* string = calloc(capacity, sizeof(char));
    char input = ' ';
    scanf("%c", &input);
    while (input != '\n')
    {
        if (length == capacity)
        {
            capacity *= 2;
            string = realloc(string, capacity);
        }

        string[length] = input;
        length++;
        scanf("%c", &input);
    }
    return string;
}

int main()
{

    printf("Enter an expression in the infix notation:\n");
    char* infixNotation = getStringFromConsole();
    bool isError = false;
    char* postfixNotation = convertInfixToPostfix(infixNotation, &isError);

    if (isError == true)
    {
        printf("Try again.");
        return 0;
    }

    double result = calculatePostfixNotation(postfixNotation);
    printf("Result:\n%lf", result);

    free(infixNotation);
    free(postfixNotation);
    return 0;
}