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

void countOfDigits(int * count, int digits[4])
{
    for (int i = 0; i < 4; i++)
    {
        count[digits[i]]++;
    }
}

int numberOfCows(int randomNumberDigits[], int inputNumberDigits[])
{
    int countOfRandomNumberDigits[10] = {0};
    int countOfInputNumberDigits[10] = {0};

    countOfDigits(countOfRandomNumberDigits, randomNumberDigits);
    countOfDigits(countOfInputNumberDigits, inputNumberDigits);

    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (countOfRandomNumberDigits[i] == countOfInputNumberDigits[i])
        {
            count += countOfRandomNumberDigits[i];
        }
    }

    return count;
}

int numberOfBulls(int randomNumberDigits[], int inputNumberDigits[])
{
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
    int randomNumberDigits[4] = {0};
    numberToDigits(randomNumberDigits, randomNumber);

    int moves = 1;
    int inputNumber = 0;
    int inputNumberDigits[4] = {0};
    while (true)
    {
        printf("Enter the estimated number:");
        scanf("%d", &inputNumber);

        if (inputNumber == randomNumber)
        {
            printf("You WIN! (In %d moves)", moves);
            return 0;
        }

        numberToDigits(inputNumberDigits, inputNumber);

        printf("Number of cows: %d \n", numberOfCows(randomNumberDigits, inputNumberDigits));
        printf("Number of bulls: %d \n", numberOfBulls(randomNumberDigits, inputNumberDigits));
        moves++;
    }
}