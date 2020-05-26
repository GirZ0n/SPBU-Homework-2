package homeworks.homework3.task1

import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test

internal class NodeTest {

    @Test
    fun toString_SingleNode_MustWork() {
        val node = Node(3, "5")
        val actual = node.toString()
        val expected = "{[3: 5] (null) (null)}"
        assertEquals(expected, actual)
    }

    @Test
    fun toString_NodeWithLeftChild_MustWork() {
        val node = Node(3, "5")
        node.leftChild = Node(1, "7")
        val actual = node.toString()
        val expected = "{[3: 5] ({[1: 7] (null) (null)}) (null)}"
        assertEquals(expected, actual)
    }

    @Test
    fun toString_NodeWithRightChild_MustWork() {
        val node = Node(3, "5")
        node.rightChild = Node(5, "0")
        val actual = node.toString()
        val expected = "{[3: 5] (null) ({[5: 0] (null) (null)})}"
        assertEquals(expected, actual)
    }

    @Test
    fun toString_NodeWithLeftAndRightChild_MustWork() {
        val node = Node(3, "5")
        node.leftChild = Node(1, "7")
        node.rightChild = Node(5, "0")
        val actual = node.toString()
        val expected = "{[3: 5] ({[1: 7] (null) (null)}) ({[5: 0] (null) (null)})}"
        assertEquals(expected, actual)
    }

    @Test
    fun getMinimumNode_SingleNode_MustWork() {
        val node = Node(3, "5")
        val actual = node.getMinimumNode()
        val expected = node
        assert(expected.equalsTo(actual))
    }

    @Test
    fun getMinimumNode_NodeWithLeftChild_MustWork() {
        val node = Node(3, "5")
        node.leftChild = Node(1, "7")
        val actual = node.getMinimumNode()
        val expected = Node(1, "7")
        assert(expected.equalsTo(actual))
    }

    @Test
    fun getMinimumNode_NodeWithRightChild_MustWork() {
        val node = Node(3, "5")
        node.rightChild = Node(5, "0")
        val actual = node.getMinimumNode()
        val expected = node
        assert(expected.equalsTo(actual))
    }

    @Test
    fun getMinimumNode_NodeWithLeftAndRightChild_MustWork() {
        val node = Node(3, "5")
        node.leftChild = Node(1, "7")
        node.rightChild = Node(5, "0")
        val actual = node.getMinimumNode()
        val expected = Node(1, "7")
        assert(expected.equalsTo(actual))
    }

    @Test
    fun removeMinimumNode_SingleNode_MustWork() {
        val node = Node(3, "5")
        val actual = node.removeMinimumNode()
        assertNull(actual)
    }

    @Test
    fun removeMinimumNode_NodeWithLeftChild_MustWork() {
        val node = Node(3, "5")
        node.leftChild = Node(1, "7")
        val actual = node.removeMinimumNode()
        val expected = Node(3, "5")
        assert(expected.equalsTo(actual))
    }

    @Test
    fun removeMinimumNode_NodeWithRightChild_MustWork() {
        val node = Node(3, "5")
        node.rightChild = Node(5, "0")
        val actual = node.removeMinimumNode()
        val expected = Node(5, "0")
        assert(expected.equalsTo(actual))
    }

    @Test
    fun removeMinimumNode_NodeWithLeftAndRightChild_MustWork() {
        val node = Node(3, "5")
        node.leftChild = Node(1, "7")
        node.rightChild = Node(5, "0")
        val actual = node.removeMinimumNode()
        val expected = Node(3, "5")
        expected.rightChild = Node(5, "0")
        assert(expected.equalsTo(actual))
    }
}
