#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

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

int caseHandlingNumber0(char currentSymbol)
{
    if (currentSymbol == '+' || currentSymbol == '-')
    {
        return 1;
    }
    else if (isdigit(currentSymbol))
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int caseHandlingNumber1(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int caseHandlingNumber2(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return 2;
    }
    else if (currentSymbol == '.')
    {
        return 3;
    }
    else if (currentSymbol == 'E')
    {
        return 5;
    }
    else if (currentSymbol == '\0')
    {
        return 8;
    }
    else
    {
        return -1;
    }
}

int caseHandlingNumber3(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return 4;
    }
    else
    {
        return -1;
    }
}

int caseHandlingNumber4(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return 4;
    }
    else if (currentSymbol == 'E')
    {
        return 5;
    }
    else if (currentSymbol == '\0')
    {
        return 8;
    }
    else
    {
        return -1;
    }
}

int caseHandlingNumber5(char currentSymbol)
{
    if (currentSymbol == '+' || currentSymbol == '-')
    {
        return 6;
    }
    else if (isdigit(currentSymbol))
    {
        return 7;
    }
    else
    {
        return -1;
    }
}

int caseHandlingNumber6(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return 7;
    }
    else
    {
        return -1;
    }
}

int caseHandlingNumber7(char currentSymbol)
{
    if (isdigit(currentSymbol))
    {
        return 7;
    }
    else if (currentSymbol == '\0')
    {
        return 8;
    }
    else
    {
        return -1;
    }
}

bool isRealNumber(char* input)
{
    int iterator = 0;
    int state = 0;
    char currentSymbol = input[iterator];
    while (true)
    {
        switch (state)
        {
            case 0:
            {
                state = caseHandlingNumber0(currentSymbol);
                break;
            }
            case 1:
            {
                state = caseHandlingNumber1(currentSymbol);
                break;
            }
            case 2:
            {
                state = caseHandlingNumber2(currentSymbol);
                break;
            }
            case 3:
            {
                state = caseHandlingNumber3(currentSymbol);
                break;
            }
            case 4:
            {
                state = caseHandlingNumber4(currentSymbol);
                break;
            }
            case 5:
            {
                state = caseHandlingNumber5(currentSymbol);
                break;
            }
            case 6:
            {
                state = caseHandlingNumber6(currentSymbol);
                break;
            }
            case 7:
            {
                state = caseHandlingNumber7(currentSymbol);
                break;
            }
            case 8:
            {
                return true;
            }
            case -1:
            {
                return false;
            }
        }
        currentSymbol = input[++iterator];
    }
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
        printf("This is not a real number");
    }
    free(input);
    return 0;
}