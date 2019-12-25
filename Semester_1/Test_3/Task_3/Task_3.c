#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef enum State State;

enum State
{
    error = -1,
    numberBegin,
    numberFirstDigit,
    numberSecondDigit,
    letter,
    groupFirstDigit,
    groupSecondDigit,
    hyphen,
    firstM,
    secondM,
    end,
};

char* getStringFromConsole()
{
    int length = 0;
    int capacity = 2;
    char* string = calloc(capacity, sizeof(char));
    char input = ' ';
    scanf("%c", &input);
    while (input != '\n')
    {
        if (length + 1 == capacity)
        {
            capacity *= 2;
            string = realloc(string, capacity);
        }

        string[length] = input;
        length++;
        scanf("%c", &input);
    }
    string[length] = '\0';
    return string;
}

int numberBeginHandling(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return numberFirstDigit;
    }
    else
    {
        return error;
    }
}

int numberFirstDigitHandling(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return numberSecondDigit;
    }
    else
    {
        return error;
    }
}

int numberSecondDigitHandling(char currentSymbol)
{
    if (currentSymbol == 'B' || currentSymbol == 'M' || currentSymbol == 'S')
    {
        return letter;
    }
    else
    {
        return error;
    }
}

int letterHandling(char currentSymbol)
{
    if (currentSymbol == '1')
    {
        return groupFirstDigit;
    }
    else if (currentSymbol - '1' > 0 && currentSymbol - '9' <= 0)
    {
        return groupSecondDigit;
    }
    else
    {
        return error;
    }
}

int groupFirstDigitHandling(char currentSymbol)
{
    if (currentSymbol == '0')
    {
        return groupSecondDigit;
    }
    else
    {
        return error;
    }
}

int groupSecondDigitHandling(char currentSymbol)
{
    if (currentSymbol == '-')
    {
        return hyphen;
    }
    else
    {
        return error;
    }
}

int hyphenHandling(char currentSymbol)
{
    if (currentSymbol == 'm')
    {
        return firstM;
    }
    else
    {
        return error;
    }
}

int firstMHandling(char currentSymbol)
{
    if (currentSymbol == 'm')
    {
        return secondM;
    }
    else
    {
        return error;
    }
}

int secondMHandling(char currentSymbol)
{
    if (currentSymbol == '\0' || currentSymbol == '\n')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isGroupNumber(char* string)
{
    State currentState;
    currentState = numberBegin;
    int iterator = 0;
    char currentSymbol = string[iterator];
    int stringLength = (int) strlen(string);
    while (iterator < stringLength + 1)
    {
        switch (currentState)
        {
            case numberBegin:
            {
                currentState = numberBeginHandling(currentSymbol);
                break;
            }
            case numberFirstDigit:
            {
                currentState = numberFirstDigitHandling(currentSymbol);
                break;
            }
            case numberSecondDigit:
            {
                currentState = numberSecondDigitHandling(currentSymbol);
                break;
            }
            case letter:
            {
                currentState = letterHandling(currentSymbol);
                break;
            }
            case groupFirstDigit:
            {
                currentState = groupFirstDigitHandling(currentSymbol);
                break;
            }
            case groupSecondDigit:
            {
                currentState = groupSecondDigitHandling(currentSymbol);
                break;
            }
            case hyphen:
            {
                currentState = hyphenHandling(currentSymbol);
                break;
            }
            case firstM:
            {
                currentState = firstMHandling(currentSymbol);
                break;
            }
            case secondM:
            {
                return secondMHandling(currentSymbol);
            }
            case end:
            {
                return true;
            }
            case error:
            {
                return false;
            }
            default:
            {
                return false;
            }
        }
        currentSymbol = string[++iterator];
    }

    return false;
}

int main()
{
    printf("Enter the string:\n");
    char* input = getStringFromConsole();
    if (isGroupNumber(input))
    {
        printf("This is the group number.");
    }
    else
    {
        printf("This is not the group number.");
    }
    free(input);
    return 0;
}