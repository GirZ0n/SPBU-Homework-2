package homeworks.homework7.task1.model

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class WinCheckerTest {
    private val winChecker = WinChecker

    @Test
    fun isPlayerWinning_Row1_PlayerWinning_MustWork() {
        val board = arrayOf(
            arrayOf('X', 'X', 'X').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray()
        )
        assert(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Row1_PlayerNotWinning_MustWork() {
        val board = arrayOf(
            arrayOf('X', ' ', 'X').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray()
        )
        assertFalse(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Row2_PlayerWinning_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf('X', 'X', 'X').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray()
        )
        assert(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Row2_PlayerNotWinning_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf('X', 'X', ' ').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray()
        )
        assertFalse(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Row3_PlayerWinning_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf('X', 'X', 'X').toCharArray()
        )
        assert(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Row3_PlayerNotWinning_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', ' ', 'X').toCharArray()
        )
        assertFalse(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Column1_PlayerWinning_MustWork() {
        val board = arrayOf(
            arrayOf('X', ' ', ' ').toCharArray(),
            arrayOf('X', ' ', ' ').toCharArray(),
            arrayOf('X', ' ', ' ').toCharArray()
        )
        assert(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Column1_PlayerNotWinning_MustWork() {
        val board = arrayOf(
            arrayOf('X', ' ', ' ').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray()
        )
        assertFalse(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Column2_PlayerWinning_MustWork() {
        val board = arrayOf(
            arrayOf(' ', 'X', ' ').toCharArray(),
            arrayOf(' ', 'X', ' ').toCharArray(),
            arrayOf(' ', 'X', ' ').toCharArray()
        )
        assert(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Column2_PlayerNotWinning_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', 'X', ' ').toCharArray(),
            arrayOf(' ', 'X', ' ').toCharArray()
        )
        assertFalse(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Column3_PlayerWinning_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', 'X').toCharArray(),
            arrayOf(' ', ' ', 'X').toCharArray(),
            arrayOf(' ', ' ', 'X').toCharArray()
        )
        assert(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Column3_PlayerNotWinning_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', 'X').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', ' ', 'X').toCharArray()
        )
        assertFalse(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_MainDiagonal_PlayerWinning_MustWork() {
        val board = arrayOf(
            arrayOf('X', ' ', ' ').toCharArray(),
            arrayOf(' ', 'X', ' ').toCharArray(),
            arrayOf(' ', ' ', 'X').toCharArray()
        )
        assert(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_MainDiagonal_PlayerNotWinning_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', 'X', ' ').toCharArray(),
            arrayOf(' ', ' ', 'X').toCharArray()
        )
        assertFalse(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Antidiagonal_PlayerWinning_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', 'X').toCharArray(),
            arrayOf(' ', 'X', ' ').toCharArray(),
            arrayOf('X', ' ', ' ').toCharArray()
        )
        assert(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_Antidiagonal_PlayerNotWinning_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', 'X', ' ').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray()
        )
        assertFalse(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_ComplexBoard1_PlayerNotWinning_MustWork() {
        val board = arrayOf(
            arrayOf('0', '0', ' ').toCharArray(),
            arrayOf('X', 'X', 'X').toCharArray(),
            arrayOf('X', '0', ' ').toCharArray()
        )
        assert(winChecker.isPlayerWinning('X', board))
    }

    @Test
    fun isPlayerWinning_ComplexBoard2_PlayerNotWinning_MustWork() {
        val board = arrayOf(
            arrayOf('0', '0', 'X').toCharArray(),
            arrayOf('X', '0', 'X').toCharArray(),
            arrayOf('X', '0', ' ').toCharArray()
        )
        assert(winChecker.isPlayerWinning('0', board))
    }
}
