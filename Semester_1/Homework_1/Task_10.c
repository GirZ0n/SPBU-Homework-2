#include <stdio.h>
#include <string.h>

int main()
{
    char inputString[256] = "";
    printf("Enter the string:");
    scanf("%s", &inputString);

    const int lengthOfString = strlen(inputString);
    for (int i = 0; i < lengthOfString; i++)
    {
        if (inputString[i] != inputString[lengthOfString - i - 1])
        {
            printf("Not a palindrome :(");
            return 0;
        }
    }

    printf("Palindrome!");
    return 0;
}