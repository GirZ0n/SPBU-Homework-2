import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class Task1Test {

    @Test
    fun Reverse_OneItemInArray_MustWork() {
        val expected = intArrayOf(1).toTypedArray()
        val actual = intArrayOf(1).toTypedArray()
        reverse(actual, 0, 0)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun Reverse_BeginGraterThanEnd_MustWork() {
        val expected = intArrayOf(1, 2, 3, 4, 5).toTypedArray()
        val actual = intArrayOf(1, 2, 3, 4, 5).toTypedArray()
        reverse(actual, 2, 0)
        assertArrayEquals(expected, actual)

    }

    @Test
    fun Reverse_EndLargerThanSize_MustWork() {
        val expected = intArrayOf(5, 4, 3, 2, 1).toTypedArray()
        val actual = intArrayOf(1, 2, 3, 4, 5).toTypedArray()
        reverse(actual, 0, 10)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun Reverse_BeginLessThanZero_MustWork() {
        val expected = intArrayOf(3, 2, 1, 4, 5).toTypedArray()
        val actual = intArrayOf(1, 2, 3, 4, 5).toTypedArray()
        reverse(actual, -10, 3)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun Reverse_ArrayOfIdenticalElements_MustWork() {
        val expected = intArrayOf(1, 1, 1, 1, 1).toTypedArray()
        val actual = intArrayOf(1, 1, 1, 1, 1).toTypedArray()
        reverse(actual, 2, 3)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun Reverse_EmptyArray_MustWork() {
        val expected = intArrayOf().toTypedArray()
        val actual = intArrayOf().toTypedArray()
        reverse(actual, 0, 0)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun Reverse_ReverseEntireArray_MustWork() {
        val expected = intArrayOf(5, 4, 3, 2, 1).toTypedArray()
        val actual = intArrayOf(1, 2, 3, 4, 5).toTypedArray()
        reverse(actual, 0, 5)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun Reverse_SimpleArray1_MustWork() {
        val expected = intArrayOf(1, 3, 2, 4, 5).toTypedArray()
        val actual = intArrayOf(1, 2, 3, 4, 5).toTypedArray()
        reverse(actual, 1, 3)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun Reverse_SimpleArray2_MustWork() {
        val expected = intArrayOf(1, 4, 3, 2, 5).toTypedArray()
        val actual = intArrayOf(1, 2, 3, 4, 5).toTypedArray()
        reverse(actual, 1, 4)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun Reverse_SeveralReverses_MustWork() {
        val expected = intArrayOf(2, 4, 5, 3, 1).toTypedArray()
        val actual = intArrayOf(1, 2, 3, 4, 5).toTypedArray()
        reverse(actual, 1, 3)
        reverse(actual, 2, 5)
        reverse(actual, 0, 5)
        assertArrayEquals(expected, actual)
    }
}