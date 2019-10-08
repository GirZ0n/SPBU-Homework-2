#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {

    printf("Enter the size of Vasya's notes set: ");
    int sizeOfVasyaNotesSet = 0;
    scanf("%d", &sizeOfVasyaNotesSet);
    printf("Enter Vasya's notes set: ");
    int *vasyaNotes = malloc(sizeof(int) * sizeOfVasyaNotesSet);
    for (int i = 0; i < sizeOfVasyaNotesSet; i++)
    {
        int input = 0;
        scanf("%d", &input);
        vasyaNotes[i] = input;
    }


    printf("Enter the size of Petya's notes set: ");
    int sizeOfPetyaNotesSet = 0;
    scanf("%d", &sizeOfPetyaNotesSet);
    printf("Enter Petya's notes set: ");
    int *petyaNotes = malloc(sizeof(int) * sizeOfPetyaNotesSet);
    for (int i = 0; i < sizeOfPetyaNotesSet; i++)
    {
        int input = 0;
        scanf("%d", &input);
        petyaNotes[i] = input;
    }

    int *result = malloc(sizeof(int) * (sizeOfPetyaNotesSet + sizeOfVasyaNotesSet));
    int i = 0;
    int j = 0;
    while(true)
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

    for (int i = 0; i < sizeOfPetyaNotesSet + sizeOfVasyaNotesSet; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}