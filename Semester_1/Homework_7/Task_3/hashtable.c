#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#include "ADTstring.h"

struct Bucket
{
    String* key;
    int value;
    int insertionAttempts;
    bool isDeleted;
};

typedef struct Bucket Bucket;

Bucket* createBucket(String* key, int value)
{
    if (key == NULL)
    {
        return NULL;
    }

    Bucket* bucket = malloc(sizeof(Bucket));
    bucket->key = cloneString(key);
    bucket->value = value;
    bucket->insertionAttempts = 0;
    bucket->isDeleted = false;
    return bucket;
}

void deleteBucket(Bucket* bucket)
{
    if (bucket != NULL)
    {
        deleteString(bucket->key);
        free(bucket);
    }
}

Bucket* copyBucket(Bucket* bucket)
{
    if (bucket == NULL)
    {
        return NULL;
    }

    Bucket* newBucket = createBucket(bucket->key, bucket->value);
    return newBucket;
}

bool isExist(Bucket* bucket)
{
    return (bucket != NULL) && (bucket->isDeleted == false);
}



struct HashTable
{
    Bucket** arrayOfBuckets;
    int capacity;
    int size;
    double maxLoadFactor;
};

HashTable* createHashTable(int size)
{
    if (size <= 0)
    {
        return NULL;
    }

    HashTable* hashTable = malloc(sizeof(HashTable));
    hashTable->capacity = size;
    hashTable->size = 0;
    hashTable->maxLoadFactor = 0.7; // Recommended level for open addressing hash tables
    hashTable->arrayOfBuckets = malloc(size * sizeof(Bucket*));
    for (int i = 0; i < size; i++)
    {
        hashTable->arrayOfBuckets[i] = NULL;
    }
    return hashTable;
}

void deleteHashTable(HashTable* hashtable)
{
    if (hashtable == NULL)
    {
        return;
    }

    for (int i = 0; i < hashtable->capacity; i++)
    {
        if (hashtable->arrayOfBuckets[i] != NULL)
        {
            deleteBucket(hashtable->arrayOfBuckets[i]);
        }
    }
    free(hashtable->arrayOfBuckets);
    free(hashtable);
}

int getHash(String* key, int base)
{
    if ((key == NULL) || (base < 1))
    {
        return 0;
    }

    char* string = convertStringToCharPointer(key);
    int hash = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        hash = (hash + (i + 1) * string[i]) % base;
    }
    free(string);
    return hash;
}

Bucket* searchForBucket(String* key, HashTable* hashtable)
{
    if ((hashtable == NULL) || (key == NULL))
    {
        return NULL;
    }

    int hash = getHash(key, hashtable->capacity);
    int attempts = 0;
    while (hashtable->arrayOfBuckets[hash] != NULL)
    {
        if (hashtable->arrayOfBuckets[hash]->isDeleted == false &&
            areStringsEqual(hashtable->arrayOfBuckets[hash]->key, key))
        {
            return hashtable->arrayOfBuckets[hash];
        }
        attempts++;
        hash = (hash + attempts * attempts) % hashtable->capacity;
    }

    return NULL;
}

bool isInHashTable(String* key, HashTable* hashtable)
{
    return searchForBucket(key, hashtable) != NULL;
}

void pushBucket(Bucket* bucket, Bucket** arrayOfBuckets, int base)
{
    if (bucket == NULL || arrayOfBuckets == NULL)
    {
        return;
    }

    int hash = getHash(bucket->key, base);
    int attempts = 0;
    while (isExist(arrayOfBuckets[hash]))
    {
        if (areStringsEqual(arrayOfBuckets[hash]->key, bucket->key))
        {
            return;
        }
        attempts++;
        hash = (hash + attempts * attempts) % base;
    }

    if (arrayOfBuckets[hash] != NULL)
    {
        deleteBucket(arrayOfBuckets[hash]);
    }

    bucket->insertionAttempts = attempts;
    arrayOfBuckets[hash] = bucket;
}

void expandHashTable(HashTable* hashtable)
{
    if (hashtable == NULL)
    {
        return;
    }

    int newCapacity = hashtable->capacity * 2;
    Bucket** newArrayOfBuckets = malloc(newCapacity * sizeof(Bucket *));
    for (int i = 0; i < newCapacity; i++)
    {
        newArrayOfBuckets[i] = NULL;
    }

    for (int i = 0; i < hashtable->capacity; i++)
    {
        if (isExist(hashtable->arrayOfBuckets[i]))
        {
            Bucket *newHashBucket = copyBucket(hashtable->arrayOfBuckets[i]);
            pushBucket(newHashBucket, newArrayOfBuckets, newCapacity);
        }
    }

    for (int i = 0; i < hashtable->capacity; i++)
    {
        if (hashtable->arrayOfBuckets[i] != NULL)
        {
            deleteBucket(hashtable->arrayOfBuckets[i]);
        }
    }

    free(hashtable->arrayOfBuckets);
    hashtable->arrayOfBuckets = newArrayOfBuckets;
    hashtable->capacity = newCapacity;
}

void pushToHashTable(String* key, int value, HashTable* hashtable)
{
    if (key == NULL || hashtable == NULL || isInHashTable(key, hashtable))
    {
        return;
    }

    Bucket* newBucket = createBucket(key, value);
    pushBucket(newBucket, hashtable->arrayOfBuckets, hashtable->capacity);
    hashtable->size++;
    if (hashtable->size > hashtable->maxLoadFactor * hashtable->capacity)
    {
        expandHashTable(hashtable);
    }
}

int getValueFromHashTable(String* key, HashTable* hashtable)
{
    if (hashtable == NULL || key == NULL)
    {
        return 0;
    }

    Bucket* bucket = searchForBucket(key, hashtable);
    if (bucket != NULL)
    {
        return bucket->value;
    }

    return 0;
}

void deleteBucketFromHashTable(String* key, HashTable* hashtable)
{
    if (key == NULL || hashtable == NULL)
    {
        return;
    }

    Bucket *bucket = searchForBucket(key, hashtable);
    if (bucket != NULL)
    {
        bucket->isDeleted = true;
        hashtable->size--;
    }
}

void changeBucketInHashTable(String* key, int newValue, HashTable* hashtable)
{
    if (key == NULL || hashtable == NULL)
    {
        return;
    }

    Bucket* oldBucket = searchForBucket(key, hashtable);
    oldBucket->value = newValue;
}

void printHashTableInfo(HashTable* hashtable)
{
    if (hashtable == NULL)
    {
        printf("Hashtable doesn't exist");
        return;
    }

    Bucket* maxCollisionBucket = NULL;
    int maxCollision = 0;
    int collisions = 0;
    for (int i = 0; i < hashtable->capacity; i++)
    {
        if (isExist(hashtable->arrayOfBuckets[i]))
        {
            if (hashtable->arrayOfBuckets[i]->insertionAttempts > maxCollision)
            {
                maxCollisionBucket = hashtable->arrayOfBuckets[i];
                maxCollision = maxCollisionBucket->insertionAttempts;
            }
            collisions += hashtable->arrayOfBuckets[i]->insertionAttempts;
        }
    }

    printf("Hash table capacity = %d\n", hashtable->capacity);
    printf("Number of free buckets = %d\n", hashtable->capacity - hashtable->size);
    printf("Load factor = %f\n", (double) (hashtable->size) / (double) (hashtable->capacity));
    printf("Average number of collisions = %f\n", (double) collisions / (double) hashtable->size);
    if (maxCollisionBucket != NULL)
    {
        printf("Bucket with the biggest collision factor: ");
        printString(maxCollisionBucket->key);
        printf(" %d", maxCollisionBucket->value);
        printf(" (collision factor: %d)\n", maxCollision);
    }
}