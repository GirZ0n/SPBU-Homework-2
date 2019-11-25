#include <stdlib.h>
#include <string.h>
#include "ADTstring.h"

struct String
{
    char* text;
    int length;
    int capacity;
};

typedef struct String String;

String* createString(int size)
{
    String* newString = malloc(sizeof(String));
    newString->text = calloc(sizeof(char), size);
    newString->length = 0;
    newString->capacity = size;
    return newString;
}

void resizeString(String* string, int newSize)
{
    if (string == NULL)
    {
        return;
    }

    string->text = realloc(string->text, newSize);
    string->capacity = newSize;
}

void deleteString(String* string)
{
    if (string == NULL)
    {
        return;
    }

    free(string->text);
    free(string);
}

int getStringLength(String *string)
{
   if (string == NULL)
   {
       return 0;
   }

   return string->length;
}

int getStringCapacity(String* string)
{
    if (string == NULL)
    {
        return 0;
    }

    return string->capacity;
}

char* convertStringToCharPointer(String* string)
{
    if (string == NULL)
    {
        return NULL;
    }

    return string->text;
}

String* convertStringToStructString(char* string)
{
    if (string == NULL)
    {
        return 0;
    }

    String* newString = createString(strlen(string));
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        newString->text[i] = string[i];
    }
    newString->length = strlen(string);

    return newString;
}

bool isStringEmpty(String* string)
{
    return getStringLength(string) == 0;
}

bool areStringsEqual(String* stringA, String* stringB)
{
    if (stringA == NULL || stringB == NULL)
    {
        return false;
    }

    if (getStringLength(stringA) != getStringLength(stringB))
    {
        return false;
    }

    int length = getStringLength(stringA);
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
    if (string == NULL)
    {
        return NULL;
    }

    String* newString = createString(getStringCapacity(string));
    newString->length = getStringLength(string);

    int length = newString->length;
    for (int i = 0; i < length; i++)
    {
        newString->text[i] = string->text[i];
    }

    return newString;
}

void concatenateStrings(String* destination, String* source)
{
    if (destination == NULL || source == NULL)
    {
        return;
    }

    resizeString(destination, getStringCapacity(destination) + getStringCapacity(source));
    int currentLength = getStringLength(destination);
    int newLength = getStringLength(destination) + getStringLength(source);
    for (int i = currentLength; i < newLength; i++)
    {
        destination->text[i] = source->text[i - currentLength];
    }
    destination->length = newLength;
}

String* getSubstring(String* string, int indexOfBegin, int indexOfEnd)
{
    if (string == NULL)
    {
        return NULL;
    }

    String* substring = createString(getStringCapacity(string));

    if (indexOfBegin < 0)
    {
        indexOfBegin = 0;
    }

    if (indexOfEnd > getStringLength(string) - 1)
    {
        indexOfEnd = getStringLength(string) - 1;
    }

    for (int i = 0; i < indexOfEnd - indexOfBegin + 1; i++)
    {
        substring->text[i] = string->text[indexOfBegin + i];
    }
    substring->length = indexOfEnd - indexOfBegin + 1;
    return substring;
}

void printString(String* string)
{
    if (string == NULL)
    {
        return;
    }

    printf("%s", string->text);
}

struct String* getStringFromConsole()
{
    String* newString = createString(2);
    char input = ' ';
    scanf("%c", &input);
    while (input != '\n')
    {
        if (getStringLength(newString) == getStringCapacity(newString))
        {
            newString->capacity *= 2;
            resizeString(newString, getStringCapacity(newString));
        }

        newString->text[getStringLength(newString)] = input;
        newString->length++;
        scanf("%c", &input);
    }

    return newString;
}

struct String* getStringFromFile(FILE* input)
{
    String* newString = createString(2);
    char inputChar = (char) fgetc(input);
    while (feof(input) == false && inputChar != '\n')
    {
        if (getStringLength(newString) == getStringCapacity(newString))
        {
            newString->capacity *= 2;
            resizeString(newString, getStringCapacity(newString));
        }

        newString->text[getStringLength(newString)] = inputChar;
        newString->length++;
        inputChar = (char) fgetc(input);
    }

    return newString;
}