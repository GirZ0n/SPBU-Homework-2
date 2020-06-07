package homeworks.homework4.task1

import java.lang.NullPointerException
import kotlin.math.abs
import kotlin.math.max

class HashTable<K, V>(
    private var hashFunction: HashFunction<K>,
    private var numberOfBuckets: Int = 1024,
    private var maxLoadFactor: Double = 0.7
) {
    private var arrayOfBuckets = Array(numberOfBuckets) { Bucket<K, V>() }
    private var numberOfFilledBuckets = 0

    var numberOfEntries = 0
        private set

    var loadFactor = 0.0
        private set
        get() = numberOfEntries.toDouble() / numberOfBuckets

    fun add(key: K?, value: V?): Boolean {
        if (key == null || value == null) {
            throw NullPointerException("Key and value must not be null")
        }

        val hash = abs(hashFunction.getHash(key)) % numberOfBuckets
        val bucket = arrayOfBuckets[hash]

        if (bucket.isContains(key)) {
            return false
        }
        if (bucket.size == 0) {
            numberOfFilledBuckets++
        }

        bucket.add(key, value)
        numberOfEntries++

        if (loadFactor > maxLoadFactor) {
            expandHashTable()
        }

        return true
    }

    fun remove(key: K?): Boolean {
        if (key == null) {
            throw NullPointerException("Key must not be null")
        }

        val hash = abs(hashFunction.getHash(key)) % numberOfBuckets
        val bucket = arrayOfBuckets[hash]

        val isRemoved = bucket.remove(key)
        if (bucket.isEmpty()) {
            numberOfFilledBuckets--
        }
        if (isRemoved) {
            numberOfEntries--
        }
        return isRemoved
    }

    fun find(key: K?): V? {
        if (key == null) {
            return null
        }

        val hash = abs(hashFunction.getHash(key)) % numberOfBuckets
        val bucket = arrayOfBuckets[hash]
        return bucket.find(key)
    }

    fun printStatistics() {
        var numberOfConflictingBuckets = 0
        var maximumListLengthInConflictingBuckets = 0
        for (bucket in arrayOfBuckets) {
            if (bucket.size > 1) {
                numberOfConflictingBuckets++
                maximumListLengthInConflictingBuckets = max(maximumListLengthInConflictingBuckets, bucket.size)
            }
        }

        println("Number of entries: $numberOfEntries")
        println("Number of filled buckets: $numberOfFilledBuckets")
        println("Size: $numberOfBuckets")
        println("Load factor: $loadFactor")
        println("Number of conflicting buckets: $numberOfConflictingBuckets")
        println("Maximum list length in conflicting buckets: $maximumListLengthInConflictingBuckets")
    }

    fun changeHashFunction(newHashFunction: HashFunction<K>) {
        hashFunction = newHashFunction
        restructureHashTable()
    }

    private fun expandHashTable() {
        numberOfBuckets *= 2
        restructureHashTable()
    }

    private fun restructureHashTable() {
        val oldArrayOfBuckets = arrayOfBuckets
        arrayOfBuckets = Array(numberOfBuckets) { Bucket<K, V>() }
        numberOfFilledBuckets = 0
        numberOfEntries = 0
        for (bucket in oldArrayOfBuckets) {
            for (entry in bucket.listOfEntries) {
                add(entry.key, entry.value)
            }
        }
    }
}
