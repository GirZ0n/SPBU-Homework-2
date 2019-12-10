#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

const int numberLength = 4;

void numberToDigits(int* digits, int number)
{
    int i = 0;
    while (number > 0)
    {
        digits[i] = number % 10;
        number /= 10;
        i++;
    }
}

void countingNumberOfCowsAndBulls(int randomNumber, int inputNumber, int* numberOfCows, int* numberOfBulls)
{
    int* randomNumberDigits = calloc(numberLength, sizeof(int));
    numberToDigits(randomNumberDigits, randomNumber);

    int* inputNumberDigits = calloc(numberLength, sizeof(int));
    numberToDigits(inputNumberDigits, inputNumber);

    int countOfDigits[10] = {0};
    for (int i = 0; i < numberLength; i++)
    {
        if (randomNumberDigits[i] != inputNumberDigits[i])
        {
            countOfDigits[randomNumberDigits[i]]++;
            countOfDigits[inputNumberDigits[i]]++;
        }
        else
        {
            (*numberOfBulls)++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (countOfDigits[i] == 2)
        {
            (*numberOfCows)++;
        }
    }

    free(inputNumberDigits);
    free(randomNumberDigits);
}

int getRandomNumber()
{
    srand(time(NULL));
    int randomDigit = 1 + rand() % 9;
    int randomNumber = randomDigit * 1000;

    bool isUsed[10] = {false};
    isUsed[randomDigit] = true;

    int needToGenerate = 3;
    while (needToGenerate > 0)
    {
        randomDigit = rand() % 10;
        if (isUsed[randomDigit] == false)
        {
            randomNumber += randomDigit * (int) pow(10, needToGenerate - 1);
            isUsed[randomDigit] = true;
            needToGenerate--;
        }
    }

    return randomNumber;
}

int getNumberOfDigitsInNumber(int number)
{
    int numberOfDigits = 0;
    while (number > 0)
    {
        number /= 10;
        numberOfDigits++;
    }
    return numberOfDigits;
}

void cleanStdin()
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != EOF && c != '\n');
}

bool checkInputNumber(int inputNumber, int numberOfVariablesRead)
{
    if (numberOfVariablesRead != 1 || inputNumber < 0 || getNumberOfDigitsInNumber(inputNumber) != 4)
    {
        return false;
    }

    int* inputNumberDigits = calloc(numberLength, sizeof(int));
    numberToDigits(inputNumberDigits, inputNumber);
    int* numberOfDigits = calloc(10, sizeof(int));
    for (int i = 0; i < numberLength; i++)
    {
        numberOfDigits[inputNumberDigits[i]]++;
    }

    bool areDifferentDigits = true;
    for (int i = 0; i < 10; i++)
    {
        if (numberOfDigits[i] > 1)
        {
            areDifferentDigits = false;
            break;
        }
    }

    free(numberOfDigits);
    free(inputNumberDigits);
    return areDifferentDigits;
}

void getInputNumber(int* inputNumber)
{
    int numberOfVariablesRead = scanf("%d", inputNumber);
    while (checkInputNumber(*inputNumber, numberOfVariablesRead) == false)
    {
        cleanStdin();
        printf("Enter the correct number:\n");
        numberOfVariablesRead = scanf("%d", inputNumber);
    }
    cleanStdin();
}

int main()
{
    printf("I made up a four-digit number. Try to guess it ;)\n\n");
    printf("Attention! You must enter a positive four-digit number, which consists of different digits.\n");

    int moves = 1;
    int inputNumber = 0;
    int randomNumber = getRandomNumber();
    while (true)
    {
        printf("\nEnter the estimated number:\n");
        getInputNumber(&inputNumber);

        if (inputNumber == randomNumber)
        {
            printf("You WIN! (In %d moves)", moves);
            return 0;
        }

        int numberOfCows = 0;
        int numberOfBulls = 0;
        countingNumberOfCowsAndBulls(randomNumber, inputNumber, &numberOfCows, &numberOfBulls);

        printf("Number of cows: %d \n", numberOfCows);
        printf("Number of bulls: %d \n", numberOfBulls);
        moves++;
    }
}