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

bool checkNumberOfStudents(int inputNumber, int numberOfVariablesRead)
{
    return numberOfVariablesRead == 1 && inputNumber > 2;
}

void getNumberOfStudents(int* numberOfUsers)
{
    int numberOfVariablesRead = scanf("%d", numberOfUsers);
    while (checkNumberOfStudents(*numberOfUsers, numberOfVariablesRead) == false)
    {
        cleanStdin();
        printf("Enter the correct number of students:\n");
        numberOfVariablesRead = scanf("%d", numberOfUsers);
    }
    cleanStdin();
}

bool checkStudents(int studentA, int studentB, int numberOfVariablesRead, int numberOfStudents)
{
    if (numberOfVariablesRead != 2 || studentA < 1 || (studentB < 1 && studentB != -1))
    {
        return false;
    }

    if (studentA > numberOfStudents || studentB > numberOfStudents)
    {
        return false;
    }

    if (studentA > 3 && studentA == studentB)
    {
        return false;
    }

    if (studentA <= 3 && studentA != studentB)
    {
        return false;
    }

    return true;
}

void getStudents(int* studentA, int* studentB, int numberOfStudents)
{
    int numberOfVariablesRead = scanf("%d %d", studentA, studentB);
    while (checkStudents(*studentA, *studentB, numberOfVariablesRead, numberOfStudents) == false)
    {
        cleanStdin();
        printf("Enter the correct pair of students:\n");
        numberOfVariablesRead = scanf("%d %d", studentA, studentB);
    }
    cleanStdin();
}

int main()
{
    printf("Enter the number of student (number > 0):\n");
    int numberOfStudent = 0;
    getNumberOfStudents(&numberOfStudent);

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

    printf("Enter student number (number > 0) and the number of student, "
           "who helped cheat (number > 0 || = -1):\n");
    for (int i = 0; i < numberOfStudent; i++)
    {
        int studentA = 0;
        int studentB = 0;
        getStudents(&studentA, &studentB, numberOfStudent);

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

        for (int j = 1; j <= numberOfStudent; j++)
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