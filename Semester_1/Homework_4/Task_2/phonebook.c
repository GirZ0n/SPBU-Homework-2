#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

const int maxStringSize = 256;

struct Entry
{
    char name[256];
    char phoneNumber[256];
};

typedef struct Entry Entry;

void createEntry(struct Entry* entry, char* name, char* phoneNumber)
{
    strcpy(entry->name, name);
    strcpy(entry->phoneNumber, phoneNumber);
}

Entry* createPhoneBook(int capacity)
{
    Entry* database = malloc(sizeof(Entry) * capacity);
    return database;
}

int phoneBookInit(struct Entry* phoneBook, int* phoneBookSize, int* phoneBookCapacity, FILE* input)
{
    int numberOfEntries = 0;
    if (input != NULL)
    {
        char *inputString = malloc(sizeof(char) * maxStringSize);
        char *name = malloc(sizeof(char) * maxStringSize);
        char *phoneNumber = malloc(sizeof(char) * maxStringSize);
        while (feof(input) == false)
        {
            if (*phoneBookSize == *phoneBookCapacity)
            {
                *phoneBookCapacity *= 2;
                phoneBook = realloc(phoneBook, *phoneBookCapacity);
            }

            fscanf(input, "%s %[^\n]", phoneNumber, name);
            createEntry(&phoneBook[*phoneBookSize], name, phoneNumber);
            (*phoneBookSize)++;
            numberOfEntries++;
        }

        free(inputString);
        free(name);
        free(phoneNumber);
    }

    return numberOfEntries;
}

void addEntry(struct Entry* phoneBook, int* phoneBookSize, int* phoneBookCapacity, char* name, char* phoneNumber)
{
    if (*phoneBookSize == *phoneBookCapacity)
    {
        *phoneBookCapacity *= 2;
        phoneBook = realloc(phoneBook, *phoneBookCapacity);
    }

    createEntry(&phoneBook[*phoneBookSize], name, phoneNumber);
    (*phoneBookSize)++;
}

bool getPhoneByName(struct Entry* phoneBook, int phoneBookSize, char* name, char* phoneNumber)
{
    for (int i = 0; i < phoneBookSize; i++)
    {
        if (!strcmp(phoneBook[i].name, name))
        {
            strcpy(phoneNumber, phoneBook[i].phoneNumber);
            return true;
        }
    }

    return false;
}

bool getNameByPhone(struct Entry* phoneBook, int phoneBookSize, char* name, char* phoneNumber)
{
    for (int i = 0; i < phoneBookSize; i++)
    {
        if (!strcmp(phoneBook[i].phoneNumber, phoneNumber))
        {
            strcpy(name, phoneBook[i].name);
            return true;
        }
    }

    return false;
}

void saveData(struct Entry* phoneBook, int phoneBookSize, int* numberOfEntries, FILE* output)
{
    for (int i = *numberOfEntries; i < phoneBookSize; i++)
    {
        fputs("\n", output);
        fputs(phoneBook[i].phoneNumber, output);
        fputs(" ", output);
        fputs(phoneBook[i].name, output);
    }

    *numberOfEntries = phoneBookSize;
}