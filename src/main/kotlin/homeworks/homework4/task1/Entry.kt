package homeworks.homework4.task1

data class Entry<K, V>(override val key: K, override val value: V) : Map.Entry<K, V>
