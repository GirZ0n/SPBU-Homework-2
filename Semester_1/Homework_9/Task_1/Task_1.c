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
    numberSign,
    integerPart,
    dot,
    fractionalPart,
    exponentBegin,
    exponentSign,
    exponentPart,
    end
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
        if (length == capacity)
        {
            capacity *= 2;
            string = realloc(string, capacity);
        }

        string[length] = input;
        length++;
        scanf("%c", &input);
    }
    string = realloc(string, (length + 1) * sizeof(char));
    string[length] = '\0';
    return string;
}

int numberBeginHandling(char currentSymbol)
{
    if (currentSymbol == '+' || currentSymbol == '-')
    {
        return numberSign;
    }
    else if (isdigit(currentSymbol))
    {
        return integerPart;
    }
    else
    {
        return error;
    }
}

int numberSignHandling(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return integerPart;
    }
    else
    {
        return error;
    }
}

int integerPartHandling(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return integerPart;
    }
    else if (currentSymbol == '.')
    {
        return dot;
    }
    else if (currentSymbol == 'E')
    {
        return exponentBegin;
    }
    else if (currentSymbol == '\0')
    {
        return end;
    }
    else
    {
        return error;
    }
}

int dotHandling(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return fractionalPart;
    }
    else
    {
        return error;
    }
}

int fractionalPartHandling(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return fractionalPart;
    }
    else if (currentSymbol == 'E')
    {
        return exponentBegin;
    }
    else if (currentSymbol == '\0')
    {
        return end;
    }
    else
    {
        return error;
    }
}

int exponentBeginHandling(char currentSymbol)
{
    if (currentSymbol == '+' || currentSymbol == '-')
    {
        return exponentSign;
    }
    else if (isdigit(currentSymbol))
    {
        return exponentPart;
    }
    else
    {
        return error;
    }
}

int exponentSignHandling(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return exponentPart;
    }
    else
    {
        return error;
    }
}

int exponentPartHandling(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return exponentPart;
    }
    else if (currentSymbol == '\0')
    {
        return end;
    }
    else
    {
        return error;
    }
}

bool isRealNumber(char* string)
{
    State currentState;
    currentState = numberBegin;
    int iterator = 0;
    char currentSymbol = string[iterator];
    int stringLength = (int) strlen(string);
    while (iterator < stringLength)
    {
        switch (currentState)
        {
            case numberBegin:
            {
                currentState = numberBeginHandling(currentSymbol);
                break;
            }
            case numberSign:
            {
                currentState = numberSignHandling(currentSymbol);
                break;
            }
            case integerPart:
            {
                currentState = integerPartHandling(currentSymbol);
                break;
            }
            case dot:
            {
                currentState = dotHandling(currentSymbol);
                break;
            }
            case fractionalPart:
            {
                currentState = fractionalPartHandling(currentSymbol);
                break;
            }
            case exponentBegin:
            {
                currentState = exponentBeginHandling(currentSymbol);
                break;
            }
            case exponentSign:
            {
                currentState = exponentSignHandling(currentSymbol);
                break;
            }
            case exponentPart:
            {
                currentState = exponentPartHandling(currentSymbol);
                break;
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
    if (isRealNumber(input))
    {
        printf("This is a real number.");
    }
    else
    {
        printf("This is not a real number.");
    }
    free(input);
    return 0;
}