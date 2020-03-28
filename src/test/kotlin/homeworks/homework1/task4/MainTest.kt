package homeworks.homework1.task4

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class Task4Test {

    @Test
    fun IsPalindrome_PalindromeString1_MustWork() {
        assert(isPalindrome("abba"))
    }

    @Test
    fun IsPalindrome_PalindromeString2_MustWork() {
        assert(isPalindrome("saippuakivikauppias"))
    }

    @Test
    fun IsPalindrome_PalindromeString3_MustWork() {
        assert(isPalindrome("abcdefedcba"))
    }

    @Test
    fun IsPalindrome_NotPalindromeString1_MustWork() {
        assertFalse(isPalindrome("qwe"))
    }

    @Test
    fun IsPalindrome_NotPalindromeString2_MustWork() {
        assertFalse(isPalindrome("dkngjsngio"))
    }

    @Test
    fun IsPalindrome_NotPalindromeString3_MustWork() {
        assertFalse(isPalindrome("oooooooooooooooooouooooooooooo"))
    }

    @Test
    fun IsPalindrome_SingleCharacterString_MustWork() {
        assert(isPalindrome("aaaaaaaaaaa"))
    }

    @Test
    fun IsPalindrome_EmptyString_MustWork() {
        assert(isPalindrome(""))
    }

    @Test
    fun IsPalindrome_BlankString_MustWork() {
        assert(isPalindrome("              "))
    }

    @Test
    fun IsPalindrome_PalindromeOfEvenLength_MustWork() {
        assert(isPalindrome("abccba"))
    }

    @Test
    fun IsPalindrome_PalindromeOfOddLength_MustWork() {
        assert(isPalindrome("abcba"))
    }
}