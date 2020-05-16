package homeworks.homework3.task1

class Node<K, V>(val key: K, val value: V) {
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

    fun toEntry() = Entry(key, value)
}
