package homeworks.homework2.task2

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class Task2Test {

    @Test
    fun DeleteAllLeftEntries_EmptyArray_MustWork() {
        val expected = emptyList<Any>()
        var actual = emptyList<Any>()
        actual = deleteAllLeftEntries(actual)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun DeleteAllLeftEntries_OneItemInArray_MustWork() {
        val expected = List<Any>(1) { 1 }
        var actual = List<Any>(1) { 1 }
        actual = deleteAllLeftEntries(actual)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun DeleteAllLeftEntries_IntArray1_MustWork() {
        val expected: List<Any> = listOf(3, 2, 1)
        var actual: List<Any> = listOf(1, 2, 3, 3, 2, 1, 1, 2, 3, 3, 2, 1)
        actual = deleteAllLeftEntries(actual)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun DeleteAllLeftEntries_IntArray2_MustWork() {
        val expected: List<Any> = listOf(4, 7, 2, 1, 3, 5, 6, 8, 9)
        var actual: List<Any> = listOf(1, 4, 2, 3, 5, 7, 3, 5, 8, 9, 2, 1, 3, 5, 6, 8, 9)
        actual = deleteAllLeftEntries(actual)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun DeleteAllLeftEntries_CharArray1_MustWork() {
        val expected: List<Any> = listOf('q', '1', 'b', 'a')
        var actual: List<Any> = listOf('a', 'b', 'q', '1', '1', 'b', 'a')
        actual = deleteAllLeftEntries(actual)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun DeleteAllLeftEntries_CharArray2_MustWork() {
        val expected: List<Any> = listOf('a', 'b', 'c')
        var actual: List<Any> = listOf('a', 'a', 'a', 'b', 'b', 'c', 'b', 'c', 'a', 'b', 'b', 'c')
        actual = deleteAllLeftEntries(actual)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun DeleteAllLeftEntries_StringArray1_MustWork() {
        val expected: List<Any> = listOf("rty", "qwe")
        var actual: List<Any> = listOf("rty", "qwe", "qwe", "qwe", "rty", "rty", "qwe")
        actual = deleteAllLeftEntries(actual)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun DeleteAllLeftEntries_StringArray2_MustWork() {
        val expected: List<Any> = listOf("rty", "1", "qwe", "dnig")
        var actual: List<Any> = listOf("rty", "qwe", "dnig", "1", "1", "qwe", "dnig")
        actual = deleteAllLeftEntries(actual)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun DeleteAllLeftEntries_MixedArray1_MustWork() {
        val expected: List<Any> = listOf(1, "qwerty", 'a')
        var actual: List<Any> = listOf(1, "qwerty", 'a', 'a')
        actual = deleteAllLeftEntries(actual)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }

    @Test
    fun DeleteAllLeftEntries_MixedArray2_MustWork() {
        val expected: List<Any> = listOf(1, "qwerty", 's', 'a', "2rwfc", 3, "1")
        var actual: List<Any> = listOf(1, "qwerty", 's', 3, 'a', 'a', "2rwfc", 3, 3, "1")
        actual = deleteAllLeftEntries(actual)
        assertArrayEquals(expected.toTypedArray(), actual.toTypedArray())
    }
}