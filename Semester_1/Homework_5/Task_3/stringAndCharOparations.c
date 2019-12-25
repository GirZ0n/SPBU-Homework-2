#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stringAndCharOparations.h"

bool isOpenBracket(char inputChar)
{
    return inputChar == '(';
}

bool isCloseBracket(char inputChar)
{
    return inputChar == ')';
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

bool isDigit(char inputChar)
{
    return inputChar - '0' >= 0 && inputChar - '0' <= 9;
}

bool isUnaryNegative(char* string, int indexOfCheck)
{
    if (string[indexOfCheck] == '-' && indexOfCheck + 1 < strlen(string))
    {
        return isDigit(string[indexOfCheck + 1]);
    }

    return false;
}

bool isOperator(char* string, int indexOfCheck)
{
    if (isUnaryNegative(string, indexOfCheck))
    {
        return false;
    }

    return string[indexOfCheck] == '+' || string[indexOfCheck] == '-' ||
           string[indexOfCheck] == '*' || string[indexOfCheck] == '/';
}

double getNumberAsDouble(char* string, int* indexOfCurrentPosition)
{
    int number = 0;
    if (isDigit(string[*indexOfCurrentPosition]))
    {
        number = string[*indexOfCurrentPosition] - '0';
    }

    int indexOfStart = *indexOfCurrentPosition;

    int inputLength = (int) strlen(string);
    while (*indexOfCurrentPosition + 1 < inputLength && isDigit(string[*indexOfCurrentPosition + 1]))
    {
        number = number * 10 + (string[*indexOfCurrentPosition + 1] - '0');
        (*indexOfCurrentPosition)++;
    }

    if (string[indexOfStart] == '-')
    {
        number *= -1;
    }

    return (double) number;
}

void expandNumber(int size, int* capacity, char** number)
{
    if (size == *capacity)
    {
        *capacity *= 2;
        *number = realloc(*number, *capacity * sizeof(char));
    }
}

char* getNumberAsString(char* string, int* indexOfStart)
{
    int size = 0;
    int capacity = 2;
    char* number = calloc(capacity, sizeof(char));
    number[size] = string[*indexOfStart];
    size++;

    int inputLength = (int) strlen(string);
    while (*indexOfStart + 1 < inputLength && isDigit(string[*indexOfStart + 1]))
    {
        expandNumber(size, &capacity, &number);
        number[size] = string[*indexOfStart + 1];
        size++;
        (*indexOfStart)++;
    }
    number = realloc(number, sizeof(char) * (size + 1));
    number[size] = '\0';
    return number;
}

void writeNumberToString(char* source, int* indexOfStart, char* destination, int* sizeOfDestination)
{
    char* number = getNumberAsString(source, indexOfStart);
    int numberLength = (int) strlen(number);
    for (int i = 0; i < numberLength; i++)
    {
        destination[(*sizeOfDestination) + i] = number[i];
    }
    (*sizeOfDestination) += numberLength;
    destination[*sizeOfDestination] = ' ';
    (*sizeOfDestination)++;
    free(number);
}