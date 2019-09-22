#include <stdio.h>
#include <string.h>

const int maxSize = 256;

int charToInt(char input)
{
    return input - '0';
}

int main() {
    int amountOfNumbers[10] = {0};
    char number[maxSize] = "";
    printf("Enter the number: ");
    scanf("%s", &number);

    for (int i = 0; i < strlen(number); i++)
    {
        amountOfNumbers[charToInt(number[i])]++;
    }

    printf("Smallest number: ");
    for (int i = 1; i < 10; i++)
    {
        if (amountOfNumbers[i] > 0)
        {
            printf("%d", i);
            amountOfNumbers[i]--;
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        while (amountOfNumbers[i] > 0)
        {
            printf("%d", i);
            amountOfNumbers[i]--;
        }
    }

    return 0;
}