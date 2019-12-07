#pragma once

#include <stdbool.h>

typedef struct StackOfChar StackOfChar;
typedef struct StackOfDouble StackOfDouble;

// Stack of char
struct StackOfChar;

StackOfChar* createStackOfChar();
void deleteStackOfChar(StackOfChar* stack);
bool stackOfCharIsEmpty(StackOfChar* stack);
bool pushChar(char value, StackOfChar* stack);
char popChar(StackOfChar* stack);
char stackOfCharTop(StackOfChar* stack);



// Stack of double
struct StackOfDouble;

StackOfDouble* createStackOfDouble();
void deleteStackOfDouble(StackOfDouble* stack);
bool stackOfDoubleIsEmpty(StackOfDouble* stack);
bool pushDouble(double value, StackOfDouble* stack);
double popDouble(StackOfDouble* stack);
double stackOfDoubleTop(StackOfDouble* stack);