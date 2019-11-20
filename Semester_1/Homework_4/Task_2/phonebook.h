#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <stdbool.h>
#include <stdio.h>

struct Entry;

void createEntry (struct Entry* entry, char* name, char *phoneNumber);
struct Entry* addEntry(struct Entry* phoneBook, int* phoneBookSize, int* phoneBookCapacity, char* name, char* phoneNumber);
void saveData(struct Entry* phoneBook, int phoneBookSize, int* numberOfEntries ,FILE* output);
struct Entry* phoneBookInit(int* phoneBookSize, int* phoneBookCapacity, FILE* input);


/*
 * getPhoneByName - search a name in phoneBook and
 *                  write the corresponding phone number in phoneNumber
 *                - returns true if phone is found, otherwise returns false
 */
bool getPhoneByName(struct Entry* phoneBook, int phoneBookSize, char* name, char* phoneNumber);


/*
 * getNameByPhone - search a phone in phoneBook and
 *                  write the corresponding name in name
 *                - returns true if name is found, otherwise returns false
 */
bool getNameByPhone(struct Entry* phoneBook, int phoneBookSize, char* name, char* phoneNumber);

#endif