#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "phonebook.h"

extern const int maxStringSize;

void getName(char* name, char* firstName, char* secondName)
{
    scanf("%s %s", firstName, secondName);
    name[0] = '\0';
    strcat(name, firstName);
    strcat(name, " ");
    strcat(name, secondName);
}

char* createString(int size)
{
    char* newString = malloc(sizeof(char) * size);
    for (int i = 0; i < size; i++)
    {
        newString[i] = '\0';
    }
    return newString;
}

int main()
{
    int phoneBookCapacity = 2;
    int phoneBookSize = 0;
    FILE* input = fopen("Phone_book.txt", "r");
    struct Entry* phoneBook = phoneBookInit(&phoneBookSize, &phoneBookCapacity, input);
    int numberOfEntries = phoneBookSize;
    if (input != NULL)
    {
        fclose(input);
    }

    printf("Select an action from the suggestions below.\n");
    printf("0 - Exit;\n");
    printf("1 - Add telephone directory entry;\n");
    printf("2 - Find phone number by name;\n");
    printf("3 - Find name by phone number;\n");
    printf("4 - Save current data to a file.\n\n");
    printf("Attention! The phone number must be entered in the international format: +12345678...\n");

    char* name = createString(maxStringSize);
    char* firstName = createString(maxStringSize);
    char* secondName = createString(maxStringSize);
    char* phoneNumber = createString(maxStringSize);
    int action = 0;
    while (true)
    {
        printf("\n");
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
                printf("Enter first and last name: ");
                getName(name, firstName, secondName);
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);
                phoneBook = addEntry(phoneBook, &phoneBookSize, &phoneBookCapacity, name, phoneNumber);

                break;
            }
            case 2:
            {
                printf("Enter first and last name: ");
                getName(name, firstName, secondName);
                if (getPhoneByName(phoneBook, phoneBookSize, name, phoneNumber))
                {
                    printf("Result: %s - %s\n", name, phoneNumber);
                }
                else
                {
                    printf("The name is not in the phone book.\n");
                }

                break;
            }
            case 3:
            {
                printf("Enter the phone number: ");
                scanf("%s", phoneNumber);
                if (getNameByPhone(phoneBook, phoneBookSize, name, phoneNumber))
                {
                    printf("Result: %s - %s\n", name, phoneNumber);
                }
                else
                {
                    printf("The phone number is not in the phone book.\n");
                }

                break;
            }
            case 4:
            {
                FILE* output = fopen("Phone_book.txt", "a");
                saveData(phoneBook, phoneBookSize, &numberOfEntries, output);
                fclose(output);

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
