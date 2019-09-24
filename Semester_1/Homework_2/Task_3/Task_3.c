#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void numberToDigits(int * digits, int number)
{
    int i = 0;
    while(number > 0)
    {
        digits[i] = number % 10;
        number /= 10;
        i++;
    }
}

int countOfDigits(int * count, int digits[])
{
    return 0;
}

int numberOfCows(int randomNumber, int inputNumber)
{
    int randomNumberDigits[4] = {0};
    int inputNumberDigits[4] = {0};

    numberToDigits(randomNumberDigits, randomNumber);
    numberToDigits(inputNumberDigits, inputNumber);

    int countOfRandomNumberDigits[10] = {0};
    int countOfInputNumberDigits[10] = {0};

    countOfDigits(countOfRandomNumberDigits, randomNumberDigits);
    countOfDigits(countOfInputNumberDigits, inputNumberDigits);

    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (countOfRandomNumberDigits[i] == countOfInputNumberDigits[i])
        {
            count++;
        }
    }

    return count;
}

int numberOfBulls(int randomNumber, int inputNumber)
{
    int randomNumberDigits[4] = {0};
    int inputNumberDigits[4] = {0};

    numberToDigits(randomNumberDigits, randomNumber);
    numberToDigits(inputNumberDigits, inputNumber);

    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (randomNumberDigits[i] == inputNumberDigits[i])
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
    printf("%d", randomNumber);

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

        printf("Number of cows: %d \n", numberOfCows(randomNumber, inputNumber));
        printf("Number of bulls: %d \n", numberOfBulls(randomNumber, inputNumber));
        moves++;
    }
}