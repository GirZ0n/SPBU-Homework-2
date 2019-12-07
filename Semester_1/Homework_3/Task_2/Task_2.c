#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSpecials(char input)
{
    return (input == ' ') || (input == '\n') || (input == '\t');
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Can't open the file");
        return 0;
    }

    int numberOfNonEmptyStrings = 0;
    bool isEmptyString = true;
    char inputChar = ' ';
    while (feof(input) == false)
    {
        inputChar = (char) fgetc(input);
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
    fclose(input);
    return 0;
}