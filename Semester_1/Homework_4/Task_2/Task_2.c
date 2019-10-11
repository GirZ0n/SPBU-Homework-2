#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const int maxSize = 256;

struct Pair
{
    char name[256];
    char phone[256];
};

typedef struct Pair Pair;

Pair createPair(char* name, char* phone)
{
    Pair currentPair;
    strcpy(currentPair.name, name);
    strcpy(currentPair.phone, phone);
    return currentPair;
}

int main()
{
    int capacity = 2;
    int size = 0;
    Pair* database = malloc(sizeof(Pair) * capacity);

    FILE *input = fopen("Telephone_directory.txt", "r");
    if (input != NULL)
    {
        char* inputString = malloc(sizeof(char) * maxSize);
        char* name = malloc(sizeof(char) * maxSize);
        char* phone = malloc(sizeof(char) * maxSize);
        while (feof(input) == false)
        {
            if (size == capacity)
            {
                capacity *= 2;
                database = realloc(database, capacity);
            }

            fgets(inputString, maxSize, input);

            sscanf(inputString, "%s - %s", name, phone);

            database[size] = createPair(name, phone);
            size++;
        }

        free(inputString);
        free(name);
        free(phone);
    }

    return 0;
}