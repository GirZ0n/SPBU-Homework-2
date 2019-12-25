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
    while (!checkNumberOfStudents(*numberOfUsers, numberOfVariablesRead))
    {
        cleanStdin();
        printf("Enter the correct number of students:\n");
        numberOfVariablesRead = scanf("%d", numberOfUsers);
    }
    cleanStdin();
}

bool checkInput(int studentA, int studentB, int numberOfVariablesRead)
{
    return numberOfVariablesRead == 2 && studentA >= 1 && (studentB >= 1 || studentB == -1);
}

bool checkStudentNumber(int studentA, int studentB, int numberOfStudents)
{
    return studentA <= numberOfStudents && studentB <= numberOfStudents;
}

bool checkFirstThreeStudents(int studentA, int studentB)
{
    return studentA > 3 || studentA == studentB;
}

bool checkOtherStudents(int studentA, int studentB)
{
    return studentA <= 3 || studentA != studentB;
}

bool checkStudents(int studentA, int studentB, int numberOfVariablesRead, int numberOfStudents)
{
    return checkInput(studentA, studentB, numberOfVariablesRead) &&
           checkStudentNumber(studentA, studentB, numberOfStudents) &&
           checkFirstThreeStudents(studentA, studentB) &&
           checkOtherStudents(studentA, studentB);
}

void getStudents(int* studentA, int* studentB, int numberOfStudents)
{
    int numberOfVariablesRead = scanf("%d %d", studentA, studentB);
    while (!checkStudents(*studentA, *studentB, numberOfVariablesRead, numberOfStudents))
    {
        cleanStdin();
        printf("Enter the correct pair of students:\n");
        numberOfVariablesRead = scanf("%d %d", studentA, studentB);
    }
    cleanStdin();
}

int* helpedCheatInit(int numberOfStudents)
{
    int* helpedCheat = malloc(sizeof(int) * (numberOfStudents + 1));
    for (int i = 0; i < numberOfStudents + 1; i++)
    {
        helpedCheat[i] = -1; // -1 means the student did not try to write off.
    }
    // We believe that students 1, 2, 3 wrote off themselves.
    helpedCheat[1] = 1;
    helpedCheat[2] = 2;
    helpedCheat[3] = 3;
    return helpedCheat;
}

bool cycleCheck(int numberOfStudents, const int* helpedCheat)
{
    for (int i = 0; i < numberOfStudents; i++)
    {
        if (helpedCheat[i] != 1 && helpedCheat[i] != 2 && helpedCheat[i] != 3 && helpedCheat[i] != -1)
        {
            return false;
        }
    }

    return true;
}

void printAnswer(int numberOfStudents, const int* helpedCheat)
{
    if (!cycleCheck(numberOfStudents, helpedCheat))
    {
        printf("A loop was found in the graph. Make sure the data entered is correct.");
        return;
    }

    printf("Answer:\n");
    for (int i = 1; i < numberOfStudents + 1; i++)
    {
        printf("%d - %d\n", i, helpedCheat[i]);
    }
}

int main()
{
    printf("Enter the number of student (number >= 3):\n");
    int numberOfStudents = 0;
    getNumberOfStudents(&numberOfStudents);

    // helpedCheat[i] = the number of the student whose student "i" wrote off.
    int* helpedCheat = helpedCheatInit(numberOfStudents);

    printf("Enter student number (number > 0) and the number of student, "
           "who helped cheat (number > 0 || = -1):\n");
    for (int i = 0; i < numberOfStudents; i++)
    {
        int studentA = 0;
        int studentB = 0;
        getStudents(&studentA, &studentB, numberOfStudents);

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

        for (int j = 1; j <= numberOfStudents; j++)
        {
            if (helpedCheat[j] == studentA)
            {
                helpedCheat[j] = helpedCheat[studentA];
            }
        }
    }

    printAnswer(numberOfStudents, helpedCheat);
    free(helpedCheat);
    return 0;
}