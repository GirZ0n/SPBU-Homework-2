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

int cowsCount(int randomNumber, int inputNumber)
{
    int* randomNumberDigits = malloc(sizeof(int) * numberLength);
    for (int i = 0; i < numberLength; i++)
    {
        randomNumberDigits[i] = 0;
    }
    numberToDigits(randomNumberDigits, randomNumber);

    int* inputNumberDigits = malloc(sizeof(int) * numberLength);
    for (int i = 0; i < numberLength; i++)
    {
        inputNumberDigits[i] = 0;
    }
    numberToDigits(inputNumberDigits, inputNumber);

    int countOfDigits[10] = {0};
    for (int i = 0; i < numberLength; i++)
    {
        if (randomNumberDigits[i] != inputNumberDigits[i])
        {
            countOfDigits[randomNumberDigits[i]]++;
            countOfDigits[inputNumberDigits[i]]++;
        }
    }

    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (countOfDigits[i] == 2)
        {
            count++;
        }
    }

    free(inputNumberDigits);
    free(randomNumberDigits);
    return count;
}

int bullsCount(int randomNumber, int inputNumber)
{
    int* randomNumberDigits = malloc(sizeof(int) * numberLength);
    for (int i = 0; i < numberLength; i++)
    {
        randomNumberDigits[i] = 0;
    }
    numberToDigits(randomNumberDigits, randomNumber);

    int* inputNumberDigits = malloc(sizeof(int) * numberLength);
    for (int i = 0; i < numberLength; i++)
    {
        inputNumberDigits[i] = 0;
    }
    numberToDigits(inputNumberDigits, inputNumber);

    int count = 0;
    for (int i = 0; i < numberLength; i++)
    {
        if (randomNumberDigits[i] == inputNumberDigits[i])
        {
            count++;
        }
    }

    free(inputNumberDigits);
    free(randomNumberDigits);
    return count;
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

bool checkInputNumber(int inputNumber, int isCorrect)
{
    if (isCorrect != 1 || inputNumber < 0 || getNumberOfDigitsInNumber(inputNumber) != 4)
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
    int isCorrect = scanf("%d", inputNumber);
    while (checkInputNumber(*inputNumber, isCorrect) == false)
    {
        cleanStdin();
        printf("Enter the correct number: ");
        isCorrect = scanf("%d", inputNumber);
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
        printf("\nEnter the estimated number: ");
        getInputNumber(&inputNumber);

        if (inputNumber == randomNumber)
        {
            printf("You WIN! (In %d moves)", moves);
            return 0;
        }

        printf("Number of cows: %d \n", cowsCount(randomNumber, inputNumber));
        printf("Number of bulls: %d \n", bullsCount(randomNumber, inputNumber));
        moves++;
    }
}