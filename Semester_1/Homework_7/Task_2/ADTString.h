#ifndef ADTSTRING_H
#define ADTSTRING_H

#include <stdbool.h>

char* createString(int size);
void deleteString(char* string);
void resizeString(char* string, int newSize);
int getStringSize(const char* string);
bool isStringEmpty(char* string);
bool areStringsEqual(const char* stringA, const char* stringB);
char* cloneString(char* string);
char* combineStrings(char* stringA, char* stringB);
char* getSubstring(const char* string, int indexOfBegin, int indexOfEnd);
char* convertString(const char string[], int size);

#endif
