#pragma once

#include "ADTstring.h"

struct HashTable;
typedef struct HashTable HashTable;

HashTable* createHashTable(int size);
void deleteHashTable(HashTable* hashTable);
bool isInHashTable(String* key, HashTable* hashTable);
void pushToHashTable(String* key, int value, HashTable* hashTable);
int getValueFromHashTable(String* key, HashTable* hashTable);
void deleteBucketFromHashTable(String* key, HashTable* hashTable);
void changeBucketInHashTable(String* key, int newValue, HashTable* hashTable);
bool setMaxLoadFactor(double newMaxLoadFactor, HashTable* hashTable);
void printHashTableInfo(HashTable* hashTable);