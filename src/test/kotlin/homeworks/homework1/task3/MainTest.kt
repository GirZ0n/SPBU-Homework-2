package homeworks.homework1.task3

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class Task3Test {

    @Test
    fun GetNumberOfOccurrences_SubstringIsContainedInSource1_MustWork() {
        assertEquals(8, getNumberOfOccurrences("abababababababa", "a"))
    }

    @Test
    fun GetNumberOfOccurrences_SubstringIsContainedInSource2_MustWork() {
        assertEquals(1, getNumberOfOccurrences("zdkgnsdj", "zdk"))
    }

    @Test
    fun GetNumberOfOccurrences_SubstringIsContainedInSource3_MustWork() {
        assertEquals(1, getNumberOfOccurrences("qwerty", "qwerty"))
    }

    @Test
    fun GetNumberOfOccurrences_SubstringIsNotContainedInSource1_MustWork() {
        assertEquals(0, getNumberOfOccurrences("abababababababa", "q"))
    }

    @Test
    fun GetNumberOfOccurrences_SubstringIsNotContainedInSource2_MustWork() {
        assertEquals(0, getNumberOfOccurrences("kngbksf", "dndgjksgnjdsnjkgn"))
    }

    @Test
    fun GetNumberOfOccurrences_SubstringIsNotContainedInSource3_MustWork() {
        assertEquals(0, getNumberOfOccurrences("qwerty", "qwertu"))
    }

    @Test
    fun GetNumberOfOccurrences_TwoBlankStrings_MustWork() {
        assertEquals(6, getNumberOfOccurrences("        ", "   "))
    }

    @Test
    fun GetNumberOfOccurrences_TwoEmptyStrings_ExceptionThrown() {
        assertThrows(IllegalArgumentException::class.java) {
            getNumberOfOccurrences("", "")
        }
    }

    @Test
    fun GetNumberOfOccurrences_EmptyString_ExceptionThrown() {
        assertThrows(IllegalArgumentException::class.java) {
            getNumberOfOccurrences("", "dsdg")
        }
    }

    @Test
    fun GetNumberOfOccurrences_EmptySubstring_ExceptionThrown() {
        assertThrows(IllegalArgumentException::class.java) {
            getNumberOfOccurrences("qwerty", "")
        }
    }
}