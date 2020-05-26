package homeworks.homework3.task1

import java.util.LinkedList

class AVLSet<K, V> : Map<K, V> where K : Comparable<K> {
    private var root: Node<K, V>? = null
    private val subtreeOperations = SubtreeOperations()

    override val entries: Set<Map.Entry<K, V>>
        get() {
            val entries = mutableSetOf<Map.Entry<K, V>>()
            val queue = LinkedList<Node<K, V>?>()
            queue.add(root)
            while (!queue.isEmpty()) {
                val currentNode = queue.pop()
                currentNode?.also {
                    entries.add(currentNode.toEntry())
                    queue.add(it.leftChild)
                    queue.add(it.rightChild)
                }
            }
            return entries.toSet()
        }

    override val keys: Set<K>
        get() {
            val keys = mutableSetOf<K>()
            for (entry in entries) {
                keys.add(entry.key)
            }
            return keys.toSet()
        }

    override val values: Collection<V>
        get() {
            val values = mutableListOf<V>()
            for (entry in entries) {
                values.add(entry.value)
            }
            return values.toList()
        }

    override var size = 0
        private set

    override fun toString() = root.toString()

    override fun isEmpty() = size == 0

    fun equalsTo(tree: AVLSet<K, V>) = this.toString() == tree.toString()

    override fun containsKey(key: K) = get(key) != null

    override fun containsValue(value: V) = values.contains(value)

    override fun get(key: K): V? {
        var current = root
        while (current != null) {
            current = when {
                current.key == key -> return current.value
                current.key > key -> current.leftChild
                else -> current.rightChild
            }
        }
        return null
    }

    fun add(key: K, value: V) {
        if (!containsKey(key)) {
            val root = this.root
            this.root = root?.let { subtreeOperations.add(key, value, root) } ?: Node(key, value)
            size++
        }
    }

    fun remove(key: K) {
        if (containsKey(key)) {
            val root = this.root
            this.root = root?.let { subtreeOperations.remove(key, it) }
            size--
        }
    }

    private inner class SubtreeOperations {
        fun add(key: K, value: V, node: Node<K, V>): Node<K, V>? {
            if (node.key > key) {
                node.leftChild = node.leftChild?.let { add(key, value, it) } ?: Node(key, value)
            } else if (node.key < key) {
                node.rightChild = node.rightChild?.let { add(key, value, it) } ?: Node(key, value)
            }
            return node.balance()
        }

        fun remove(key: K, node: Node<K, V>): Node<K, V>? {
            when {
                key < node.key -> node.leftChild = node.leftChild?.let { remove(key, it) }
                key > node.key -> node.rightChild = node.rightChild?.let { remove(key, it) }
                else -> {
                    val result: Node<K, V>?
                    val leftChild = node.leftChild
                    val rightChild = node.rightChild

                    when {
                        rightChild == null -> {
                            result = leftChild
                        }
                        leftChild == null -> {
                            result = rightChild
                        }
                        else -> {
                            val minimum = rightChild.getMinimumNode()
                            minimum.rightChild = rightChild.removeMinimumNode()
                            minimum.leftChild = leftChild
                            result = minimum.balance()
                        }
                    }

                    return result
                }
            }

            return node.balance()
        }
    }
}
