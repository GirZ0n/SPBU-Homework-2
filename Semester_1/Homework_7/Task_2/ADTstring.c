#include <stdlib.h>
#include <string.h>
#include "ADTstring.h"

struct String
{
    char* text;
    int size;
    int capacity;
};

typedef struct String String;

int getStringSize(String* string)
{
    return string->size;
}

int getStringCapacity(String* string)
{
    return string->capacity;
}

String* createString(int size)
{
    String* newString = malloc(sizeof(String));
    newString->text = calloc(sizeof(char), size);
    newString->size = 0;
    newString->capacity = size;
    return newString;
}

char* convertStringToCharPointer(String* string)
{
    return string->text;
}

String* convertStringToStructString(char* string)
{
    String* newString = createString(strlen(string));

    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        newString->text[i] = string[i];
    }
    newString->size = strlen(string);

    return newString;
}

void resizeString(String* string, int newSize)
{
    string->text = realloc(string->text, newSize);
    string->capacity = newSize;
}

void deleteString(String* string)
{
    free(string->text);
    free(string);
}

bool isStringEmpty(String* string)
{
    return getStringSize(string) == 0;
}

bool areStringsEqual(String* stringA, String* stringB)
{
    if (getStringSize(stringA) != getStringSize(stringB))
    {
        return false;
    }

    int length = getStringSize(stringA);
    for (int i = 0; i < length; i++)
    {
        if (stringA->text[i] != stringB->text[i])
        {
            return false;
        }
    }

    return true;
}

String* cloneString(String* string)
{
    String* newString = createString(getStringCapacity(string));
    newString->size = getStringSize(string);

    int length = newString->size;
    for (int i = 0; i < length; i++)
    {
        newString->text[i] = string->text[i];
    }

    return newString;
}

void concatenateStrings(String* destination, String* source)
{
    resizeString(destination, getStringCapacity(destination) + getStringCapacity(source));
    int currentLength = getStringSize(destination);
    int newLength = getStringSize(destination) + getStringSize(source);
    for (int i = currentLength; i < newLength; i++)
    {
        destination->text[i] = source->text[i - currentLength];
    }
    destination->size = newLength;
}

String* getSubstring(String* string, int indexOfBegin, int indexOfEnd)
{
    String* substring = createString(getStringCapacity(string));

    if (indexOfBegin < 0)
    {
        indexOfBegin = 0;
    }

    if (indexOfEnd > getStringSize(string) - 1)
    {
        indexOfEnd = getStringSize(string) - 1;
    }

    for (int i = 0; i < indexOfEnd - indexOfBegin + 1; i++)
    {
        substring->text[i] = string->text[indexOfBegin + i];
    }
    substring->size = indexOfEnd - indexOfBegin + 1;
    return substring;
}

void printString(String* string)
{
    printf("%s", string->text);
}

bool isSpecials(char input)
{
    return (input == ' ') || (input == '\n') || (input == '\t');
}

struct String* getStringFromConsole()
{
    String* newString = createString(2);
    char input = ' ';
    scanf("%c", &input);
    while (!isSpecials(input))
    {
        if (getStringSize(newString) == getStringCapacity(newString))
        {
            newString->capacity *= 2;
            resizeString(newString, getStringCapacity(newString));
        }

        newString->text[getStringSize(newString)] = input;
        newString->size++;
        scanf("%c", &input);
    }

    return newString;
}

struct String* getStringFromFile(FILE* input)
{
    String* newString = createString(2);
    char inputChar = fgetc(input);
    while (!isSpecials(inputChar) && feof(input) == false)
    {
        if (getStringSize(newString) == getStringCapacity(newString))
        {
            newString->capacity *= 2;
            resizeString(newString, getStringCapacity(newString));
        }

        newString->text[getStringSize(newString)] = inputChar;
        newString->size++;
        inputChar = fgetc(input);
    }

    return newString;
}