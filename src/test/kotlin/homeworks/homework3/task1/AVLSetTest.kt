package homeworks.homework3.task1

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class AVLSetTest {

    @Test
    fun containsKey_EmptyTree_MustWork() {
        val testTree = AVLSet<Int, Char>()
        assertFalse(testTree.containsKey(362))
    }

    @Test
    fun containsKey_NonEmptyTree_ContainsKey_MustWork() {
        val testTree = AVLSet<Int, Char>()
        for (i in 1..100) {
            testTree.add(i, i.toChar())
        }
        assert(testTree.containsKey(53))
    }

    @Test
    fun containsKey_NonEmptyTree_DoesNotContainKey_MustWork() {
        val testTree = AVLSet<Int, Char>()
        for (i in 1..100) {
            testTree.add(i, i.toChar())
        }
        assertFalse(testTree.containsKey(-1))
    }

    @Test
    fun size_EmptyTree_MustWork() {
        val testTree = AVLSet<Int, Char>()
        assertEquals(0, testTree.size)
    }

    @Test
    fun size_NonEmptyTree_MustWork() {
        val testTree = AVLSet<Int, Char>()
        for (i in 1..32523) {
            testTree.add(i, i.toChar())
        }
        assertEquals(32523, testTree.size)
    }

    @Test
    fun size_NonEmptyTree_AddAndRemoveElements_MustWork() {
        val testTree = AVLSet<Int, Char>()
        for (i in 1..32523) {
            testTree.add(i, i.toChar())
        }
        for (i in 1..124) {
            testTree.remove(i)
        }
        assertEquals(32399, testTree.size)
    }

    @Test
    fun getValue_EmptyArray_MustWork() {
        val testTree = AVLSet<Int, Char>()
        assertNull(testTree.getValue(1))
    }

    @Test
    fun getValue_NonEmptyArray_KeyIsInTree_MustWork() {
        val testTree = AVLSet<Int, Char>()
        for (i in 1..1000) {
            testTree.add(i, i.toChar())
        }
        assertEquals(245.toChar(), testTree.getValue(245))
    }

    @Test
    fun getValue_NonEmptyArray_KeyIsNotInTree_MustWork() {
        val testTree = AVLSet<Int, Char>()
        for (i in 1..1000) {
            testTree.add(i, i.toChar())
        }
        assertNull(testTree.getValue(1001))
    }
}
