import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class Task3Test {

    @Test
    fun GetNumberOfOccurrences_SubstringIsContainedInSource1_MustWork() {
        assertEquals(8, getNumberOfOccurrences("abababababababa", "a"))
    }

    @Test
    fun GetNumberOfOccurrences_SubstringIsContainedInSource2_MustWork() {
        assertEquals(7, getNumberOfOccurrences("abababababababa", "aba"))
    }

    @Test
    fun GetNumberOfOccurrences_SubstringIsContainedInSource3_MustWork() {
        assertEquals(1, getNumberOfOccurrences("zdkgnsdj", "zdk"))
    }

    @Test
    fun GetNumberOfOccurrences_SubstringIsContainedInSource4_MustWork() {
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
    fun GetNumberOfOccurrences_SubstringIsNotContainedInSource4_MustWork() {
        assertEquals(0, getNumberOfOccurrences("abababababababa", "q"))
    }

    @Test
    fun GetNumberOfOccurrences_TwoEmptyStrings_MustWork() {
        assertEquals(0, getNumberOfOccurrences("ndfnsaf", "fasnfdn"))
    }

    @Test
    fun GetNumberOfOccurrences_TwoBlankStrings_MustWork() {
        assertEquals(6, getNumberOfOccurrences("        ", "   "))
    }
}