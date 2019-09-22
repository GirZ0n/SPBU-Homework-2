#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int numberOfCows()
{
    return 0;
}

int numberOfBulls()
{
    return 0;
}

int main()
{

    printf("I made up a four-digit number. Try to guess it ;) \n");

    srand(time(NULL));
    int randomNumber = rand() % 10000;

    int inputNumber = 0;
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
        printf("Number of bulls: %d \n", numberOfBulls());
        moves++;
    }
}