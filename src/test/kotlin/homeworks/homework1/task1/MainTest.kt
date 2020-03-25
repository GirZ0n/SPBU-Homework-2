package homeworks.homework1.task1

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class Task1Test {

    @Test
    fun Reverse_OneItemInArray_MustWork() {
        val expected = listOf(1)
        var actual = listOf(1)
        actual = reverse(actual, 0, 1)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun Reverse_BeginGraterThanEnd_ExceptionThrown() {
        var array = listOf(4, 4, 4, 1, 4, 6, 7, 7, 9, 7, 0, 7, 8, 9, 5, 2, 0, 4, 2, 3)
        assertThrows(IllegalArgumentException::class.java) {
            array = reverse(array, 30, 0)
        }
    }

    @Test
    fun Reverse_EndLargerThanSize_ExceptionThrown() {
        var array = listOf(1, 7, 1, 2, 4, 1, 6, 0, 1, 8, 1, 2, 4, 8, 1, 3, 5, 4, 3, 9)
        assertThrows(java.lang.IllegalArgumentException::class.java) {
            array = reverse(array, 0, 1000)
        }
    }

    @Test
    fun Reverse_BeginLessThanZero_ExceptionThrown() {
        var array = listOf(0, 8, 2, 3, 7, 3, 4, 1, 0, 3, 9, 5, 5, 4, 0, 5, 7, 5, 6, 4)
        assertThrows(IllegalArgumentException::class.java) {
            array = reverse(array, -10000, 3)
        }
    }

    @Test
    fun Reverse_ArrayOfIdenticalElements_MustWork() {
        val expected = listOf(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)
        var actual = listOf(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)
        actual = reverse(actual, 2, 3)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun Reverse_EmptyArray_MustWork() {
        val expected = emptyList<Int>()
        var actual = emptyList<Int>()
        actual = reverse(actual, 0, 0)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun Reverse_ReverseEntireArray_MustWork() {
        val expected = listOf(6, 8, 5, 2, 4, 4, 8, 5, 1, 2, 9, 0, 8, 5, 8, 1, 3, 0, 2, 4)
        var actual = listOf(4, 2, 0, 3, 1, 8, 5, 8, 0, 9, 2, 1, 5, 8, 4, 4, 2, 5, 8, 6)
        actual = reverse(actual, 0, 20)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun Reverse_SimpleArray1_MustWork() {
        val expected = listOf(2, 4, 2, 4, 8, 6, 3, 0, 3, 4, 3, 7, 1, 3, 0, 2, 9, 8, 9, 9)
        var actual = listOf(2, 4, 2, 4, 8, 6, 3, 0, 3, 4, 9, 2, 0, 3, 1, 7, 3, 8, 9, 9)
        actual = reverse(actual, 10, 17)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun Reverse_SimpleArray2_MustWork() {
        val expected = listOf(0, 3, 4, 4, 0, 4, 8, 4, 4, 1, 6, 8, 4, 4, 9, 9, 8, 0, 7, 2)
        var actual = listOf(0, 4, 0, 4, 4, 3, 8, 4, 4, 1, 6, 8, 4, 4, 9, 9, 8, 0, 7, 2)
        actual = reverse(actual, 1, 6)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun Reverse_SimpleArray3_MustWork() {
        val expected = listOf(2, 4, 8, 1, 3, 4, 6, 3, 9, 8, 7, 2, 3, 3, 8, 5, 7, 9, 3, 5)
        var actual = listOf(2, 4, 8, 7, 5, 8, 3, 3, 2, 7, 8, 9, 3, 6, 4, 3, 1, 9, 3, 5)
        actual = reverse(actual, 3, 17)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun SwapBeginAndEnd_EmptyArray_MustWork() {
        var array = emptyList<Int>()
        array = swapBeginAndEnd(array, 0, 0)
        assertEquals(emptyList<Int>(), array)
    }

    @Test
    fun SwapBeginAndEnd_ArrayOfIdenticalElements_MustWork() {
        val expected = listOf(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)
        var actual = listOf(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)
        actual = swapBeginAndEnd(actual, 12, 8)
        assertEquals(expected, actual)
    }

    @Test
    fun SwapBeginAndEnd_BeginLengthEqualsArraySize_MustWork() {
        val expected = listOf(8, 0, 2, 5, 8, 2, 4, 9, 5, 9, 9, 4, 9, 7, 7, 0, 5, 2, 5, 8)
        var actual = listOf(8, 0, 2, 5, 8, 2, 4, 9, 5, 9, 9, 4, 9, 7, 7, 0, 5, 2, 5, 8)
        actual = swapBeginAndEnd(actual, 20, 0)
        assertEquals(expected, actual)
    }

    @Test
    fun SwapBeginAndEnd_EndLengthEqualsArraySize_MustWork() {
        val expected = listOf(5, 4, 0, 6, 2, 1, 3, 6, 0, 8, 7, 8, 0, 0, 9, 4, 1, 2, 2, 5)
        var actual = listOf(5, 4, 0, 6, 2, 1, 3, 6, 0, 8, 7, 8, 0, 0, 9, 4, 1, 2, 2, 5)
        actual = swapBeginAndEnd(actual, 0, 20)
        assertEquals(expected, actual)
    }

    @Test
    fun SwapBeginAndEnd_BeginLengthPlusEndLengthLargerThanArraySize_ExceptionThrown() {
        var array = listOf(7, 4, 1, 9, 0, 0, 1, 1, 8, 9, 9, 4, 6, 0, 8, 2, 0, 7, 4, 3)
        assertThrows(java.lang.IllegalArgumentException::class.java) {
            array = swapBeginAndEnd(array, 12, 20)
        }
    }

    @Test
    fun SwapBeginAndEnd_OneItemInArray_ExceptionThrown() {
        val expected = listOf(42)
        var actual = listOf(42)
        actual = swapBeginAndEnd(actual, 1, 0)
        assertEquals(expected, actual)
    }

    @Test
    fun SwapBeginAndEnd_SimpleArray1_ExceptionThrown() {
        val expected = List(158) {it + 42} + List(42) {it}
        var actual = List(200) {it}
        actual = swapBeginAndEnd(actual, 42, 158)
        assertEquals(expected, actual)
    }

    @Test
    fun SwapBeginAndEnd_SimpleArray2_ExceptionThrown() {
        val expected = listOf(2, 1, 9, 8, 6, 4, 4, 4, 8, 5, 7, 3, 0, 6, 7, 7, 6, 9, 2, 4)
        var actual = listOf(8, 5, 7, 3, 0, 6, 7, 7, 6, 9, 2, 4, 2, 1, 9, 8, 6, 4, 4, 4)
        actual = swapBeginAndEnd(actual, 12, 8)
        assertEquals(expected, actual)
    }

    @Test
    fun SwapBeginAndEnd_SimpleArray3_ExceptionThrown() {
        val expected = listOf(1, 0, 3, 3, 4, 4, 5, 0, 6, 1, 7, 4, 5, 3, 0, 1, 5, 6, 9, 9)
        var actual = listOf(6, 9, 9, 1, 0, 3, 3, 4, 4, 5, 0, 6, 1, 7, 4, 5, 3, 0, 1, 5)
        actual = swapBeginAndEnd(actual, 3, 17)
        assertEquals(expected, actual)
    }

    @Test
    fun SwapBeginAndEnd_SimpleArray4_ExceptionThrown() {
        val expected = listOf(6, 0, 3, 6, 1, 9, 7, 9, 4, 1, 5, 9, 5, 5, 3, 6, 3, 8, 6, 0)
        var actual = listOf(4, 1, 5, 9, 5, 5, 3, 6, 3, 8, 6, 0, 6, 0, 3, 6, 1, 9, 7, 9)
        actual = swapBeginAndEnd(actual, 12, 8)
        assertEquals(expected, actual)
    }
}
