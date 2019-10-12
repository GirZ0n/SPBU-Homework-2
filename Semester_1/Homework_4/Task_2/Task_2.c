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

void databaseInit(Pair* database, int* size, int* capacity)
{
    FILE *input = NULL;
    input = fopen("Telephone_directory.txt", "r");
    if (input != NULL)
    {
        char* inputString = malloc(sizeof(char) * maxSize);
        char* name = malloc(sizeof(char) * maxSize);
        char* phone = malloc(sizeof(char) * maxSize);
        while (feof(input) == false)
        {
            if (size == capacity)
            {
                *capacity *= 2;
                database = realloc(database, *capacity);
            }

            fgets(inputString, maxSize, input);
            sscanf(inputString, "%s %[^\n]", phone, name);
            createPair(&database[*size], name, phone);
            (*size)++;
        }

        free(inputString);
        free(name);
        free(phone);
        fclose(input);
    }
}

int main()
{
    int capacity = 2;
    int size = 0;
    Pair* database = malloc(sizeof(Pair) * capacity);
    databaseInit(database, &size, &capacity);

    /*
    for (int i = 0; i < size; i++)
    {
        printf("%s - %s\n", database[i].name, database[i].phone);
    }
    */
    return 0;
}