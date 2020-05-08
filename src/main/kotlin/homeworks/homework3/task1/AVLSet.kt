package homeworks.homework3.task1

class AVLSet<K, V> where K : Comparable<K> {
    private var root: Node<K, V>? = null
    var size = 0
        private set

    override fun toString() = root.toString()

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

    fun containsKey(key: K) = getElement(key) != null

    fun getValue(key: K) = getElement(key)?.value

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

    private fun subtreeEquals(firstRoot: Node<K, V>?, secondRoot: Node<K, V>?): Boolean {
        if (firstRoot == null) {
            return secondRoot == null
        } else {
            if (secondRoot == null) {
                return false
            } else {
                if (firstRoot.key != secondRoot.key || firstRoot.value != secondRoot.value) {
                    return false
                }
                if (!subtreeEquals(firstRoot.leftChild, secondRoot.leftChild) ||
                    !subtreeEquals(firstRoot.rightChild, secondRoot.rightChild)
                ) {
                    return false
                }
                return true
            }
        }
    }

    fun equalsTo(tree: AVLSet<K, V>): Boolean {
        return subtreeEquals(this.root, tree.root)
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

        private val balanceFactorNeededForTurn = 2
        fun balance(): Node<K, V>? {
            updateHeight()
            val rightChildBalanceFactor = rightChild?.getBalanceFactor() ?: -1
            val leftChildBalanceFactor = leftChild?.getBalanceFactor() ?: -1
            val balanceFactor = getBalanceFactor()
            var result: Node<K, V>? = this

            if (balanceFactor == balanceFactorNeededForTurn) {
                if (rightChildBalanceFactor < 0) {
                    rightChild = rightChild?.rotateRight()
                }
                result = rotateLeft()
            }

            if (balanceFactor == -balanceFactorNeededForTurn) {
                if (leftChildBalanceFactor > 0) {
                    leftChild = leftChild?.rotateLeft()
                }
                result = rotateRight()
            }

            return result
        }

        override fun toString(): String {
            return "{[$key: $value] (${leftChild?.toString()}) (${rightChild?.toString()})}"
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
