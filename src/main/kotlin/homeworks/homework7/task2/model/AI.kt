package homeworks.homework7.task2.model

import kotlin.random.Random

private const val CHANCE_OF_HARD_DIFFICULTY = 0.7

class AI(
    private val aiSign: Char = '0',
    private val playerSign: Char = 'X',
    private val emptySign: Char = '_',
    private var difficulty: String = "Easy"
) {

    private fun getFreePositions(board: Array<CharArray>): List<Pair<Int, Int>> {
        val freePositions = mutableListOf<Pair<Int, Int>>()
        for (i in 0..2) {
            for (j in 0..2) {
                if (board[i][j] == emptySign) {
                    freePositions.add(Pair(i, j))
                }
            }
        }
        return freePositions.toList()
    }

    private fun getMoveEasy(board: Array<CharArray>): Pair<Int, Int> {
        val freePositions = getFreePositions(board)
        return if (freePositions.isNotEmpty()) {
            getFreePositions(board).shuffled().first()
        } else {
            Pair(-1, -1)
        }
    }

    private fun getMoveMedium(board: Array<CharArray>): Pair<Int, Int> {
        return when {
            Random.nextDouble() < CHANCE_OF_HARD_DIFFICULTY -> getMoveHard(board)
            else -> getMoveEasy(board)
        }
    }

    private fun getMoveHard(board: Array<CharArray>): Pair<Int, Int> {
        val minimax = MinimaxAlgorithm
        return minimax.getBestMove(board, aiSign, playerSign, emptySign)
    }

    fun getMove(board: Array<CharArray>): Pair<Int, Int> {
        return when (difficulty) {
            "Easy" -> getMoveEasy(board)
            "Medium" -> getMoveMedium(board)
            "Hard" -> getMoveHard(board)
            else -> throw IllegalStateException("Difficulty not defined")
        }
    }
}
