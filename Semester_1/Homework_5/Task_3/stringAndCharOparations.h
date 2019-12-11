#pragma once

bool isOpenBracket(char inputChar);
bool isCloseBracket(char inputChar);
bool isLessPriority(char operatorA, char operatorB);
bool isDigit(char inputChar);
bool isUnaryNegative(char* string, int indexOfCheck);
bool isOperator(char* string, int indexOfCheck);
double getNumberAsDouble(char* string, int* indexOfCurrentPosition);
char* getNumberAsString(char* string, int* indexOfStart);
void writeNumberToString(char* source, int* indexOfStart, char* destination, int* sizeOfDestination);
