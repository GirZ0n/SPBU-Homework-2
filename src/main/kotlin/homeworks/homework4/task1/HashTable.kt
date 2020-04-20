package homeworks.homework4.task1

import kotlin.math.abs
import kotlin.math.max

class HashTable<K, V>(
    private var size: Int,
    private var hashFunction: (K) -> Int,
    private var maxLoadFactor: Double = 0.7
) {
    private var arrayOfBuckets = Array(size) { Bucket<K, V>() }
    private var numberOfFilledBuckets = 0

    var numberOfEntries = 0
        private set

    var loadFactor = 0.0
        private set
        get() = numberOfEntries.toDouble() / size.toDouble()

    fun add(key: K?, value: V?) {
        if (key == null || value == null) {
            return
        }

        val hash = abs(hashFunction(key)) % size
        val bucket = arrayOfBuckets[hash]

        if (bucket.isContains(key)) {
            return
        }
        if (bucket.size == 0) {
            numberOfFilledBuckets++
        }

        bucket.add(key, value)
        numberOfEntries++

        if (loadFactor > maxLoadFactor) {
            expandHashTable()
        }
    }

    fun remove(key: K?) {
        if (key == null) {
            return
        }

        val hash = abs(hashFunction(key)) % size
        val bucket = arrayOfBuckets[hash]

        if (bucket.isEmpty()) {
            return
        }
        bucket.remove(key)
        if (bucket.isEmpty()) {
            numberOfFilledBuckets--
        }
        numberOfEntries--
    }

    fun find(key: K?): V? {
        if (key == null) {
            return null
        }

        val hash = abs(hashFunction(key)) % size
        val bucket = arrayOfBuckets[hash]
        return bucket.find(key)
    }

    fun printStatistics() {
        var numberOfConflicts = 0
        var maximumListLengthInConflictingBuckets = 0
        for (bucket in arrayOfBuckets) {
            if (bucket.size > 1) {
                numberOfConflicts++
                maximumListLengthInConflictingBuckets = max(maximumListLengthInConflictingBuckets, bucket.size)
            }
        }

        println("Number of entries: $numberOfEntries")
        println("Number of filled buckets: $numberOfFilledBuckets")
        println("Size: $size")
        println("Load factor: $loadFactor")
        println("Number of conflicts: $numberOfConflicts")
        println("Maximum list length in conflicting buckets: $maximumListLengthInConflictingBuckets")
    }

    fun changeHashFunction(newHashFunction: (K) -> Int) {
        hashFunction = newHashFunction
        restructureHashTable()
    }

    private fun expandHashTable() {
        size *= 2
        restructureHashTable()
    }

    private fun restructureHashTable() {
        val oldArrayOfBuckets = arrayOfBuckets
        arrayOfBuckets = Array(size) { Bucket<K, V>() }
        numberOfFilledBuckets = 0
        numberOfEntries = 0
        for (bucket in oldArrayOfBuckets) {
            for (entry in bucket.listOfEntries) {
                add(entry.first, entry.second)
            }
        }
    }

    private class Bucket<K, V> {
        val listOfEntries = mutableListOf<Pair<K, V>>()
        var size = 0
            private set
            get() = listOfEntries.size

        fun add(key: K, value: V) = listOfEntries.add(Pair(key, value))

        fun remove(key: K) = listOfEntries.removeIf { it.first == key }

        fun find(key: K) = listOfEntries.find { it.first == key }?.second

        fun isContains(key: K) = key in listOfEntries.map { it.first }

        fun isEmpty() = size == 0
    }
}
