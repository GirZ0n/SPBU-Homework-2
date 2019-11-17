#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const int stringMaxSize = 512;

bool isSpecials(char input)
{
    return (input == ' ') || (input == '\n') || (input == '\t');
}

int main()
{
    FILE *input = fopen("input.txt", "r");

    int numberOfNonEmptyStrings = 0;
    char *inputString = malloc(sizeof(char) * stringMaxSize);
    for (int i = 0; i < stringMaxSize; i++)
    {
        inputString[i] = ' ';
    }

    if (input == NULL)
    {
        printf("Cant open the file");
        return 0;
    }

    bool isEmptyString = true;
    char inputChar = ' ';
    while (feof(input) == false)
    {
        inputChar = fgetc(input);
        if (inputChar == '\n')
        {
            isEmptyString = true;
        }
        if (isEmptyString)
        {
            if (!isSpecials(inputChar) && inputChar != EOF)
            {
                isEmptyString = false;
                numberOfNonEmptyStrings++;
            }
        }
    }

    printf("The number of non-empty lines = %d", numberOfNonEmptyStrings);
    free(inputString);
    fclose(input);
    return 0;
}