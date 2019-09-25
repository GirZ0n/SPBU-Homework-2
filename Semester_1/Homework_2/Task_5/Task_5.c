#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int maxSize = 512;

void symbolsCount(char string[], int amountOfSymbols[])
{
    int stringLength = strlen(string);
    for (int i = 0; i < stringLength; i++)
    {
        amountOfSymbols[(int)string[i]]++;
    }
}

bool areEqual(int amountOfSymbolsInString1[], int amountOfSymbolsInString2[])
{
    for (int i = 0; i < 256; i++)
    {
        if (amountOfSymbolsInString1[i] != amountOfSymbolsInString2[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int amountOfSymbolsInString1[256] = {0};
    int amountOfSymbolsInString2[256] = {0};

    char inputString1[maxSize] = "";
    printf("Enter the string #1: ");
    scanf("%s", &inputString1);
    char inputString2[maxSize] = "";
    printf("Enter the string #2: ");
    scanf("%s", &inputString2);

    symbolsCount(inputString1, amountOfSymbolsInString1);
    symbolsCount(inputString2, amountOfSymbolsInString2);

    if (areEqual(amountOfSymbolsInString1, amountOfSymbolsInString2))
    {
        printf("From the first string you CAN get the second!");
        return 0;
    }

    printf("From the first string you CANNOT get the second :(");
    return 0;
}
