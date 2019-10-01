#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int maxSize = 256;

bool areEqual(char inputString[], char inputSubstring[], int begin)
{
    int inputSubstringLength = strlen(inputSubstring);

    for(int j = 0; j < inputSubstringLength; j++)
    {
        if (inputString[begin + j] != inputSubstring[j])
        {
            return false;
        }
    }

    return true;
}

int countTheNumberOfEntries(char *inputString, char *inputSubstring)
{
    int count = 0;
    int inputSubstringLength = strlen(inputSubstring);
    int inputStringLength = strlen(inputString);

    for (int i = 0; i < inputStringLength - inputSubstringLength + 1; i++)
    {
        if (areEqual(inputString, inputSubstring, i))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    char inputString[maxSize] = "";
    char inputSubstring[maxSize] = "";
    printf("Enter the string:");
    scanf("%s", &inputString);
    printf("Enter the substring:");
    scanf("%s", &inputSubstring);

    printf("The number of occurrences of a substring '%s' in a string '%s' = %d", inputSubstring, inputString,
           countTheNumberOfEntries(inputString, inputSubstring));
    return 0;
}
