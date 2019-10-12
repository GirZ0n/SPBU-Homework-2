#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 256

struct Pair
{
    char name[maxSize];
    char phone[maxSize];
};

typedef struct Pair Pair;

void createPair(Pair* pair, char* name, char* phone)
{
    strcpy(pair->name, name);
    strcpy(pair->phone, phone);
}

void databaseInit(Pair* database, int* databaseSize, int* databaseCapacity)
{
    FILE *input = fopen("Telephone_directory.txt", "r");
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
        }

        free(inputString);
        free(name);
        free(phone);
        fclose(input);
    }
}

int max(int elementA, int elementB)
{
    if (elementA > elementB)
    {
        return elementA;
    }

    return elementB;
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

bool getNameByPhone(Pair* database, int databaseSize, char name[], char phone[])
{
    for (int i = 0; i < databaseSize; i++)
    {
        if (areEqual(database[i].phone, phone))
        {
            strcpy(name, database[i].name);
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

    databaseInit(database, &databaseSize, &databaseCapacity);

    printf("Select an action from the suggestions below.\n");
    printf("0 - Exit;\n");
    printf("1 - Add telephone directory entry;\n");
    printf("2 - Find phone by name;\n");
    printf("3 - Find name by phone;\n");
    printf("4 - Save current data to a file.\n\n");

    char name[maxSize];
    char phone[maxSize];
    int action = 0;
    while (true)
    {
        printf("Your action: ");
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
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                printf("Enter the phone: ");
                scanf("%s", phone);
                if (getNameByPhone(database, databaseSize, name, phone))
                {
                    printf("Result: %s - %s\n", name, phone);
                }
                else
                {
                    printf("The phone number is not in the telephone directory.\n");
                }

                break;
            }
            case 4:
            {
                break;
            }
            default:
            {
                printf("Enter the correct action.\n");
                break;
            }
        }
    }


    for (int i = 0; i < databaseSize; i++)
    {
        printf("%s - %s\n", database[i].name, database[i].phone);
    }

    return 0;
}