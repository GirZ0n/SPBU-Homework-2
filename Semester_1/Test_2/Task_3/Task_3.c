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

void swap(struct Pair* left, struct Pair* right)
{
    struct Pair temp = *left;
    *left = *right;
    *right = temp;
}

void printArray(int size, struct Pair* array)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s %d\n", array[i].surname, array[i].loyalty);
    }
}

void sortByLoyalty(int size, struct Pair* array)
{
    for (int i = 0 ; i < size - 1; i++)
    {
        for (int j = 0 ; j < size - i - 1 ; j++)
        {
            if(array[j].loyalty > array[j + 1].loyalty)
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void sortBySurname(int size, struct Pair* array)
{
    for (int i = 0 ; i < size - 1; i++)
    {
        for (int j = 0 ; j < size - i - 1 ; j++)
        {
            if(array[j].surname < array[j + 1].surname)
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main()
{
    int sizeOfList = 0;
    int capacityOfList = 2;
    struct Pair* list = malloc(capacityOfList * sizeof(struct Pair));
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
            list = realloc(list, capacityOfList * sizeof(struct Pair));
        }

        sscanf(inputString,"%s %d", surname, &loyalty);
        list[sizeOfList].surname = calloc(maxSize, sizeof(char));
        strcpy(list[sizeOfList].surname, surname);
        list[sizeOfList].loyalty = loyalty;
        sizeOfList++;
    }

    int numberOfDeadPeople = 0;
    printf("Enter the number of people you want to shoot: ");
    scanf("%d", &numberOfDeadPeople);

    int numberOfPeopleInSiberia = 0;
    printf("Enter the number of people you want to send to Siberia: ");
    scanf("%d", &numberOfPeopleInSiberia);

    if (numberOfDeadPeople + numberOfPeopleInSiberia > sizeOfList)
    {
        printf("You want to kill too many people");
        return 0;
    }

    printf("Starred list:\n");
    sortByLoyalty(sizeOfList, list);
    for (int i = 0; i < numberOfDeadPeople; i++)
    {
        printf("%s - Kill\n", list[i].surname);
    }

    struct Pair* others = malloc((sizeOfList - numberOfDeadPeople) * sizeof(struct Pair));
    for (int i = 0; i < sizeOfList - numberOfDeadPeople; i++)
    {
        others[i] = list[numberOfDeadPeople + i];
    }

    sortBySurname(sizeOfList - numberOfDeadPeople, others);
    for (int i = 0; i < numberOfPeopleInSiberia; i++)
    {
        printf("%s - Siberia\n", others[i].surname);
    }

    for (int i = numberOfPeopleInSiberia; i < sizeOfList - numberOfDeadPeople; i++)
    {
        printf("%s - Do not touch\n", others[i].surname);
    }

    free(list);
    free(others);
    free(inputString);
    free(surname);
    if (input != NULL)
    {
        fclose(input);
    }
}