#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

char* getNumberAsString(char* input, int* indexOfStart)
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

double getNumberAsDouble(char* input, int* indexOfStart)
{
    int number = 0;
    if (isDigit(input[*indexOfStart]))
    {
        number = input[*indexOfStart] - '0';
    }

    int inputLength = strlen(input);
    while (*indexOfStart + 1 < inputLength && isDigit(input[*indexOfStart + 1]))
    {
        number = number * 10 + (input[*indexOfStart + 1] - '0');
        (*indexOfStart)++;
    }
    return (double) number;
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

char* charToString(char input)
{
    char* string = calloc(1, sizeof(char));
    sprintf(string, "%c", input);
    return string;
}

/*
 * infixToPostfix - convert an expression in infix notation to postfix;
 *                - return true if the conversion succeeds, otherwise return false
 */
bool infixToPostfix (char* infixNotation, char* postfixNotation)
{
    struct StackOfChar* stackOfChar = createStackOfChar();

    int inputStringLength = strlen(infixNotation);
    for (int i = 0; i < inputStringLength; i++)
    {
        if (isOperator(infixNotation, i))
        {
            while (!stackOfCharIsEmpty(stackOfChar) && isLessPriority(infixNotation[i], stackOfCharTop(stackOfChar))
                   && !isOpenBracket(stackOfCharTop(stackOfChar)))
            {
                strcat(postfixNotation, charToString(popChar(stackOfChar)));
                strcat(postfixNotation, " ");
            }

            pushChar(infixNotation[i], stackOfChar);
        }
        else if (isCloseBracket(infixNotation[i]))
        {
            while (!stackOfCharIsEmpty(stackOfChar) && !isOpenBracket(stackOfCharTop(stackOfChar)))
            {
                strcat(postfixNotation, charToString(popChar(stackOfChar)));
                strcat(postfixNotation, " ");
            }

            if (!stackOfCharIsEmpty(stackOfChar))
            {
                popChar(stackOfChar);
            }
            else
            {
                printf("Missing bracket.");
                return false;
            }
        }
        else if (isOpenBracket(infixNotation[i]))
        {
            pushChar(infixNotation[i], stackOfChar);
        }
        else if (isUnaryNegative(infixNotation, i) || isDigit(infixNotation[i]))
        {
            strcat(postfixNotation, getNumberAsString(infixNotation, &i));
            strcat(postfixNotation, " ");
        }
        else if (infixNotation[i] == ' ')
        {
            continue;
        }
        else
        {
            printf("Invalid character.");
            return false;
        }
    }

    while (!stackOfCharIsEmpty(stackOfChar))
    {
        if (isOpenBracket(stackOfCharTop(stackOfChar)))
        {
            printf("Missing bracket.");
            return false;
        }

        strcat(postfixNotation, charToString(popChar(stackOfChar)));
        strcat(postfixNotation, " ");
    }

    return true;
}

double calculatePostfixNotation(char* postfixNotation)
{
    struct StackOfDouble* stackOfDouble = createStackOfDouble();
    int inputStringLength = strlen(postfixNotation);
    for (int i = 0; i < inputStringLength; i++)
    {
        if (isOperator(postfixNotation, i))
        {
            double operandB = popDouble(stackOfDouble);
            double operandA = popDouble(stackOfDouble);
            double result = getResultOfOperation(operandA, operandB, postfixNotation[i]);
            pushDouble(result, stackOfDouble);
        }
        else if (isUnaryNegative(postfixNotation, i) || isDigit(postfixNotation[i]))
        {
            pushDouble(getNumberAsDouble(postfixNotation, &i), stackOfDouble);
        }
        else
        {
            continue;
        }
    }

    return popDouble(stackOfDouble);
}

int main()
{
    printf("Enter an expression in the infix notation:\n");
    char* infixNotation = calloc(maxSize, sizeof(char));
    scanf("%[^\n]", infixNotation);

    char* postfixNotation = calloc(maxSize, sizeof(char));
    if (infixToPostfix(infixNotation, postfixNotation) == false)
    {
        return 0;
    }

    printf("Result: %lf", calculatePostfixNotation(postfixNotation));
    return 0;
}