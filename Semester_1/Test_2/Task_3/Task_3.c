#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stdlib.h"

const int maxSize = 256;

struct Pair
{
    char* surname;
    int loyalty;
};

typedef struct Pair Pair;

void deleteArray(int size, Pair* array)
{
    for (int i = 0; i < size; i++)
    {
        free(array[i].surname);
    }
    free(array);
}

int byLoyalty(const void* left, const void* right)
{
    return ((Pair*)left)->loyalty - ((Pair*)right)->loyalty;
}

int bySurname(const void* left, const void* right)
{
    return strcmp(((Pair*)left)->surname, ((Pair*)right)->surname);
}

int main()
{
    int sizeOfList = 0;
    int capacityOfList = 2;
    Pair* list = malloc(capacityOfList * sizeof(Pair));
    FILE* input = fopen("input.txt", "r");
    char* inputString = calloc(maxSize, sizeof(char));
    char* surname = calloc(maxSize, sizeof(char));
    int loyalty = 0;

    while (!feof(input))
    {
        fgets(inputString, maxSize, input);

        if (sizeOfList == capacityOfList)
        {
            capacityOfList *= 2;
            list = realloc(list, capacityOfList * sizeof(Pair));
        }

        sscanf(inputString,"%s %d", surname, &loyalty);
        list[sizeOfList].surname = calloc(maxSize, sizeof(char));
        strcpy(list[sizeOfList].surname, surname);
        list[sizeOfList].loyalty = loyalty;
        sizeOfList++;
    }

    int numberOfDeadPeople = 0;
    printf("Enter the number of people you want to kill: ");
    scanf("%d", &numberOfDeadPeople);

    int numberOfPeopleInSiberia = 0;
    printf("Enter the number of people you want to send to Siberia: ");
    scanf("%d", &numberOfPeopleInSiberia);

    if (numberOfDeadPeople + numberOfPeopleInSiberia > sizeOfList)
    {
        printf("You want to kill too many people. Think about your behavior!");
        return 0;
    }

    printf("Expected list:\n");
    qsort(list, sizeOfList, sizeof(Pair), byLoyalty);
    for (int i = 0; i < numberOfDeadPeople; i++)
    {
        printf("%s - Kill\n", list[i].surname);
    }

    qsort(list + numberOfDeadPeople, sizeOfList - numberOfDeadPeople, sizeof(Pair), bySurname);
    for (int i = numberOfDeadPeople; i < numberOfDeadPeople + numberOfPeopleInSiberia; i++)
    {
        printf("%s - Siberia\n", list[i].surname);
    }

    for (int i = numberOfDeadPeople + numberOfPeopleInSiberia; i < sizeOfList; i++)
    {
        printf("%s - Do not touch\n", list[i].surname);
    }

    deleteArray(sizeOfList, list);
    free(inputString);
    free(surname);
    if (input != NULL)
    {
        fclose(input);
    }
    return 0;
}