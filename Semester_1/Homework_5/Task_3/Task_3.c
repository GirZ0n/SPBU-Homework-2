#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackOfChar.h"
#include "stackOfDouble.h"
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
        default:
        {
            return 0;
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

bool operatorProcessing(char* infixNotation, int currentIndex, char* postfixNotation, int* sizeOfPostfix,
                        StackOfChar* stack, bool* isNextNumber)
{
    while (!stackOfCharIsEmpty(stack) && isLessPriority(infixNotation[currentIndex], stackOfCharTop(stack))
           && !isOpenBracket(stackOfCharTop(stack)))
    {
        postfixNotation[(*sizeOfPostfix)++] = popChar(stack);
        postfixNotation[(*sizeOfPostfix)++] = ' ';
    }

    pushChar(infixNotation[currentIndex], stack);

    if (*isNextNumber)
    {
        return false;
    }

    *isNextNumber = true;
    return true;
}

bool closeBracketProcessing(char* postfixNotation, int* sizeOfPostfix, StackOfChar* stack)
{
    while (!stackOfCharIsEmpty(stack) && !isOpenBracket(stackOfCharTop(stack)))
    {
        postfixNotation[(*sizeOfPostfix)++] = popChar(stack);
        postfixNotation[(*sizeOfPostfix)++] = ' ';
    }

    if (!stackOfCharIsEmpty(stack))
    {
        popChar(stack);
    }
    else
    {
        return false;
    }

    return true;
}

bool numberProcessing(char* infixNotation, int* indexOfStart, char** postfixNotation, int* sizeOfPostfix,
                      bool* isNextNumber)
{
    if (!(*isNextNumber))
    {
        return false;
    }

    writeNumberToString(infixNotation, indexOfStart, *postfixNotation, sizeOfPostfix);
    *isNextNumber = false;
    return true;
}

void errorProcessing(bool* isError, char* postfixNotation, StackOfChar* stack, char* errorMessage)
{
    printf("%s", errorMessage);
    *isError = true;
    deleteStackOfChar(stack);
    free(postfixNotation);
}

char* convertInfixToPostfix(char* infixNotation, bool* isError)
{
    StackOfChar* stack = createStackOfChar();
    int sizeOfPostfix = 0;
    bool isNextNumber = true;
    char* postfixNotation = calloc(strlen(infixNotation) * 2 + 1, sizeof(char));

    int inputStringLength = (int) strlen(infixNotation);
    for (int i = 0; i < inputStringLength; i++)
    {
        if (isOperator(infixNotation, i))
        {
            if(!operatorProcessing(infixNotation, i, postfixNotation, &sizeOfPostfix, stack, &isNextNumber))
            {
                errorProcessing(isError, postfixNotation, stack, "Missing number. ");
                return " ";
            }
        }
        else if (isCloseBracket(infixNotation[i]))
        {
            if (!closeBracketProcessing(postfixNotation, &sizeOfPostfix, stack))
            {
                errorProcessing(isError, postfixNotation, stack, "Missing bracket. ");
                return " ";
            }
        }
        else if (isOpenBracket(infixNotation[i]))
        {
            pushChar(infixNotation[i], stack);
        }
        else if (isUnaryNegative(infixNotation, i) || isDigit(infixNotation[i]))
        {
            if (!numberProcessing(infixNotation, &i, &postfixNotation, &sizeOfPostfix, &isNextNumber))
            {
                errorProcessing(isError, postfixNotation, stack, "Missing operator. ");
                return "";
            }
        }
        else if (infixNotation[i] == ' ')
        {
            continue;
        }
        else
        {
            errorProcessing(isError, postfixNotation, stack, "Invalid character. ");
            return " ";
        }
    }

    if (isNextNumber)
    {
        errorProcessing(isError, postfixNotation, stack, "Missing number. ");
        return " ";
    }

    if (fillingPostfixNotation(postfixNotation, &sizeOfPostfix, stack) == false)
    {
        errorProcessing(isError, postfixNotation, stack, "Missing bracket. ");
        return " ";
    }

    deleteStackOfChar(stack);
    return postfixNotation;
}

void operatorProcessingInCalculatePostfixNotation(char* postfixNotation, int index, StackOfDouble* stack)
{
    double operandB = popDouble(stack);
    double operandA = popDouble(stack);
    double result = getResultOfOperation(operandA, operandB, postfixNotation[index]);
    pushDouble(result, stack);
}

double calculatePostfixNotation(char* postfixNotation)
{
    struct StackOfDouble* stack = createStackOfDouble();
    int inputStringLength = (int) strlen(postfixNotation);
    for (int i = 0; i < inputStringLength; i++)
    {
        if (isOperator(postfixNotation, i))
        {
            operatorProcessingInCalculatePostfixNotation(postfixNotation, i, stack);
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

void expandString(int length, int* capacity, char** string)
{
    if (length + 1 == *capacity)
    {
        *capacity *= 2;
        *string = realloc(*string, *capacity * sizeof(char));
    }
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
        expandString(length, &capacity, &string);
        string[length] = input;
        length++;
        scanf("%c", &input);
    }
    string[length] = '\0';
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
        printf("Try again.");
        free(infixNotation);
        return 0;
    }

    double result = calculatePostfixNotation(postfixNotation);
    printf("Result:\n%lf", result);

    free(infixNotation);
    free(postfixNotation);
    return 0;
}