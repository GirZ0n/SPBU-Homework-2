#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 256

struct Pair
{
    char name[maxSize];
    char phoneNumber[maxSize];
};

typedef struct Pair Pair;

void createPair(Pair* pair, char* name, char* phoneNumber)
{
    strcpy(pair->name, name);
    strcpy(pair->phoneNumber, phoneNumber);
}

int databaseInit(Pair* database, int* databaseSize, int* databaseCapacity)
{
    FILE *input = fopen("Telephone_directory.txt", "r");
    int numberOfEntries = 0;
    if (input != NULL)
    {
        char *inputString = malloc(sizeof(char) * maxSize);
        char *name = malloc(sizeof(char) * maxSize);
        char *phone = malloc(sizeof(char) * maxSize);
        while (feof(input) == false)
        {
            if (databaseSize == databaseCapacity)
            {
                *databaseCapacity *= 2;
                database = realloc(database, *databaseCapacity);
            }

            fgets(inputString, maxSize, input);
            sscanf(inputString, "%s %[^\n]", phone, name);
            createPair(&database[*databaseSize], name, phone);
            (*databaseSize)++;
            numberOfEntries++;
        }

        free(inputString);
        free(name);
        free(phone);
        fclose(input);
    }

    return numberOfEntries;
}

int max(int elementA, int elementB)
{
    return elementA > elementB ? elementA : elementB;
}

bool areEqual(char stringA[], char stringB[])
{
    int stringLength = max(strlen(stringA), strlen(stringB));
    for (int i = 0; i < stringLength; i++)
    {
        if (stringA[i] != stringB[i])
        {
            return false;
        }
    }

    return true;
}

bool getNameByPhone(Pair* database, int databaseSize, char name[], char phoneNumber[])
{
    for (int i = 0; i < databaseSize; i++)
    {
        if (areEqual(database[i].phoneNumber, phoneNumber))
        {
            strcpy(name, database[i].name);
            return true;
        }
    }

    return false;
}

bool getPhoneByName(Pair* database, int databaseSize, char name[], char phoneNumber[])
{
    for (int i = 0; i < databaseSize; i++)
    {
        if (areEqual(database[i].name, name))
        {
            strcpy(phoneNumber, database[i].phoneNumber);
            return true;
        }
    }

    return false;
}

int main()
{
    int databaseCapacity = 2;
    int databaseSize = 0;
    Pair* database = malloc(sizeof(Pair) * databaseCapacity);

    int numberOfEntries = databaseInit(database, &databaseSize, &databaseCapacity);

    printf("Select an action from the suggestions below.\n");
    printf("0 - Exit;\n");
    printf("1 - Add telephone directory entry;\n");
    printf("2 - Find phone number by name;\n");
    printf("3 - Find name by phone number;\n");
    printf("4 - Save current data to a file.\n\n");
    printf("Attention! The phone number must be entered in the international format: +12345678...\n");

    char name[maxSize] = "";
    char firstName[maxSize] = "";
    char secondName[maxSize] = "";
    char phoneNumber[maxSize] = "";
    int action = 0;
    while (true)
    {
        printf("\nYour action: ");
        scanf("%d", &action);
        switch (action)
        {
            case 0:
            {
                printf("Have a nice day! Bye :)");
                return 0;
            }
            case 1:
            {
                printf("Enter first and last name: ");
                scanf("%s %s", firstName, secondName);
                name[0] = '\0';
                strcat(name, firstName);
                strcat(name, " ");
                strcat(name, secondName);
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);

                if (databaseSize == databaseCapacity)
                {
                    databaseCapacity *= 2;
                    database = realloc(database, databaseCapacity);
                }

                createPair(&database[databaseSize], name, phoneNumber);
                databaseSize++;

                break;
            }
            case 2:
            {
                printf("Enter first and last name: ");
                scanf("%s %s", firstName, secondName);
                name[0] = '\0';
                strcat(name, firstName);
                strcat(name, " ");
                strcat(name, secondName);
                if (getPhoneByName(database, databaseSize, name, phoneNumber))
                {
                    printf("Result: %s - %s\n", name, phoneNumber);
                }
                else
                {
                    printf("The name is not in the telephone directory.\n");
                }

                break;
            }
            case 3:
            {
                printf("Enter the phone number: ");
                scanf("%s", phoneNumber);
                if (getNameByPhone(database, databaseSize, name, phoneNumber))
                {
                    printf("Result: %s - %s\n", name, phoneNumber);
                }
                else
                {
                    printf("The phone number is not in the telephone directory.\n");
                }

                break;
            }
            case 4:
            {
                FILE *output = fopen("Telephone_directory.txt", "a");
                for (int i = numberOfEntries; i < databaseSize; i++)
                {
                    fputs("\n", output);
                    fputs(database[i].phoneNumber, output);
                    fputs(" ", output);
                    fputs(database[i].name, output);
                }
                numberOfEntries = databaseSize;
                fclose(output);

                break;
            }
            default:
            {
                printf("Enter the correct action.\n");
                break;
            }
        }
    }
}