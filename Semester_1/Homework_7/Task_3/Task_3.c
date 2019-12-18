#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "hashtable.h"

void formatWord(char* word)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == '.' || word[i] == ',' || word[i] == '!' || word[i] == '?')
        {
            word[i] = '\0';
            return;
        }
        else
        {
            word[i] = (char) tolower(word[i]);
        }
    }
}

char* getWordFromFile(FILE* input)
{
    int size = 0;
    int capacity = 2;
    char* word = calloc(capacity, sizeof(char));
    char inputChar = (char) fgetc(input);
    while (inputChar != EOF && inputChar != ' ' && inputChar != '\n')
    {
        if (size + 1 == capacity)
        {
            capacity *= 2;
            word = realloc(word, sizeof(char) * capacity);
        }

        word[size] = inputChar;
        size++;
        inputChar = (char) fgetc(input);
    }
    word[size] = '\0';
    return word;
}

int main()
{
    FILE* text = fopen("input.txt", "r");
    if (text == NULL)
    {
        printf("Can not open the file.");
        return 0;
    }

    HashTable* hashtable = createHashTable(50);
    int entries = 0;

    while (feof(text) == false)
    {
        char* word = getWordFromFile(text);
        formatWord(word);
        if (word[0] != '\0')
        {
            String* keyWord = convertStringToStructString(word);
            if (!isInHashTable(keyWord, hashtable))
            {
                pushBucketToHashTable(keyWord, 1, hashtable);
            }
            else
            {
                entries = getValueFromHashTable(keyWord, hashtable);
                changeBucketInHashTable(keyWord, ++entries, hashtable);
            }
            deleteString(keyWord);
        }
        free(word);
    }

    printHashTable(hashtable);
    printHashTableInfo(hashtable);

    deleteHashTable(hashtable);
    fclose(text);
    return 0;
}