#include <stdio.h>
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

bool isNaturalNumber(int inputNumber, bool isCorrect)
{
    if (!isCorrect)
    {
        printf("Input Error. ");
        return false;
    }

    if (inputNumber < 1)
    {
        printf("Need a number >= 1. ");
        return false;
    }

    return true;
}

bool isNotNegative(int timePeriod, bool isCorrect)
{
    if (!isCorrect)
    {
        printf("Input Error. ");
        return false;
    }

    if (timePeriod < 0)
    {
        printf("Need a number >= 0. ");
        return false;
    }

    return true;
}

void getNumberOfUsers(int* numberOfUsers)
{
    bool isCorrect = scanf("%d", numberOfUsers);
    while (isNaturalNumber(*numberOfUsers, isCorrect) == false)
    {
        cleanStdin();
        printf("Enter the correct number of users: ");
        isCorrect = scanf("%d", numberOfUsers);
    }
    cleanStdin();
}

void getNumberOfActions(int* numberOfActions)
{
    bool isCorrect = scanf("%d", numberOfActions);
    while (isNaturalNumber(*numberOfActions, isCorrect) == false)
    {
        cleanStdin();
        printf("Enter the correct number of actions: ");
        isCorrect = scanf("%d", numberOfActions);
    }
    cleanStdin();
}

void getTimeInterval(int* timePeriod)
{
    bool isCorrect = scanf("%d", timePeriod);
    while (isNotNegative(*timePeriod, isCorrect) == false)
    {
        cleanStdin();
        printf("Enter the correct time interval: ");
        isCorrect = scanf("%d", timePeriod);
    }
    cleanStdin();
}


void getNumberOfUserActions(int* numberOfUserActions)
{
    bool isCorrect = scanf("%d", numberOfUserActions);
    while (isNaturalNumber(*numberOfUserActions, isCorrect) == false)
    {
        cleanStdin();
        printf("Enter the correct number of user actions: ");
        isCorrect = scanf("%d", numberOfUserActions);
    }
    cleanStdin();
}

void getAction(int* action)
{
    bool isCorrect = scanf("%d", action);
    while (isNotNegative(*action, isCorrect) == false)
    {
        cleanStdin();
        printf("Enter the correct action: ");
        isCorrect = scanf("%d", action);
    }
    cleanStdin();
}

int main() 
{
    int numberOfUsers = 0;
    int numberOfActions = 0;
    int timeInterval = 0;
    printf("Enter the number of users: ");
    getNumberOfUsers(&numberOfUsers);
    printf("Enter the required number of actions: ");
    getNumberOfActions(&numberOfActions);
    printf("Enter the time interval: ");
    getTimeInterval(&timeInterval);

    int answer = 0;
    for (int i = 0; i < numberOfUsers; i++)
    {
        int numberOfUserAction = 0;
        printf("Enter the number of actions the user %d performed: ", i + 1);
        getNumberOfUserActions(&numberOfUserAction);

        int action = 0;
        int count = 0;
        printf("Enter how many minutes ago each action took place:\n");
        for (int j = 0; j < numberOfUserAction; j++)
        {
            getAction(&action);
            if (action <= timeInterval)
            {
                count++;
            }
        }

        if (count == numberOfActions)
        {
            answer++;
        }
    }

    printf("Total performed %d action(-s) in the last %d minute(-s): %d user(-s)",
           numberOfActions, timeInterval, answer);
    return 0;
}
