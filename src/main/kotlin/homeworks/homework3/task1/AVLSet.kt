package homeworks.homework3.task1

class AVLSet<K, V> {
    private var root: Node<K, V>? = null
    private val balanceTree = AVLBalance<K, V>()

    private class AVLBalance<K, V> {
        private fun rotateLeft(root: Node<K, V>): Node<K, V>? {
            TODO()
        }

        private fun rotateRight(root: Node<K, V>): Node<K, V>? {
            TODO()
        }

        private fun balance(root: Node<K, V>): Node<K, V>? {
            TODO()
        }

        private fun getMinimumNodeFromRightSubtree(root: Node<K, V>): Node<K, V> {
            TODO()
        }

        private fun removeMinimumNodeFromRightSubtree(root: Node<K, V>): Node<K, V> {
            TODO()
        }
    }

    private class Node<K, V>(var key: K, var value: V) {
        var leftChild: Node<K, V>? = null
        var rightChild: Node<K, V>? = null

        fun getHeight(): Int {
            TODO()
        }

        fun getBalanceFactor(): Int {
            TODO()
        }

        fun updateHeight() {
            TODO()
        }
    }

    fun isKeyContained(key: K): Boolean {
        TODO()
    }

    fun isValueContained(value: V): Boolean {
        TODO()
    }

    fun add(key: K, value: V) {
        TODO()
    }

    fun removeKey(key: K) {
        TODO()
    }

    fun removeValue(value: V) {
        TODO()
    }

    fun printInAscendingOrder() {
        TODO()
    }

    fun printInDescendingOrder() {
        TODO()
    }

    fun printSet() {
        TODO()
    }
}

