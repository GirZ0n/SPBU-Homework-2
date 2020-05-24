package homeworks.homework7.task2.model

class AI(
    private val aiSign: Char = '0',
    private val playerSign: Char = 'X',
    private val emptySign: Char = '_',
    private var difficulty: String = "Easy"
) {

    private fun getFreePositions(board: Array<CharArray>): List<Pair<Int, Int>> {
        val freePositions = emptyList<Pair<Int, Int>>().toMutableList()
        for (i in 0..2) {
            for (j in 0..2) {
                if (board[i][j] == '_') {
                    freePositions.add(Pair(i, j))
                }
            }
        }
        return freePositions.toList()
    }

    private fun getMoveEasy(board: Array<CharArray>) = getFreePositions(board).shuffled().first()

    private fun getMoveMedium(board: Array<CharArray>): Pair<Int, Int> {
        return when (listOf(0, 1).shuffled().first()) {
            0 -> getMoveEasy(board)
            1 -> getMoveHard(board)
            else -> throw IllegalStateException("It is not possible to calculate the move")
        }
    }

    private val minimax = MinimaxAlgorithm
    private fun getMoveHard(board: Array<CharArray>): Pair<Int, Int> =
        minimax.getBestMove(board, aiSign, playerSign, emptySign)

    fun getMove(board: Array<CharArray>): Pair<Int, Int> {
        return when (difficulty) {
            "Easy" -> getMoveEasy(board)
            "Medium" -> getMoveMedium(board)
            "Hard" -> getMoveHard(board)
            else -> throw IllegalStateException("Difficulty not defined")
        }
    }
}
