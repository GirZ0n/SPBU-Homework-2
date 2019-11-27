#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the number of student: ");
    int numberOfStudent = 0;
    scanf("%d", &numberOfStudent);

    // helpedCheat[i] = the number of the student whose student "i" wrote off.
    int* helpedCheat = malloc(sizeof(int) * (numberOfStudent + 1));
    for (int i = 0; i < numberOfStudent + 1; i++)
    {
        helpedCheat[i] = -1; // -1 means the student did not try to write off.
    }
    // We believe that students 1, 2, 3 wrote off themselves.
    helpedCheat[1] = 1;
    helpedCheat[2] = 2;
    helpedCheat[3] = 3;

    printf("Enter student number and the number of student, who helped cheat:\n");
    for (int i = 0; i < numberOfStudent; i++)
    {
        int studentA = 0;
        int studentB = 0;
        scanf("%d %d", &studentA, &studentB);

        if (studentB == -1)
        {
            continue;
        }

        if (helpedCheat[studentB] == -1)
        {
            helpedCheat[studentA] = studentB;
        }
        else
        {
            helpedCheat[studentA] = helpedCheat[studentB];
        }

        for (int j = 1; j <= numberOfStudent + 1; j++)
        {
            if (helpedCheat[j] == studentA)
            {
                helpedCheat[j] = helpedCheat[studentA];
            }
        }
    }

    printf("Answer:\n");
    for (int i = 1; i < numberOfStudent + 1; i++)
    {
        printf("%d - %d\n", i, helpedCheat[i]);
    }
    free(helpedCheat);
    return 0;
}