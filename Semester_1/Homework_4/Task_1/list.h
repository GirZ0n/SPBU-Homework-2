#ifndef LIST_H
#define LIST_H

struct List;
struct ListElement;

struct List* createList();
void pushBack(int value, struct List* list);
void nextElement(struct List* list);
void pop(struct List* list);
void printList(int size, struct List* list);

#endif
