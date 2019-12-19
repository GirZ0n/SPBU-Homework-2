#include <stdio.h>
#include <stdlib.h>
#include "ADTstring.h"

String* conversionTest(char* string)
{
    struct String* testString = convertStringToStructString(string);
    printf("Conversion: length = %d\n", getStringLength(testString));
    return testString;
}

void cloneAndPrintTest(String* testString)
{
    struct String* clone = cloneString(testString);
    printf("Clone and print: ");
    printString(clone);
    printf(" (Length = %d)\n", getStringLength(clone));
    deleteString(clone);
}

void convertAndPrintTest(String* testString)
{
    printf("Convert and print (as char*): %s\n", convertStringToCharPointer(testString));
}

void isEmptyTest(String* testString)
{
    printf("Is string empty: %d\n", isStringEmpty(testString));
    struct String* emptyString = convertStringToStructString("");
    printf("Is emptyString empty: %d\n", isStringEmpty(emptyString));
    deleteString(emptyString);
}

void areEqualTest(String* testString)
{
    struct String* equalString = cloneString(testString);
    printf("testString == equalString: %d\n", areStringsEqual(testString, equalString));

    struct String* otherString = convertStringToStructString("123");
    printf("testString == otherString: %d\n", areStringsEqual(testString, otherString));

    deleteString(equalString);
    deleteString(otherString);
}

void getSubstringTest(String* testString)
{
    printf("testString[3:10]: ");
    String* substring = getSubstring(testString, 3, 10);
    printString(substring);
    printf(" (Length = %d)", getStringLength(substring));
    printf("\n");
    deleteString(substring);

    printf("testString[-1000:3256]: ");
    substring = getSubstring(testString, -1000, 3256);
    printString(substring);
    printf(" (Length = %d)", getStringLength(substring));
    printf("\n");
    deleteString(substring);

    printf("testString[435345:-235436]: ");
    substring = getSubstring(testString, 435345, -235436);
    printString(substring);
    printf(" (Length = %d)", getStringLength(substring));
    printf("\n");
    deleteString(substring);
}

void concatenationTest(String* testString)
{
    printf("testString + 2nmfke3: ");
    String* convertedString = convertStringToStructString("2nmfke3");
    concatenateStrings(testString, convertedString);
    printString(testString);
    printf(" (After сoncatenation: length = %d)\n", getStringLength(testString));
    deleteString(convertedString);
}

void getStringFromConsoleTest()
{
    printf("Enter string: ");
    String* input = getStringFromConsole();
    printf("Get string from console and print it: ");
    printString(input);
    printf(" (length = %d)\n", getStringLength(input));
    deleteString(input);
}

void getStringFromFileTest(FILE* testFile)
{
    printf("Get string from file and print it: ");
    String* testString = getStringFromFile(testFile);
    printString(testString);
    printf(" (Length = %d)\n", getStringLength(testString));
    deleteString(testString);
}

void test()
{
    char* string = "2365462kn 3434fd,kwmk";
    printf("string = %s\n\n", string);

    String* testString = conversionTest(string);
    printf("\n");

    cloneAndPrintTest(testString);
    printf("\n");

    convertAndPrintTest(testString);
    printf("\n");

    isEmptyTest(testString);
    printf("\n");

    areEqualTest(testString);
    printf("\n");

    getSubstringTest(testString);
    printf("\n");

    concatenationTest(testString);
    printf("\n");

    getStringFromConsoleTest();
    printf("\n");

    FILE* testFile = fopen("testFile.txt", "r");
    if (testFile == NULL)
    {
        printf("Can not open the file");
        deleteString(testString);
        return;
    }
    getStringFromFileTest(testFile);
    fclose(testFile);

    deleteString(testString);
}

int main()
{
    test();
    return 0;
}