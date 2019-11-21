#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    int numberOfWarriors = 0;
    printf("Enter the number of warriors: ");
    scanf("%d", &numberOfWarriors);
    int needToKillEvery = 0;
    printf("Need to kill every: ");
    scanf("%d", &needToKillEvery);

    struct List* list = createList();
    for (int i = 1; i <= numberOfWarriors; i++)
    {
        pushBack(i, list);
    }

    for (int i = 0; i < numberOfWarriors - 1; i++)
    {
        for (int j = 0; j < needToKillEvery - 1; j++)
        {
            nextElement(list);
        }
        pop(list);
    }

    printf("Answer: ");
    printList(1, list);

    free(list);
    return 0;
}