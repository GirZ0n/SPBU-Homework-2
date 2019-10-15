#ifndef LIST_H
#define LIST_H

struct List;
struct ListElement;
typedef struct List List;
typedef struct ListElement ListElement;

List* createList();
void pushBack(int value, List* list);
void nextElement(List* list);
void pop(List* list);
void printList(int size, List* list);

#endif
