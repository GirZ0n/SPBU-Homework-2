#ifndef LIST_H
#define LIST_H

struct List;
struct ListElement;
typedef struct List List;
typedef struct ListElement ListElement;

List* createList();
ListElement* createListElement(int value);
void pushBack(int value, List* list);
void pop(ListElement* listElement ,List* list);
void print(int size, List* list);

#endif
