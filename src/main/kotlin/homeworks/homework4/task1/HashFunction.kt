package homeworks.homework4.task1

interface HashFunction<K> {
    fun getHash(element: K): Int
}
