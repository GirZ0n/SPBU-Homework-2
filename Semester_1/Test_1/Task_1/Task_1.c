#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* getArray(int size)
{
    int* array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }

    int input = 0;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &input);
        array[i] = input;
    }

    return array;
}

int main() {

    printf("Enter the size of Vasya's notes set: ");
    int sizeOfVasyaNotesSet = 0;
    scanf("%d", &sizeOfVasyaNotesSet);
    printf("Enter Vasya's notes set: ");
    int *vasyaNotes = getArray(sizeOfVasyaNotesSet);

    printf("Enter the size of Petya's notes set: ");
    int sizeOfPetyaNotesSet = 0;
    scanf("%d", &sizeOfPetyaNotesSet);
    printf("Enter Petya's notes set: ");
    int *petyaNotes = getArray(sizeOfPetyaNotesSet);

    int *result = malloc(sizeof(int) * (sizeOfPetyaNotesSet + sizeOfVasyaNotesSet));
    int i = 0;
    int j = 0;
    while (true)
    {
        while (i < sizeOfPetyaNotesSet && petyaNotes[i] >= vasyaNotes[j])
        {
            result[i + j] = petyaNotes[i];
            i++;
        }

        while (j < sizeOfVasyaNotesSet && vasyaNotes[j] >= petyaNotes[i])
        {
            result[i + j] = vasyaNotes[j];
            j++;
        }

        if (i == sizeOfPetyaNotesSet && j == sizeOfVasyaNotesSet)
        {
            break;
        }
    }

    printf("Desired array: ");
    for (int i = 0; i < sizeOfPetyaNotesSet + sizeOfVasyaNotesSet; i++)
    {
        printf("%d ", result[i]);
    }

    free(result);
    free(petyaNotes);
    free(vasyaNotes);
    return 0;
}