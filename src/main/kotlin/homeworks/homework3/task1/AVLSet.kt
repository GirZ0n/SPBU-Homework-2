package homeworks.homework3.task1

class AVLSet<K, V> where K : Comparable<K>, V : Comparable<V> {
    private var root: Node<K, V>? = null


    private class Node<K, V>(var key: K, var value: V) where K : Comparable<K>, V : Comparable<V> {
        var balanceFactor: Int = 0
            private set
        var leftChild: Node<K, V>? = null
        var rightChild: Node<K, V>? = null
        private val balanceTree = AVLBalance<K, V>()

        private class AVLBalance<K, V> where K : Comparable<K>, V : Comparable<V> {
            private fun rotateLeft(root: Node<K, V>?): Node<K, V>? {
                if (root == null) return null

                val pivot = root.rightChild
                root.rightChild = pivot?.leftChild
                pivot?.leftChild = root
                root.updateBalanceFactor()
                pivot?.updateBalanceFactor()

                return pivot
            }

            private fun rotateRight(root: Node<K, V>?): Node<K, V>? {
                if (root == null) return null

                val pivot = root.leftChild
                root.leftChild = pivot?.rightChild
                pivot?.rightChild = root
                root.updateBalanceFactor()
                pivot?.updateBalanceFactor()

                return pivot
            }

            fun balance(root: Node<K, V>): Node<K, V>? {
                root.updateBalanceFactor()
                val rightChildBalanceFactor = root.rightChild?.balanceFactor ?: -1
                val leftChildBalanceFactor = root.leftChild?.balanceFactor ?: -1

                if (root.balanceFactor == 2) {
                    if (rightChildBalanceFactor < 0) {
                        root.rightChild = rotateRight(root.rightChild)
                    }
                    return rotateLeft(root)
                }

                if (root.balanceFactor == -2) {
                    if (leftChildBalanceFactor > 0) {
                        root.leftChild = rotateLeft(root.leftChild);
                    }
                    return rotateRight(root);
                }

                return root
            }
        }

        private fun getHeight(): Int {
            val leftChildHeight = this.leftChild?.getHeight() ?: -1
            val rightChildHeight = this.rightChild?.getHeight() ?: -1
            return 1 + maxOf(leftChildHeight, rightChildHeight)
        }

        fun updateBalanceFactor() {
            val leftChildHeight = leftChild?.getHeight() ?: -1
            val rightChildHeight = rightChild?.getHeight() ?: -1
            balanceFactor = rightChildHeight - leftChildHeight
        }

        fun add(key: K, value: V): Node<K, V>? {
            if (this.key > key) {
                this.leftChild?.add(key, value) ?: also { it.leftChild = Node(key, value) }
            } else if (this.key < key) {
                this.rightChild?.add(key, value) ?: also { it.rightChild = Node(key, value) }
            }

            return balanceTree.balance(this)
        }

        fun printKeys() {
            print("( ${this.key} ")
            this.leftChild?.printKeys() ?: run {print(" Null")}
            this.rightChild?.printKeys() ?: run {print(" Null")}
            print(") ")
        }
    }

    fun isKeyContained(key: K): Boolean {
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

    fun isValueContained(value: V): Boolean {
        TODO()
    }

    fun add(key: K, value: V) {
        if (root == null) root = Node(key, value)

        if (!isKeyContained(key)) root = root?.add(key, value)
    }

    fun changeValue(key: K, value: V) {
        TODO()
    }

    fun removeKey(key: K) {
        TODO()
    }

    fun removeValue(value: V) {
        TODO()
    }


    private fun getMinimumNodeFromRightSubtree(root: Node<K, V>): Node<K, V> {
        TODO()
    }

    private fun removeMinimumNodeFromRightSubtree(root: Node<K, V>): Node<K, V> {
        TODO()
    }


    fun printKeys() {
        root?.printKeys() ?: run { println("NULL") }
    }
}
