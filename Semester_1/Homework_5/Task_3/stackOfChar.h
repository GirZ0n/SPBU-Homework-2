#pragma once

#include <stdbool.h>

struct StackOfChar;
typedef struct StackOfChar StackOfChar;

StackOfChar* createStackOfChar();
void deleteStackOfChar(StackOfChar* stack);
bool stackOfCharIsEmpty(StackOfChar* stack);
bool pushChar(char value, StackOfChar* stack);
char popChar(StackOfChar* stack);
char stackOfCharTop(StackOfChar* stack);