#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

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
    int numberCapacity = 2;
    char* number = calloc(numberCapacity, sizeof(char));
    number[0] = input[*indexOfStart];
    int numberLength = 1;

    int inputLength = (int) strlen(input);
    while (*indexOfStart + 1 < inputLength && isDigit(input[*indexOfStart + 1]))
    {
        if (numberLength == numberCapacity)
        {
            numberCapacity *= 2;
            number = realloc(number, numberCapacity);
        }

        number[numberLength] = input[*indexOfStart + 1];
        numberLength++;
        (*indexOfStart)++;
    }

    return number;
}

double getNumberAsDouble(char* input, int* indexOfCurrentPosition)
{
    int number = 0;
    if (isDigit(input[*indexOfCurrentPosition]))
    {
        number = input[*indexOfCurrentPosition] - '0';
    }

    int indexOfStart = *indexOfCurrentPosition;

    int inputLength = (int) strlen(input);
    while (*indexOfCurrentPosition + 1 < inputLength && isDigit(input[*indexOfCurrentPosition + 1]))
    {
        number = number * 10 + (input[*indexOfCurrentPosition + 1] - '0');
        (*indexOfCurrentPosition)++;
    }

    if (input[indexOfStart] == '-')
    {
        number *= -1;
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

    return input[indexOfCheck] == '+' || input[indexOfCheck] == '-' ||
           input[indexOfCheck] == '*' || input[indexOfCheck] == '/';
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

char* convertInfixToPostfix (char* infixNotation, bool* isError)
{
    struct StackOfChar* stackOfChar = createStackOfChar();
    int postfixLength = 0;
    int postfixCapacity = 2;
    char* postfixNotation = calloc(postfixCapacity, sizeof(char));

    int inputStringLength = (int) strlen(infixNotation);
    for (int i = 0; i < inputStringLength; i++)
    {
        if (isOperator(infixNotation, i))
        {
            while (!stackOfCharIsEmpty(stackOfChar) && isLessPriority(infixNotation[i], stackOfCharTop(stackOfChar))
                   && !isOpenBracket(stackOfCharTop(stackOfChar)))
            {
                if (postfixLength + 2 > postfixCapacity)
                {
                    postfixCapacity *= 2;
                    postfixNotation = realloc(postfixNotation, postfixCapacity);
                }

                strcat(postfixNotation, charToString(popChar(stackOfChar)));
                strcat(postfixNotation, " ");
                postfixLength += 2;
            }

            pushChar(infixNotation[i], stackOfChar);
        }
        else if (isCloseBracket(infixNotation[i]))
        {
            while (!stackOfCharIsEmpty(stackOfChar) && !isOpenBracket(stackOfCharTop(stackOfChar)))
            {
                if (postfixLength + 2 > postfixCapacity)
                {
                    postfixCapacity *= 2;
                    postfixNotation = realloc(postfixNotation, postfixCapacity);
                }

                strcat(postfixNotation, charToString(popChar(stackOfChar)));
                strcat(postfixNotation, " ");
                postfixLength += 2;
            }

            if (!stackOfCharIsEmpty(stackOfChar))
            {
                popChar(stackOfChar);
            }
            else
            {
                *isError = true;
                printf("Missing bracket.");
                return " ";
            }
        }
        else if (isOpenBracket(infixNotation[i]))
        {
            pushChar(infixNotation[i], stackOfChar);
        }
        else if (isUnaryNegative(infixNotation, i) || isDigit(infixNotation[i]))
        {
            char* number = getNumberAsString(infixNotation, &i);
            while (postfixLength + strlen(number) + 1 > postfixCapacity)
            {
                postfixCapacity *= 2;
                postfixNotation = realloc(postfixNotation, postfixCapacity);
            }

            strcat(postfixNotation, number);
            strcat(postfixNotation, " ");
            postfixLength += (int) strlen(number) + 1;
            free(number);
        }
        else if (infixNotation[i] == ' ')
        {
            continue;
        }
        else
        {
            *isError = true;
            printf("Invalid character.");
            return " ";
        }
    }

    while (!stackOfCharIsEmpty(stackOfChar))
    {
        if (isOpenBracket(stackOfCharTop(stackOfChar)))
        {
            *isError = true;
            printf("Missing bracket.");
            return " ";
        }

        if (postfixLength + 2 > postfixCapacity)
        {
            postfixCapacity *= 2;
            postfixNotation = realloc(postfixNotation, postfixCapacity);
        }

        char* operator = charToString(popChar(stackOfChar));
        strcat(postfixNotation, operator);
        strcat(postfixNotation, " ");
        postfixLength += 2;
        free(operator);
    }

    deleteStackOfChar(stackOfChar);
    return postfixNotation;
}

double calculatePostfixNotation(char* postfixNotation)
{
    struct StackOfDouble* stackOfDouble = createStackOfDouble();
    int inputStringLength = (int) strlen(postfixNotation);
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

    double result = popDouble(stackOfDouble);
    deleteStackOfDouble(stackOfDouble);
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

    if (isError)
    {
        return 0;
    }

    printf("Result: %lf", calculatePostfixNotation(postfixNotation));
    free(infixNotation);
    free(postfixNotation);
    return 0;
}