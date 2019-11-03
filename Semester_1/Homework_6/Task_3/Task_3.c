#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "set.h"

int main()
{
    struct Set* set = createSet();
    printf("Select an action from the suggestions below.\n");
    printf("0 - Exit;\n");
    printf("1 - Add value to set;\n");
    printf("2 - Remove value from set;\n");
    printf("3 - Check if a value belongs to a set;\n");
    printf("4 - Print set in ascending order;\n");
    printf("5 - Print set in descending order;\n");
    printf("6 - Print set.\n\n");

    int value = 0;
    int action = 0;
    while (true)
    {
        printf("Your action: ");
        scanf("%d", &action);
        switch (action)
        {
            case 0:
            {
                printf("Have a nice day! Bye :)");
                return 0;
            }
            case 1:
            {
                printf("Enter value: ");
                scanf("%d", &value);
                addElement(value, set);
                printf("\n");
                break;
            }
            case 2:
            {
                printf("Enter value: ");
                scanf("%d", &value);
                removeElement(value, set);
                printf("\n");
                break;
            }
            case 3:
            {
                printf("Enter value: ");
                scanf("%d", &value);
                if (isContained(value, set))
                {
                    printf("Value is in the set.\n\n");
                }
                else
                {
                    printf("Value isn't in the set.\n\n");
                }
                break;
            }
            case 4:
            {
                printInAscendingOrder(set);
                printf("\n\n");
                break;
            }
            case 5:
            {
                printInDescendingOrder(set);
                printf("\n\n");
                break;
            }
            case 6:
            {
                printSet(set);
                printf("\n\n");
                break;
            }
            default:
            {
                printf("Enter the correct action.\n\n");

                break;
            }
        }
    }
}