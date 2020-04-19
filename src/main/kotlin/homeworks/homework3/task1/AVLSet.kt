package homeworks.homework3.task1

private const val BALANCE_FACTOR_NEEDED_FOR_LEFT_TURN = 2
private const val BALANCE_FACTOR_NEEDED_FOR_RIGHT_TURN = -2

class AVLSet<K, V> where K : Comparable<K> {
    private var root: Node<K, V>? = null
    var size = 0
        private set

    fun print() {
        root?.print() ?: print("Null")
        println()
    }

    fun containsKey(key: K): Boolean {
        var current = root
        while (current != null) {
            current = when {
                current.key == key -> return true
                current.key > key -> current.leftChild
                else -> current.rightChild
            }
        }
        return false
    }

    fun getValue(key: K): V? {
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
        val root = this.root
        if (!containsKey(key)) {
            this.root = root?.let { addInSubtree(key, value, root) } ?: Node(key, value)
        }
        size++
    }

    private fun addInSubtree(key: K, value: V, node: Node<K, V>): Node<K, V>? {
        if (node.key > key) {
            node.leftChild = node.leftChild?.let { addInSubtree(key, value, it) } ?: Node(key, value)
        } else if (node.key < key) {
            node.rightChild = node.rightChild?.let { addInSubtree(key, value, it) } ?: Node(key, value)
        }
        return node.balance()
    }

    fun remove(key: K) {
        val root = this.root
        if (containsKey(key)) {
            this.root = root?.let { removeInSubtree(key, it) }
        }
        size--
    }

    private fun removeInSubtree(key: K, node: Node<K, V>): Node<K, V>? {
        when {
            key < node.key -> node.leftChild = node.leftChild?.let { removeInSubtree(key, it) }
            key > node.key -> node.rightChild = node.rightChild?.let { removeInSubtree(key, it) }
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

    private class Node<K, V>(val key: K, var value: V) where K : Comparable<K> {
        private var height = 0
        var leftChild: Node<K, V>? = null
        var rightChild: Node<K, V>? = null

        private fun updateHeight() {
            val leftChildHeight = leftChild?.height ?: -1
            val rightChildHeight = rightChild?.height ?: -1
            height = maxOf(leftChildHeight, rightChildHeight) + 1
        }

        private fun getBalanceFactor(): Int {
            val leftChildHeight = leftChild?.height ?: -1
            val rightChildHeight = rightChild?.height ?: -1
            return rightChildHeight - leftChildHeight
        }

        private fun rotateRight(): Node<K, V>? {
            val pivot = leftChild
            leftChild = pivot?.rightChild
            pivot?.rightChild = this
            updateHeight()
            pivot?.updateHeight()
            return pivot
        }

        private fun rotateLeft(): Node<K, V>? {
            val pivot = rightChild
            rightChild = pivot?.leftChild
            pivot?.leftChild = this
            updateHeight()
            pivot?.updateHeight()
            return pivot
        }

        fun balance(): Node<K, V>? {
            updateHeight()
            val rightChildBalanceFactor = rightChild?.getBalanceFactor() ?: -1
            val leftChildBalanceFactor = leftChild?.getBalanceFactor() ?: -1
            val balanceFactor = getBalanceFactor()
            var result: Node<K, V>? = this

            if (balanceFactor == BALANCE_FACTOR_NEEDED_FOR_LEFT_TURN) {
                if (rightChildBalanceFactor < 0) {
                    rightChild = rightChild?.rotateRight()
                }
                result = rotateLeft()
            }

            if (balanceFactor == BALANCE_FACTOR_NEEDED_FOR_RIGHT_TURN) {
                if (leftChildBalanceFactor > 0) {
                    leftChild = leftChild?.rotateLeft()
                }
                result = rotateRight()
            }

            return result
        }

        fun print() {
            print("{[$key: $value] (")
            leftChild?.print() ?: print("Null")
            print(") ")
            print("(")
            rightChild?.print() ?: print("Null")
            print(")}")
        }

        fun getMinimumNode(): Node<K, V> {
            return leftChild?.getMinimumNode() ?: this
        }

        fun removeMinimumNode(): Node<K, V>? {
            if (leftChild == null) {
                return rightChild
            } else {
                leftChild = leftChild?.removeMinimumNode()
            }
            return balance()
        }
    }
}