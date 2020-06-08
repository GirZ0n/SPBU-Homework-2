package homeworks.homework4.task1

interface HashFunction<K> {
    fun calculateHash(element: K): Int
}
