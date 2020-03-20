package homeworks.homework1.task4

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class Task4Test {

    @Test
    fun IsPalindrome_PalindromeString1_MustWork() {
        assertEquals(true, isPalindrome("abba"))
    }

    @Test
    fun IsPalindrome_PalindromeString2_MustWork() {
        assertEquals(true, isPalindrome("saippuakivikauppias"))
    }

    @Test
    fun IsPalindrome_PalindromeString3_MustWork() {
        assertEquals(true, isPalindrome("abcdefedcba"))
    }

    @Test
    fun IsPalindrome_NotPalindromeString1_MustWork() {
        assertEquals(false, isPalindrome("qwe"))
    }

    @Test
    fun IsPalindrome_NotPalindromeString2_MustWork() {
        assertEquals(false, isPalindrome("dkngjsngio"))
    }

    @Test
    fun IsPalindrome_NotPalindromeString3_MustWork() {
        assertEquals(false, isPalindrome("oooooooooooooooooouooooooooooo"))
    }

    @Test
    fun IsPalindrome_SingleCharacterString_MustWork() {
        assertEquals(true, isPalindrome("aaaaaaaaaaa"))
    }

    @Test
    fun IsPalindrome_ZeroLengthString_MustWork() {
        assertEquals(true, isPalindrome(""))
    }

    @Test
    fun IsPalindrome_BlankString_MustWork() {
        assertEquals(true, isPalindrome("              "))
    }

    @Test
    fun IsPalindrome_PalindromeOfEvenLength_MustWork() {
        assertEquals(true, isPalindrome("abccba"))
    }

    @Test
    fun IsPalindrome_PalindromeOfOddLength_MustWork() {
        assertEquals(true, isPalindrome("abcba"))
    }
}