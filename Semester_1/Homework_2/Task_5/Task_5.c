#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int maxSize = 256;

void symbolsCount(char string[], int amountOfSymbols[])
{
    return;
}

bool isEqual(int amountOfSymbolsInString1[], int amountOfSymbolsInString2[])
{
    return false;
}

int main()
{
    int amountOfSymbolsInString1[256] = {0};
    int amountOfSymbolsInString2[256] = {0};

    char inputString1[256] = "";
    printf("Enter the string #1: ");
    scanf("%s", &inputString1);
    char inputString2[256] = "";
    printf("Enter the string #2: ");
    scanf("%s", &inputString2);

    symbolsCount(inputString1, amountOfSymbolsInString1);
    symbolsCount(inputString2, amountOfSymbolsInString2);

    if (isEqual(amountOfSymbolsInString1, amountOfSymbolsInString2))
    {
        printf("From the first string you CAN get the second!");
        return 0;
    }

    printf("From the first line you CANNOT get the second :(");
}