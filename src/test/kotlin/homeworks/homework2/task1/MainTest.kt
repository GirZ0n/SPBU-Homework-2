package homeworks.homework2.task1

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class Task1Test {

    @Test
    fun CountXToBeDeleted_EmptyString_ExceptionThrown() {
        assertThrows(IllegalArgumentException::class.java) {
            countXToBeDeleted("")
        }
    }

    @Test
    fun CountXToBeDeleted_BlankString_MustWork() {
        assertEquals(0, countXToBeDeleted("         "))
    }

    @Test
    fun CountXToBeDeleted_StringDoesntContainX_MustWork() {
        assertEquals(0, countXToBeDeleted("sdnhgisd"))
    }

    @Test
    fun CountXToBeDeleted_StringContainsX_MustWork() {
        assertEquals(0, countXToBeDeleted("ababxababxbxbabab"))
    }

    @Test
    fun CountXToBeDeleted_StringContainsSubstringXX_MustWork() {
        assertEquals(0, countXToBeDeleted("ababxxababxxbxbabab"))
    }

    @Test
    fun CountXToBeDeleted_StringConsistsOfX_MustWork() {
        assertEquals(12, countXToBeDeleted("xxxxxxxxxxxxxx"))
    }

    @Test
    fun CountXToBeDeleted_StringContainsSubstringXXX1_MustWork() {
        assertEquals(5, countXToBeDeleted("xxxdsjbfxxxxdnsjnxxxx"))
    }

    @Test
    fun CountXToBeDeleted_StringContainsSubstringXXX2_MustWork() {
        assertEquals(8, countXToBeDeleted("aaaaaxxxxxxxxxaaxaxaxaxaxxx"))
    }

    @Test
    fun CountXToBeDeleted_StringContainsSubstringXXX3_MustWork() {
        assertEquals(5, countXToBeDeleted("xxxaxxxaxxxaxxxaxxxaxx"))
    }

    @Test
    fun CountXToBeDeleted_StringContainsSubstringXXX4_MustWork() {
        assertEquals(1, countXToBeDeleted("axaxaxaxaxaxaxaxaxaxaxaxaxaxxx"))
    }
}