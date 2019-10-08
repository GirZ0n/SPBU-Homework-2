#include <stdio.h>
#include <string.h>

const int maxSize = 256;

int charToInt(char input)
{
    return input - '0';
}

int main() {
    int amountOfDigits[10] = {0};
    char number[maxSize] = "";
    printf("Enter the number: ");
    scanf("%s", &number);

    int numberLength = strlen(number);
    for (int i = 0; i < numberLength; i++)
    {
        amountOfDigits[charToInt(number[i])]++;
    }

    printf("Smallest number: ");
    for (int i = 1; i < 10; i++)
    {
        if (amountOfDigits[i] > 0)
        {
            printf("%d", i);
            amountOfDigits[i]--;
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        while (amountOfDigits[i] > 0)
        {
            printf("%d", i);
            amountOfDigits[i]--;
        }
    }

    return 0;
}
