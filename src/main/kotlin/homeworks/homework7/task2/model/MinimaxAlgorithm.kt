package homeworks.homework7.task2.model

object MinimaxAlgorithm {
    private const val MAX_VALUE = 1000
    private const val MIN_VALUE = -MAX_VALUE
    private const val BASIC_VALUE = 10

    fun getBestMove(board: Array<CharArray>, playerSign: Char, opponentSign: Char, emptySign: Char): Pair<Int, Int> {
        var bestValue = MIN_VALUE
        var bestMove = Pair(-1, -1)
        for (i in 0..2) {
            for (j in 0..2) {
                if (board[i][j] == emptySign) {
                    board[i][j] = playerSign
                    val moveValue = minimax(board, false, playerSign, opponentSign, emptySign)
                    val move = Pair(i, j)
                    board[i][j] = emptySign // Undo
                    bestMove = move.takeIf { bestValue < moveValue } ?: bestMove
                    bestValue = moveValue.takeIf { bestValue < it } ?: bestValue
                }
            }
        }
        return bestMove
    }

    private fun minimax(
        board: Array<CharArray>,
        isPlayer: Boolean, // !isPlayer = isOpponent
        playerSign: Char,
        opponentSign: Char,
        emptySign: Char
    ): Int {
        val score = evaluateCurrentState(board, playerSign, opponentSign)

        return if (score == BASIC_VALUE) {
            score
        } else if (score == -BASIC_VALUE) {
            score
        } else if (!isMovesLeft(board, emptySign)) {
            0
        } else if (isPlayer) {
            playerHandling(board, isPlayer, playerSign, opponentSign, emptySign)
        } else {
            opponentHandling(board, isPlayer, playerSign, opponentSign, emptySign)
        }
    }

    private fun playerHandling(
        board: Array<CharArray>,
        isPlayer: Boolean,
        playerSign: Char,
        opponentSign: Char,
        emptySign: Char
    ): Int {
        var best = MIN_VALUE
        for (i in 0..2) {
            for (j in 0..2) {
                if (board[i][j] == emptySign) {
                    board[i][j] = playerSign
                    best = best.coerceAtLeast(minimax(board, !isPlayer, playerSign, opponentSign, emptySign))
                    board[i][j] = emptySign // Undo
                }
            }
        }
        return best
    }

    private fun opponentHandling(
        board: Array<CharArray>,
        isPlayer: Boolean,
        playerSign: Char,
        opponentSign: Char,
        emptySign: Char
    ): Int {
        var best = MAX_VALUE
        for (i in 0..2) {
            for (j in 0..2) {
                if (board[i][j] == emptySign) {
                    board[i][j] = opponentSign
                    best = best.coerceAtMost(minimax(board, !isPlayer, playerSign, opponentSign, emptySign))
                    board[i][j] = emptySign // Undo
                }
            }
        }
        return best
    }

    private fun isMovesLeft(board: Array<CharArray>, emptySign: Char): Boolean {
        for (raw in board) {
            for (elem in raw) {
                if (elem == emptySign) {
                    return true
                }
            }
        }
        return false
    }

    private fun evaluateCurrentState(board: Array<CharArray>, playerSign: Char, opponentSign: Char): Int {
        val results = emptyList<Int>().toMutableList()
        results.add(checkRowsForWinningCombinations(board, playerSign, opponentSign))
        results.add(checkColumnsForWinningCombinations(board, playerSign, opponentSign))
        results.add(checkMainDiagonalForWinningCombination(board, playerSign, opponentSign))
        results.add(checkAntidiagonalForWinningCombination(board, playerSign, opponentSign))
        for (result in results) {
            if (result == BASIC_VALUE || result == -BASIC_VALUE) {
                return result
            }
        }
        return 0
    }

    /*
        The following 4 functions return:
            BASIC_VALUE - when player wins;
            -BASIC_VALUE - when opponent wins;
            0 - when tie.
     */
    private fun checkRowsForWinningCombinations(board: Array<CharArray>, playerSign: Char, opponentSign: Char): Int {
        for (row in 0..2) {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                return if (board[row][0] == playerSign) {
                    BASIC_VALUE
                } else if (board[row][0] == opponentSign) {
                    -BASIC_VALUE
                } else continue
            }
        }
        return 0
    }

    private fun checkColumnsForWinningCombinations(board: Array<CharArray>, playerSign: Char, opponentSign: Char): Int {
        for (column in 0..2) {
            if (board[0][column] == board[1][column] && board[1][column] == board[2][column]) {
                return if (board[0][column] == playerSign) {
                    BASIC_VALUE
                } else if (board[0][column] == opponentSign) {
                    -BASIC_VALUE
                } else continue
            }
        }
        return 0
    }

    private fun checkMainDiagonalForWinningCombination(
        board: Array<CharArray>,
        playerSign: Char,
        opponentSign: Char
    ): Int {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return when (board[1][1]) {
                playerSign -> BASIC_VALUE
                opponentSign -> -BASIC_VALUE
                else -> 0
            }
        }
        return 0
    }

    private fun checkAntidiagonalForWinningCombination(
        board: Array<CharArray>,
        playerSign: Char,
        opponentSign: Char
    ): Int {
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return when (board[1][1]) {
                playerSign -> BASIC_VALUE
                opponentSign -> -BASIC_VALUE
                else -> 0
            }
        }
        return 0
    }
}
