#include <stdio.h>

int main()
{
    int numberOfTickets[28] = {0};
    for (int i = 0; i < 1000; i++)
    {
        int sumOfDigits = (i / 100) + (i % 100 / 10) + (i % 10);
        numberOfTickets[sumOfDigits]++;
    }

    int countOfLuckyTickets = 0;
    for (int i = 0; i < 28; i++)
    {
        countOfLuckyTickets += (numberOfTickets[i] * numberOfTickets[i]);
    }

    printf("Count of lucky tickets: %d", countOfLuckyTickets);
    return 0;
}