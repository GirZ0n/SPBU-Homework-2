package homeworks.homework3.task1

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

class AVLSet<K, V> {
    private var root: Node<K, V>? = null

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

    private fun rotateLeft(): Node<K, V>? {
        TODO()
    }

    private fun rotateRight(): Node<K, V>? {
        TODO()
    }

    private fun balance(): Node<K, V>? {
        TODO()
    }

    private fun getMinimumNodeFromRightSubtree(): Node<K, V> {
        TODO()
    }

    private fun removeMinimumNodeFromRightSubtree(): Node<K, V> {
        TODO()
    }
}

