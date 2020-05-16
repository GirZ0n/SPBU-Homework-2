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
    fun get_EmptyArray_MustWork() {
        val testTree = AVLSet<Int, Char>()
        assertNull(testTree[1])
    }

    @Test
    fun get_NonEmptyArray_KeyIsInTree_MustWork() {
        val testTree = AVLSet<Int, Char>()
        for (i in 1..1000) {
            testTree.add(i, i.toChar())
        }
        assertEquals(245.toChar(), testTree[245])
    }

    @Test
    fun get_NonEmptyArray_KeyIsNotInTree_MustWork() {
        val testTree = AVLSet<Int, Char>()
        for (i in 1..1000) {
            testTree.add(i, i.toChar())
        }
        assertNull(testTree[1001])
    }

    @Test
    fun addAndRemove_EmptyTree_MustWork() {
        val expected = AVLSet<Int, Char>()
        val actual = AVLSet<Int, Char>()
        for (i in 1..100) {
            actual.add(i, i.toChar())
        }
        for (i in 1..100) {
            actual.remove(i)
        }
        assert(expected.equalsTo(actual))
    }

    @Test
    fun addAndRemove_NonEmpty_MustWork() {
        val expected = AVLSet<Int, Char>()
        expected.add(1, 'a')
        expected.add(2, 'b')
        expected.add(3, 'c')
        val actual = AVLSet<Int, Char>()
        actual.add(1, 'a')
        actual.add(3, 'c')
        actual.add(235, 'q')
        actual.add(2, 'b')
        actual.remove(235)

        assert(expected.equalsTo(actual))
    }

    @Test
    fun isEmpty_EmptyTree_MustWork() {
        val testTree = AVLSet<Int, Char>()
        assert(testTree.isEmpty())
    }

    @Test
    fun isEmpty_NonEmptyTree_ContainsKey_MustWork() {
        val testTree = AVLSet<Int, Char>()
        for (i in 1..100) {
            testTree.add(i, i.toChar())
        }
        assertFalse(testTree.isEmpty())
    }
}
