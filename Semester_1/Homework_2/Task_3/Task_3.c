#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int indexOfDigitToInt(int number, int index)
{
    int digits[4] = {0};
    digits[0] = number / 1000;
    digits[1] = number % 1000 / 100;
    digits[2] = number % 100 / 10;
    digits[3] = number % 10;

    return digits[index];
}

int numberOfCows()
{
    return 0;
}

int numberOfBulls(int randomNumber, int inputNumber)
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (indexOfDigitToInt(randomNumber, i) == indexOfDigitToInt(inputNumber, i))
        {
            count++;
        }
    }
    return count;
}

int main()
{

    printf("I made up a four-digit number. Try to guess it ;) \n");

    srand(time(NULL));
    int randomNumber = rand() % 10000;
    int inputNumber = 0;
    //printf("%d", randomNumber);

    int moves = 1;
    while (true)
    {
        printf("Enter the estimated number:");
        scanf("%d", &inputNumber);

        if (inputNumber == randomNumber)
        {
            printf("You WIN! (In %d moves)", moves);
            return 0;
        }

        printf("Number of cows: %d \n", numberOfCows());
        printf("Number of bulls: %d \n", numberOfBulls(randomNumber, inputNumber));
        moves++;
    }
}