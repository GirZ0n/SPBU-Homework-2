#include <stdio.h>
#include "ADTstring.h"

int main()
{
    char* string = "2365462kn 3434fd,kwmk";
    printf("string = %s\n", string);

    struct String* testString = convertStringToStructString(string);
    printf("Conversion: size = %d, capacity = %d\n", getStringSize(testString), getStringCapacity(testString));

    resizeString(testString, 45);
    printf("Resize: size = %d, capacity = %d\n", getStringSize(testString), getStringCapacity(testString));

    struct String* clone = cloneString(testString);
    printf("Clone and print: ");
    printString(clone);
    printf(" (Size = %d, capacity = %d)\n", getStringSize(clone), getStringCapacity(clone));

    printf("Convert and print (as char*): %s\n", convertStringToCharPointer(testString));

    printf("Is string empty: %d\n", isStringEmpty(testString));
    struct String* emptyString = convertStringToStructString("");
    printf("Is emptyString empty: %d\n", isStringEmpty(emptyString));

    struct String* equalString = convertStringToStructString("2365462kn 3434fd,kwmk");
    printf("testString == equalString: %d\n", areStringsEqual(testString, equalString));

    struct String* otherString = convertStringToStructString("2365462kn 3434fd,kwrk");
    printf("testString == otherString: %d\n", areStringsEqual(testString, otherString));

    printf("testString[3:10]: ");
    printString(getSubstring(testString, 3, 10));
    printf("\n");

    printf("testString[-1000:3256]: ");
    printString(getSubstring(testString, -1000, 2235));
    printf("\n");

    printf("testString[435345:-235436]: ");
    printString(getSubstring(testString, 435345, -235436));
    printf("\n");

    printf("testString + 2nmfke3: ");
    concatenateStrings(testString, convertStringToStructString("2nmfke3"));
    printString(testString);
    printf(" (After сoncatenation: size = %d, capacity = %d)\n",
            getStringSize(testString), getStringCapacity(testString));

    printf("Enter string: ");
    testString = getStringFromConsole();
    printf("Get string from console and print it: ");
    printString(testString);
    printf(" (Size = %d, capacity = %d)\n", getStringSize(testString), getStringCapacity(testString));

    printf("Get string from file and print it: ");
    FILE* test = fopen("testFile.txt", "r");
    testString = getStringFromFile(test);
    printString(testString);
    printf(" (Size = %d, capacity = %d)\n", getStringSize(testString), getStringCapacity(testString));

    return 0;
}