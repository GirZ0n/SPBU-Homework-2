#include <stdlib.h>
#include <string.h>
#include "ADTstring.h"

struct String
{
    char* text;
    int length;
};

String* createString(int size)
{
    String* newString = malloc(sizeof(String));
    newString->text = calloc(sizeof(char), size + 1);
    newString->length = 0;
    return newString;
}

void resizeString(String* string, int newSize)
{
    if (string == NULL || string->text == NULL)
    {
        return;
    }

    char* newText = calloc(newSize + 1, sizeof(char));
    strcpy(newText, string->text);
    free(string->text);
    string->text = newText;
    string->length = newSize;
}

void deleteString(String* string)
{
    if (string != NULL)
    {
        if (string->text != NULL)
        {
            free(string->text);
        }
        free(string);
    }
}

int getStringLength(String *string)
{
   if (string == NULL)
   {
       return 0;
   }

   return string->length;
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

    String* newString = createString((int) strlen(string));
    strcpy(newString->text, string);
    newString->length = (int) strlen(string);

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

    return strcmp(stringA->text, stringB->text) == 0;
}

String* cloneString(String* string)
{
    if (string == NULL)
    {
        return NULL;
    }

    String* newString = createString(getStringLength(string));
    newString->length = getStringLength(string);
    strcpy(newString->text, string->text);

    return newString;
}

void concatenateStrings(String* destination, String* source)
{
    if (destination == NULL || source == NULL)
    {
        return;
    }

    int newLength = getStringLength(destination) + getStringLength(source);
    resizeString(destination, newLength);
    strcat(destination->text, source->text);
}

String* getSubstring(String* string, int indexOfBegin, int indexOfEnd)
{
    if (string == NULL)
    {
        return NULL;
    }


    if (indexOfBegin < 0)
    {
        indexOfBegin = 0;
    }

    if (indexOfEnd > getStringLength(string) - 1)
    {
        indexOfEnd = getStringLength(string) - 1;
    }

    if (indexOfEnd < indexOfBegin)
    {
        indexOfEnd = indexOfBegin;
        indexOfBegin++;
    }

    String* substring = createString(indexOfEnd - indexOfBegin + 1);
    substring->length = indexOfEnd - indexOfBegin + 1;
    strncpy(substring->text, string->text + indexOfBegin, substring->length);
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
    int size = 0;
    int capacity = 2;
    String* newString = createString(capacity);
    char input = ' ';
    scanf("%c", &input);
    while (input != '\n')
    {
        if (size == capacity)
        {
            capacity *= 2;
            resizeString(newString, capacity);
        }

        newString->text[size] = input;
        size++;
        scanf("%c", &input);
    }

    resizeString(newString, size);
    return newString;
}

struct String* getStringFromFile(FILE* input)
{
    int size = 0;
    int capacity = 2;
    String* newString = createString(capacity);

    if (input == NULL)
    {
        return newString;
    }

    char inputChar = (char) fgetc(input);
    while (feof(input) == false && inputChar != '\n')
    {
        if (size == capacity)
        {
            capacity *= 2;
            resizeString(newString, capacity);
        }

        newString->text[size] = inputChar;
        size++;
        inputChar = (char) fgetc(input);
    }

    resizeString(newString, size);
    return newString;
}