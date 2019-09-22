#include <stdio.h>
#include <string.h>
#include <stdbool.h>


char top(char stack[], int stackPointer)
{
    return stack[stackPointer - 1];
}


bool isEmpty(int stackPointer)
{
    return (stackPointer == 0);
}


void push(char stack[], char element, int stackPointer)
{
    stack[stackPointer] = element;
}


bool isOpening(char bracket)
{
    return (bracket == '(' || bracket == '[' || bracket == '{');
}


bool isSameType(char stack[], char bracket, int stackPointer)
{
    if (bracket == ')' && top(stack, stackPointer) == '(')
    {
        return true;
    }

    if (bracket == ']' && top(stack, stackPointer) == '[')
    {
        return true;
    }

    if (bracket == '}' && top(stack, stackPointer) == '{')
    {
        return true;
    }

    return false;
}


int main()
{
    int stackPointer = 0;
    char stack[256] = "";
    char bracketSequence[256] = "";
    printf("Enter the bracket sequence:");
    scanf("%s", &bracketSequence);


    for (int i = 0; i < strlen(bracketSequence); i++)
    {
        char bracket = bracketSequence[i];
        if (isOpening(bracket))
        {
            push(stack, bracket, stackPointer);
            stackPointer++;
        }
        else
        {
            if (isSameType(stack, bracket, stackPointer))
            {
                stackPointer--; // pop();
            }
            else
            {
                printf("This is not a correct bracket sequences :(");
                return 0;
            }
        }
    }

    if (isEmpty(stackPointer))
    {
        printf("This is a correct bracket sequences!");
        return 0;
    }

    printf("This is not a correct bracket sequences :(");
    return 0;
}