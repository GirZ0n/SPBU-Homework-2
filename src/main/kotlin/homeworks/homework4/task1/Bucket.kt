package homeworks.homework4.task1

class Bucket<K, V> {
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
