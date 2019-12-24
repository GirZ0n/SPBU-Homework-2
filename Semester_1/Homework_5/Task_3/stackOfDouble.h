#pragma once

#include <stdbool.h>

struct StackOfDouble;
typedef struct StackOfDouble StackOfDouble;

StackOfDouble* createStackOfDouble();
void deleteStackOfDouble(StackOfDouble* stack);
bool stackOfDoubleIsEmpty(StackOfDouble* stack);
bool pushDouble(double value, StackOfDouble* stack);
double popDouble(StackOfDouble* stack);
double stackOfDoubleTop(StackOfDouble* stack);