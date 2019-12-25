#include <stdio.h>
#include "list.h"

int main()
{
    List* list = createList();
    printf("Enter the number of elements:\n");
    int numberOfElements = 0;
    scanf("%d", &numberOfElements);
    if (numberOfElements < 0)
    {
        printf("Error. Enter the correct number (> 0).");
        return 0;
    }

    printf("Enter the array:\n");
    int input = 0;
    for (int i = 0; i < numberOfElements; i++)
    {
        scanf("%d", &input);
        pushBack(input, list);
    }

    printf("Unsotrted list:\n");
    printList(list);
    printf("Sorted list:\n");
    sortList(list);
    printList(list);
    deleteList(list);
}