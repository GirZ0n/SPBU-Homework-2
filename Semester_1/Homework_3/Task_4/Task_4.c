#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void cleanStdin()
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != EOF && c != '\n');
}

bool isNatural(int inputNumber, int numberOfVariablesRead)
{
    return numberOfVariablesRead == 1 && inputNumber > 0;
}

void getNumberOfUsers(int* numberOfUsers)
{
    int numberOfVariablesRead = scanf("%d", numberOfUsers);
    while (isNatural(*numberOfUsers, numberOfVariablesRead) == false)
    {
        cleanStdin();
        printf("Enter the correct number of users:\n");
        numberOfVariablesRead = scanf("%d", numberOfUsers);
    }
    cleanStdin();
}

void getNumberOfActions(int* numberOfActions)
{
    int numberOfVariablesRead = scanf("%d", numberOfActions);
    while (isNatural(*numberOfActions, numberOfVariablesRead) == false)
    {
        cleanStdin();
        printf("Enter the correct number of actions:\n");
        numberOfVariablesRead = scanf("%d", numberOfActions);
    }
    cleanStdin();
}

void getTimeInterval(int* timePeriod)
{
    int numberOfVariablesRead = scanf("%d", timePeriod);
    while (isNatural(*timePeriod, numberOfVariablesRead) == false)
    {
        cleanStdin();
        printf("Enter the correct time interval:\n");
        numberOfVariablesRead = scanf("%d", timePeriod);
    }
    cleanStdin();
}


void getNumberOfUserActions(int* numberOfUserActions)
{
    int numberOfVariablesRead = scanf("%d", numberOfUserActions);
    while (isNatural(*numberOfUserActions, numberOfVariablesRead) == false)
    {
        cleanStdin();
        printf("Enter the correct number of user actions:\n");
        numberOfVariablesRead = scanf("%d", numberOfUserActions);
    }
    cleanStdin();
}

void getArray(int size, int* array)
{
    for (int i = 0; i < size; i++)
    {
        int numberOfVariablesRead = scanf("%d", &array[i]);
        if (isNatural(array[i], numberOfVariablesRead) == false)
        {
            printf("Input Error. Re-enter the array:\n");
            cleanStdin();
            i = -1;
            continue;
        }
    }
}

int main() 
{
    int numberOfUsers = 0;
    int numberOfActions = 0;
    int timeInterval = 0;
    printf("Enter the number of users (number > 0):\n");
    getNumberOfUsers(&numberOfUsers);
    printf("Enter the required number of actions (number > 0):\n");
    getNumberOfActions(&numberOfActions);
    printf("Enter the time interval: (number > 0)\n");
    getTimeInterval(&timeInterval);

    int answer = 0;
    for (int i = 0; i < numberOfUsers; i++)
    {
        int numberOfUserAction = 0;
        printf("Enter the number of actions the user %d performed (number > 0):\n", i + 1);
        getNumberOfUserActions(&numberOfUserAction);

        int count = 0;
        int* actions = calloc(sizeof(int), numberOfUserAction);
        printf("Enter how many minutes ago each action took place (numbers > 0):\n");
        getArray(numberOfUserAction, actions);

        for (int j = 0; j < numberOfUserAction; j++)
        {
            if (actions[j] <= timeInterval)
            {
                count++;
            }
        }

        if (count == numberOfActions)
        {
            answer++;
        }

        free(actions);
    }

    printf("Total performed %d action(-s) in the last %d minute(-s): %d user(-s)",
           numberOfActions, timeInterval, answer);
    return 0;
}
