package homeworks.homework4.task1

class Bucket<K, V> {
    val listOfEntries = mutableListOf<Entry<K, V>>()
    var size = 0
        private set
        get() = listOfEntries.size

    fun add(key: K, value: V) = if (!isContains(key)) listOfEntries.add(Entry(key, value)) else false

    fun remove(key: K) = if (isContains(key)) listOfEntries.removeIf { it.key == key } else false

    fun find(key: K) = listOfEntries.find { it.key == key }?.value

    fun isContains(key: K) = key in listOfEntries.map { it.key }

    fun isEmpty() = size == 0
}
