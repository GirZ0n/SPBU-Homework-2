#pragma once

#include <stdbool.h>
#include <stdio.h>

struct String;
typedef struct String String;

String* createString(int size);
void deleteString(String* string);
int getStringLength(String* string);
char* convertStringToCharPointer(String* string);
String* convertStringToStructString(char* string);
bool isStringEmpty(String* string);
bool areStringsEqual(String* stringA, String* stringB);
String* cloneString(String* string);
void concatenateStrings(String* stringA, String* stringB);
String* getSubstring(String* string, int indexOfBegin, int indexOfEnd);
void printString(String* string);
String* getStringFromConsole();
String* getStringFromFile(FILE* input);