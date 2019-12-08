#include <stdio.h>
#include <stdlib.h>
#include "AVLset.h"

void cleanStdin()
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != EOF && c != '\n');
}

void getNumber(int* number)
{
    int numberOfVariablesRead = scanf("%d", number);
    while (numberOfVariablesRead != 1)
    {
        cleanStdin();
        printf("Input Error. Enter the correct number:\n");
        numberOfVariablesRead = scanf("%d", number);
    }
    cleanStdin();
}

int main()
{
    Set* set = createSet();
    printf("Select an action from the suggestions below.\n");
    printf("0 - Exit;\n");
    printf("1 - Add value to set;\n");
    printf("2 - Remove value from set;\n");
    printf("3 - Check if a value belongs to a set;\n");
    printf("4 - Print set in ascending order;\n");
    printf("5 - Print set in descending order;\n");
    printf("6 - Print set.\n");

    int value = 0;
    int action = 0;
    while (true)
    {
        printf("\n");
        printf("Your action:\n");
        getNumber(&action);
        switch (action)
        {
            case 0:
            {
                printf("Have a nice day! Bye :)");
                deleteSet(set);
                return 0;
            }
            case 1:
            {
                printf("Enter value (number):\n");
                getNumber(&value);
                addElement(value, set);
                break;
            }
            case 2:
            {
                printf("Enter value (number):\n");
                getNumber(&value);
                removeElement(value, set);
                break;
            }
            case 3:
            {
                printf("Enter value (number):\n");
                getNumber(&value);
                if (isContained(value, set))
                {
                    printf("Value is in the set.\n");
                }
                else
                {
                    printf("Value isn't in the set.\n");
                }
                break;
            }
            case 4:
            {
                printf("Set in ascending order:\n");
                printInAscendingOrder(set);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("Set in descending order:\n");
                printInDescendingOrder(set);
                printf("\n");
                break;
            }
            case 6:
            {
                printf("Set:\n");
                printSet(set);
                printf("\n");
                break;
            }
            default:
            {
                printf("Enter the correct action.\n");
                break;
            }
        }
    }
}