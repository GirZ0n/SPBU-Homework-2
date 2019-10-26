#ifndef CHARSTACK_H
#define CHARSTACK_H

#include <stdbool.h>

struct CharStack;
struct CharStackElement;

struct CharStack* charStackCreate();
bool charStackIsEmpty(struct CharStack* stack);
bool charStackPush(char value, struct CharStack* stack);
char charStackPop(struct CharStack* stack);
char charStackTop(struct CharStack* stack);

#endif