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

bool isRealNumber(char* input)
{
    int iterator = 0;
    int state = 0;
    char currentSymbol = input[iterator];
    while(true)
    {
        switch (state)
        {
            case 0:
            {
                if (currentSymbol == '+' || currentSymbol == '-')
                {
                    state = 1;
                }
                else if (isdigit(currentSymbol))
                {
                    state = 2;
                }
                else
                {
                    return false;
                }
                break;
            }
            case 1:
            {
                if (isdigit(currentSymbol))
                {
                    state = 2;
                }
                else
                {
                    return false;
                }
                break;
            }
            case 2:
            {
                if (isdigit(currentSymbol))
                {
                    state = 2;
                }
                else if (currentSymbol == '.')
                {
                    state = 3;
                }
                else if (currentSymbol == 'E')
                {
                    state = 5;
                }
                else if (currentSymbol == '\0')
                {
                    state = 8;
                }
                else
                {
                    return false;
                }
                break;
            }
            case 3:
            {
                if (isdigit(currentSymbol))
                {
                    state = 4;
                }
                else
                {
                    return false;
                }
                break;
            }
            case 4:
            {
                if (isdigit(currentSymbol))
                {
                    state = 4;
                }
                else if (currentSymbol == 'E')
                {
                    state = 5;
                }
                else if (currentSymbol == '\0')
                {
                    state = 8;
                }
                else
                {
                    return false;
                }
                break;
            }
            case 5:
            {
                if (currentSymbol == '+' || currentSymbol == '-')
                {
                    state = 6;
                }
                else if (isdigit(currentSymbol))
                {
                    state = 7;
                }
                else
                {
                    return false;
                }
                break;
            }
            case 6:
            {
                if (isdigit(currentSymbol))
                {
                    state = 7;
                }
                else
                {
                    return false;
                }
                break;
            }
            case 7:
            {
                if (isdigit(currentSymbol))
                {
                    state = 7;
                }
                else if (currentSymbol == '\0')
                {
                    state = 8;
                }
                else
                {
                    return false;
                }
                break;
            }
            case 8:
            {
                return true;
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