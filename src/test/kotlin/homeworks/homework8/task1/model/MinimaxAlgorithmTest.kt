package homeworks.homework8.task1.model

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class MinimaxAlgorithmTest {
    private val minimaxAlgorithm = MinimaxAlgorithm

    @Test
    fun getBestMove_Row1_BanOpponentWin_MustWork() {
        val board = arrayOf(
            arrayOf('X', ' ', 'X').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', ' ', '0').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, '0', 'X', ' '), Pair(0, 1))
    }

    @Test
    fun getBestMove_Row2_BanOpponentWin_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', '0').toCharArray(),
            arrayOf(' ', 'X', 'X').toCharArray(),
            arrayOf(' ', ' ', ' ').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, '0', 'X', ' '), Pair(1, 0))
    }

    @Test
    fun getBestMove_Row3_BanOpponentWin_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', ' ').toCharArray(),
            arrayOf(' ', '0', ' ').toCharArray(),
            arrayOf(' ', 'X', 'X').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, '0', 'X', ' '), Pair(2, 0))
    }

    @Test
    fun getBestMove_Column1_BanOpponentWin_MustWork() {
        val board = arrayOf(
            arrayOf('X', ' ', ' ').toCharArray(),
            arrayOf(' ', '0', ' ').toCharArray(),
            arrayOf('X', ' ', ' ').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, '0', 'X', ' '), Pair(1, 0))
    }

    @Test
    fun getBestMove_Column2_BanOpponentWin_MustWork() {
        val board = arrayOf(
            arrayOf(' ', 'X', ' ').toCharArray(),
            arrayOf(' ', 'X', ' ').toCharArray(),
            arrayOf('0', ' ', ' ').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, '0', 'X', ' '), Pair(2, 1))
    }

    @Test
    fun getBestMove_Column3_BanOpponentWin_MustWork() {
        val board = arrayOf(
            arrayOf(' ', '0', ' ').toCharArray(),
            arrayOf(' ', ' ', 'X').toCharArray(),
            arrayOf(' ', ' ', 'X').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, '0', 'X', ' '), Pair(0, 2))
    }

    @Test
    fun getBestMove_MainDiagonal_BanOpponentWin_MustWork() {
        val board = arrayOf(
            arrayOf('X', ' ', ' ').toCharArray(),
            arrayOf(' ', 'X', ' ').toCharArray(),
            arrayOf('0', ' ', ' ').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, '0', 'X', ' '), Pair(2, 2))
    }

    @Test
    fun getBestMove_Antidiagonal_BanOpponentWin_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', 'X').toCharArray(),
            arrayOf('0', ' ', ' ').toCharArray(),
            arrayOf('X', ' ', ' ').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, '0', 'X', ' '), Pair(1, 1))
    }

    @Test
    fun getBestMove_Row1_MakeWinMove_MustWork() {
        val board = arrayOf(
            arrayOf('X', ' ', 'X').toCharArray(),
            arrayOf('0', ' ', ' ').toCharArray(),
            arrayOf(' ', ' ', '0').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, 'X', '0', ' '), Pair(0, 1))
    }

    @Test
    fun getBestMove_Row2_MakeWinMove_MustWork() {
        val board = arrayOf(
            arrayOf(' ', 'X', '0').toCharArray(),
            arrayOf(' ', 'X', 'X').toCharArray(),
            arrayOf(' ', '0', '0').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, 'X', '0', ' '), Pair(1, 0))
    }

    @Test
    fun getBestMove_Row3_MakeWinMove_MustWork() {
        val board = arrayOf(
            arrayOf(' ', ' ', '0').toCharArray(),
            arrayOf(' ', '0', ' ').toCharArray(),
            arrayOf(' ', 'X', 'X').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, 'X', '0', ' '), Pair(2, 0))
    }

    @Test
    fun getBestMove_Column1_MakeWinMove_MustWork() {
        val board = arrayOf(
            arrayOf('X', '0', ' ').toCharArray(),
            arrayOf(' ', '0', ' ').toCharArray(),
            arrayOf('X', ' ', ' ').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, 'X', '0', ' '), Pair(1, 0))
    }

    @Test
    fun getBestMove_Column2_MakeWinMove_MustWork() {
        val board = arrayOf(
            arrayOf('0', 'X', ' ').toCharArray(),
            arrayOf('X', 'X', '0').toCharArray(),
            arrayOf('X', ' ', ' ').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, 'X', '0', ' '), Pair(0, 2))
    }

    @Test
    fun getBestMove_Column3_MakeWinMove_MustWork() {
        val board = arrayOf(
            arrayOf('X', '0', ' ').toCharArray(),
            arrayOf('0', '0', 'X').toCharArray(),
            arrayOf(' ', ' ', 'X').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, 'X', '0', ' '), Pair(0, 2))
    }

    @Test
    fun getBestMove_MainDiagonal_MakeWinMove_MustWork() {
        val board = arrayOf(
            arrayOf('X', 'X', ' ').toCharArray(),
            arrayOf('0', 'X', ' ').toCharArray(),
            arrayOf('0', ' ', '0').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, 'X', '0', ' '), Pair(0, 2))
    }

    @Test
    fun getBestMove_Antidiagonal_MakeWinMove_MustWork() {
        val board = arrayOf(
            arrayOf('X', '0', 'X').toCharArray(),
            arrayOf('0', ' ', ' ').toCharArray(),
            arrayOf('X', ' ', '0').toCharArray()
        )
        assertEquals(minimaxAlgorithm.getBestMove(board, 'X', '0', ' '), Pair(1, 1))
    }
}
