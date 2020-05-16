package homeworks.homework6.task1

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class MainTest {

    @Test
    fun quickSort_EmptyArray_MustWork() {
        val actual = emptyArray<Int>()
        val expected = emptyArray<Int>()
        quickSort(actual, 0, actual.lastIndex)
        assertEquals(expected.toList(), actual.toList())
    }

    @Test
    fun quickSort_SameElementsInArray_MustWork() {
        val actual = arrayOf(42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42)
        val expected = actual.sortedArray()
        quickSort(actual, 0, actual.lastIndex)
        assertEquals(expected.toList(), actual.toList())
    }

    @Test
    fun quickSort_NonEmptyArray1_MustWork() {
        val actual = arrayOf(1, 14, -14, 27, -6, 11, 27, 9, 3, 14, 14, -31, 2, -14, -19, -34, -30, -35, -27, -15)
        val expected = actual.sortedArray()
        quickSort(actual, 0, actual.lastIndex)
        assertEquals(expected.toList(), actual.toList())
    }

    @Test
    fun quickSort_NonEmptyArray2_MustWork() {
        val actual = arrayOf(-3, -35, 3, 16, -5, -14, -32, -38, 19, -27, -26, -35, -19, -32, -39, 22, -13, 22, 16, 16)
        val expected = actual.sortedArray()
        quickSort(actual, 0, actual.lastIndex)
        assertEquals(expected.toList(), actual.toList())
    }

    @Test
    fun quickSort_NonEmptyArray3_MustWork() {
        val actual = arrayOf(9, 30, 31, -13, 13, 5, -29, -26, 21, -35, -32, -29, -16, -8, 27, -2, -21, 4, 36, 34)
        val expected = actual.sortedArray()
        quickSort(actual, 0, actual.lastIndex)
        assertEquals(expected.toList(), actual.toList())
    }

    @Test
    fun asyncQuickSort_EmptyArray_MustWork() {
        val actual = emptyArray<Int>()
        val expected = emptyArray<Int>()
        quickSort(actual, 0, actual.lastIndex)
        assertEquals(expected.toList(), actual.toList())
    }

    @Test
    fun asyncQuickSort_SameElementsInArray_MustWork() {
        val actual = arrayOf(42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42)
        val expected = actual.sortedArray()
        quickSort(actual, 0, actual.lastIndex)
        assertEquals(expected.toList(), actual.toList())
    }

    @Test
    fun asyncQuickSort_NonEmptyArray1_MustWork() {
        val actual = arrayOf(28, 36, -21, 2, -5, 0, -4, 5, -39, 11, 22, -3, 39, 20, -31, 2, 23, -33, -31, -33)
        val expected = actual.sortedArray()
        quickSort(actual, 0, actual.lastIndex)
        assertEquals(expected.toList(), actual.toList())
    }

    @Test
    fun asyncQuickSort_NonEmptyArray2_MustWork() {
        val actual = arrayOf(28, -21, -4, -37, -35, 9, 6, 9, -37, 26, 29, 0, -30, 20, -34, 15, 16, -12, -5, 18)
        val expected = actual.sortedArray()
        quickSort(actual, 0, actual.lastIndex)
        assertEquals(expected.toList(), actual.toList())
    }

    @Test
    fun asyncQuickSort_NonEmptyArray3_MustWork() {
        val actual = arrayOf(10, 34, 20, -24, 34, 3, 39, 23, -26, 37, 21, 12, 37, 4, -20, -14, -27, 26, 29, 10)
        val expected = actual.sortedArray()
        quickSort(actual, 0, actual.lastIndex)
        assertEquals(expected.toList(), actual.toList())
    }
}
