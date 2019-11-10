#include <stdlib.h>
#include "ADTString.h"

char* createString(int size)
{
    char* string = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size + 1; i++)
    {
        string[i] = '\0';
    }
    return string;
}

void resizeString(char* string, int newSize)
{
    string = realloc(string, newSize);
}

void deleteString(char* string)
{
    free(string);
}

int getStringSize(const char* string)
{
    int size = 0;
    while (string[size] != '\0')
    {
        size++;
    }
    return size;
}

bool isStringEmpty(char* string)
{
    return getStringSize(string) == 0;
}

bool areStringsEqual(const char* stringA, const char* stringB)
{
    int i = 0;
    while (stringA[i] == stringB[i] && stringA[i] != '\0' && stringB[i] != '\0')
    {
        i++;
    }

    if (stringA[i] == '\0' && stringB[i] == '\0')
    {
        return true;
    }

    return false;
}

char* cloneString(char* string)
{
    int stringSize = getStringSize(string);
    char* copyOfString = createString(stringSize);
    for (int i = 0; i < stringSize; i++)
    {
        copyOfString[i] = string[i];
    }
    return copyOfString;
}

char* combineStrings(char* stringA, char* stringB)
{
    int sizeOfStringA = getStringSize(stringA);
    int sizeOfStringB = getStringSize(stringB);

    char* newString = createString(sizeOfStringA + sizeOfStringB);
    for (int i = 0; i < sizeOfStringA; i++)
    {
        newString[i] = stringA[i];
    }

    for (int i = 0; i < sizeOfStringB; i++)
    {
        newString[i + sizeOfStringA] = stringB[i];
    }

    return newString;
}

char* getSubstring(const char* string, int indexOfBegin, int indexOfEnd)
{
    char* substring = createString(indexOfEnd - indexOfBegin + 1);
    for (int i = 0; i < indexOfEnd - indexOfBegin + 1; i++)
    {
        substring[i] = string[indexOfBegin + i];
    }
    return substring;
}

char* convertString(const char string[], int size)
{
    char* newString = createString(size);
    for (int i = 0; i < size; i++)
    {
        newString[i] = string[i];
    }
    return newString;
}