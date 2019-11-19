#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const int maxSize = 256;
const int sizeOfDate = 10;

bool isDigit(char input)
{
    return input - '0' >= 0 && input - '0' <= 9;
}

bool isDate(char* string)
{
    if (strlen(string) == sizeOfDate)
    {
        for (int i = 0; i < sizeOfDate; i++)
        {
            if (!isDigit(string[i]) && string[i] != '.')
            {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool isLessDate(char* inputDate, char* minDate)
{
    char dot = ' ';
    int dayOfInputDate = 0;
    int monthOfInputDate = 0;
    int yearOfInputDate = 0;
    sscanf(inputDate, "%d%c%d%c%d", &dayOfInputDate, &dot, &monthOfInputDate, &dot, &yearOfInputDate);
    int dayOfMinDate = 0;
    int monthOfMinDate = 0;
    int yearOfMinDate = 0;
    sscanf(minDate, "%d%c%d%c%d", &dayOfMinDate, &dot, &monthOfMinDate, &dot, &yearOfMinDate);

    if (yearOfInputDate < yearOfMinDate)
    {
        return true;
    }
    else if (yearOfInputDate > yearOfMinDate)
    {
        return false;
    }
    else if (monthOfInputDate < monthOfMinDate)
    {
        return true;
    }
    else if (monthOfInputDate > monthOfMinDate)
    {
        return false;
    }
    else if (dayOfInputDate < dayOfMinDate)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    FILE *input = fopen("input.txt", "r");
    char* inputString = calloc(maxSize, sizeof(char));
    char* minDate = calloc(maxSize, sizeof(char));
    bool isFirstDate = true;
    while (feof(input) == false)
    {
        fscanf(input, "%s", inputString);
        if (isDate(inputString))
        {
            if (isFirstDate)
            {
                strcpy(minDate, inputString);
                isFirstDate = false;
            }
            else
            {
                if (isLessDate(inputString, minDate))
                {
                    strcpy(minDate, inputString);
                }
            }
        }
    }
    if (isFirstDate == true)
    {
        printf("Dates not found");
    }
    else
    {
        printf("Lowest date: %s", minDate);
    }

    fclose(input);
    return 0;
}