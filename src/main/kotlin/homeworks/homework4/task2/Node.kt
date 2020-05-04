package homeworks.homework4.task2

abstract class Node {
    var leftChild: Node? = null
    var rightChild: Node? = null
    abstract fun calculate(): Int
    abstract override fun toString(): String
}
