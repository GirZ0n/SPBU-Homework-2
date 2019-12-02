#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    return count;
}

int integerPow(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;
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
            randomNumber += randomDigit * integerPow(10, needToGenerate - 1);
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

bool checkInputNumber(int inputNumber, bool isCorrect)
{
    if (!isCorrect)
    {
        printf("Input Error. ");
        return false;
    }

    if (inputNumber < 0)
    {
        printf("Need a number >= 0. ");
        return false;
    }

    if (getNumberOfDigitsInNumber(inputNumber) != 4)
    {
        printf("Need a four-digit number. ");
        return false;
    }

    return true;
}

void getInputNumber(int* inputNumber)
{
    bool isCorrect = scanf("%d", inputNumber);;
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
    printf("I made up a four-digit number. Try to guess it ;) \n");

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
