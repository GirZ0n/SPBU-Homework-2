#include <stdio.h>

int main() 
{
    int numberOfUsers = 0;
    int numberOfActions = 0;
    int timePeriod = 0;
    printf("Enter the number of users, the required number of actions and the time interval: ");
    scanf("%d %d %d", &numberOfUsers, &numberOfActions, &timePeriod);

    int answer = 0;
    for (int i = 0; i < numberOfUsers; i++)
    {
        int numberOfUserAction = 0;
        printf("Enter the number of actions the user performed: ");
        scanf("%d", &numberOfUserAction);

        int action = 0;
        int count = 0;
        printf("Enter how many minutes ago each action took place: ");
        for (int j = 0; j < numberOfUserAction; j++)
        {
            scanf("%d", &action);
            if (action <= timePeriod)
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
            numberOfActions, timePeriod, answer);
    return 0;
}
