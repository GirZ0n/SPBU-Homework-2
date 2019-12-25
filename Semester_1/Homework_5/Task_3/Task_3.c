#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "convertInfixToPostfix.h"
#include "calculatePostfixNotation.h"

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