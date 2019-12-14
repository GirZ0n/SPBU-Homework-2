#pragma once

#include "ADTstring.h"

struct HashTable;
typedef struct HashTable HashTable;

HashTable* createHashTable(int size);
void deleteHashTable(HashTable* hashtable);
bool isInHashTable(String* key, HashTable* hashtable);
void pushToHashTable(String* key, int value, HashTable* hashtable);
int getValueFromHashTable(String* key, HashTable* hashtable);
void deleteBucketFromHashTable(String* key, HashTable* hashtable);
void changeBucketInHashTable(String* key, int newValue, HashTable* hashtable);
void printHashTableInfo(HashTable* hashtable);