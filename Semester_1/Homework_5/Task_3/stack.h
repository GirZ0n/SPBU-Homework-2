#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Stack of char
struct StackOfChar;
struct StackOfCharElement;

struct StackOfChar* createStackOfChar();
bool stackOfCharIsEmpty(struct StackOfChar* stack);
bool pushChar(char value, struct StackOfChar* stack);
char popChar(struct StackOfChar* stack);
char stackOfCharTop(struct StackOfChar* stack);



// Stack of double
struct StackOfDouble;
struct StackOfDoubleElement;

struct StackOfDouble* createStackOfDouble();
bool stackOfDoubleIsEmpty(struct StackOfDouble* stack);
bool pushDouble(double value, struct StackOfDouble* stack);
double popDouble(struct StackOfDouble* stack);
double stackOfDoubleTop(struct StackOfDouble* stack);

#endif