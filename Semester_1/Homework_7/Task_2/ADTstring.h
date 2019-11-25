#ifndef ADTSTRING_H
#define ADTSTRING_H

#include <stdbool.h>
#include <stdio.h>

struct String;

struct String* createString(int size);
void resizeString(struct String*, int newSize);
void deleteString(struct String* string);
int getStringLength(struct String* string);
int getStringCapacity(struct String* string);
char* convertStringToCharPointer(struct String* string);
struct String* convertStringToStructString(char* string);
bool isStringEmpty(struct String* string);
bool areStringsEqual(struct String* stringA, struct String* stringB);
struct String* cloneString(struct String* string);
void concatenateStrings(struct String* stringA, struct String* stringB);
struct String* getSubstring(struct String* string, int indexOfBegin, int indexOfEnd);
void printString(struct String* string);
struct String* getStringFromConsole();
struct String* getStringFromFile(FILE* input);

#endif