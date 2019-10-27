#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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

bool infixToPostfix (char* infixNotation, int* sizeOfPostfixNotation,
                     int* postfixNotationNumbers, char* postfixNotationOperators)
{
    struct StackOfChar* stackOfChar = createStackOfChar();

    int infixNotationLength = strlen(infixNotation);
    for (int i = 0; i < infixNotationLength; i++)
    {
        if (isOperator(infixNotation, i))
        {
            while (!stackOfCharIsEmpty(stackOfChar) && isLessPriority(infixNotation[i], stackOfCharTop(stackOfChar))
                   && !isOpenBracket(stackOfCharTop(stackOfChar)))
            {
                postfixNotationOperators[*sizeOfPostfixNotation] = popChar(stackOfChar);
                (*sizeOfPostfixNotation)++;
            }

            pushChar(infixNotation[i], stackOfChar);
        }
        else if (isCloseBracket(infixNotation[i]))
        {
            while (!stackOfCharIsEmpty(stackOfChar) && !isOpenBracket(stackOfCharTop(stackOfChar)))
            {
                postfixNotationOperators[*sizeOfPostfixNotation] = popChar(stackOfChar);
                (*sizeOfPostfixNotation)++;
            }

            if (!stackOfCharIsEmpty(stackOfChar))
            {
                popChar(stackOfChar);
            }
            else
            {
                printf("Missing bracket");
                return false;
            }
        }
        else if (isOpenBracket(infixNotation[i]))
        {
            pushChar(infixNotation[i], stackOfChar);
        }
        else if (isUnaryNegative(infixNotation, i) || isDigit(infixNotation[i]))
        {
            postfixNotationNumbers[*sizeOfPostfixNotation] = getNumber(infixNotation, &i);
            (*sizeOfPostfixNotation)++;
        }
        else if (infixNotation[i] == ' ')
        {
            continue;
        }
        else
        {
            printf("Invalid character");
            return false;
        }
    }


    while (!stackOfCharIsEmpty(stackOfChar))
    {
        if (isOpenBracket(stackOfCharTop(stackOfChar)))
        {
            printf("Missing bracket");
            return 0;
        }

        postfixNotationOperators[*sizeOfPostfixNotation] = popChar(stackOfChar);
        (*sizeOfPostfixNotation)++;
    }

    return true;
}

double calculatePostfixNotation(int sizeOfPostfixNotation, int* postfixNotationNumbers,
                                char* postfixNotationOperators)
{
    struct StackOfDouble* stackOfDouble = createStackOfDouble();
    for (int i = 0; i < sizeOfPostfixNotation; i++)
    {
        if (postfixNotationOperators[i] != ' ')
        {
            double operandB = popDouble(stackOfDouble);
            double operandA = popDouble(stackOfDouble);
            double result = getResultOfOperation(operandA, operandB, postfixNotationOperators[i]);
            pushDouble(result, stackOfDouble);
        }
        else
        {
            pushDouble(postfixNotationNumbers[i], stackOfDouble);
        }
    }

    return popDouble(stackOfDouble);
}

int main()
{
    printf("Enter an expression in the infix notation:\n");
    char infixNotation[maxSize] = "\0";
    scanf("%[^\n]", infixNotation);

    int sizeOfPostfixNotation = 0;
    int postfixNotationNumbers[maxSize] = {0};
    char postfixNotationOperators[maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        postfixNotationOperators[i] = ' ';
    }

    if (infixToPostfix(infixNotation, &sizeOfPostfixNotation,
            postfixNotationNumbers, postfixNotationOperators) == false)
    {
        return 0;
    }



    printf("Result: %lf", calculatePostfixNotation(sizeOfPostfixNotation, postfixNotationNumbers,
            postfixNotationOperators));
    return 0;
}