#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const int stringMaxSize = 512;

bool isSpecials(char input)
{
    return (input == ' ') || (input == '\n') || (input == '\t');
}

bool isEmpty(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (!isSpecials(string[i]))
        {
            return false;
        }
    }

    return true;
}

int main() {
    FILE *input = fopen("input.txt", "r");

    int numberOfNonEmptyStrings = 0;
    char *inputString = malloc(sizeof(char) * stringMaxSize);
    for (int i = 0; i < tringMaxSize; i++)
    {
        inputString[i] = ' ';
    }
    
    if (input == NULL)
    {
        printf("Cant open the file");
        return 0;
    }
    else
    {
        while (feof(input) == false)
        {
            fgets(inputString, stringMaxSize, input);
            if (!isEmpty(inputString))
            {
                numberOfNonEmptyStrings++;
            }
        }
    }

    printf("The number of non-empty lines = %d", numberOfNonEmptyStrings);

    free(inputString);
    fclose(input);
    return 0;
}
