package homeworks.homework3.task1

import java.util.LinkedList

class AVLSet<K, V> : Map<K, V> where K : Comparable<K> {
    private var root: Node<K, V>? = null
    private val subtreeOperations = SubtreeOperations()

    override val entries: Set<Map.Entry<K, V>>
        get() {
            val entries = emptySet<Entry<K, V>>().toMutableSet()
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
            val keys = emptySet<K>().toMutableSet()
            for (entry in entries) {
                keys.add(entry.key)
            }
            return keys.toSet()
        }

    override val values: Collection<V>
        get() {
            val keys = emptyList<V>().toMutableList()
            for (entry in entries) {
                keys.add(entry.value)
            }
            return keys.toList()
        }

    override var size = 0
        private set

    override fun toString() = root.toString()

    override fun isEmpty() = size == 0

    fun equalsTo(tree: AVLSet<K, V>) = subtreeOperations.equals(this.root, tree.root)

    override fun containsKey(key: K) = getElement(key) != null

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

    private fun getElement(key: K): Node<K, V>? {
        var current = root
        while (current != null) {
            current = when {
                current.key == key -> return current
                current.key > key -> current.leftChild
                else -> current.rightChild
            }
        }
        return null
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

        fun equals(firstRoot: Node<K, V>?, secondRoot: Node<K, V>?): Boolean {
            if (firstRoot == null) {
                return secondRoot == null
            } else {
                if (secondRoot == null) {
                    return false
                } else {
                    if (firstRoot.key != secondRoot.key || firstRoot.value != secondRoot.value) {
                        return false
                    }
                    if (!equals(firstRoot.leftChild, secondRoot.leftChild) ||
                        !equals(firstRoot.rightChild, secondRoot.rightChild)
                    ) {
                        return false
                    }
                    return true
                }
            }
        }
    }
}
