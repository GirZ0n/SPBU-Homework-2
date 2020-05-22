package homeworks.homework7.task2.model

object WinChecker {
    fun isPlayerWinning(playerSign: Char, board: Array<CharArray>): Boolean {
        return checkRowsForWinningCombination(playerSign, board) ||
                checkColumnsForWinningCombination(playerSign, board) ||
                checkMainDiagonalForWinningCombination(playerSign, board) ||
                checkAntiDiagonalForWinningCombination(playerSign, board)
    }

    private fun checkRowsForWinningCombination(playerSign: Char, board: Array<CharArray>): Boolean {
        for (row in 0..2) {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                if (board[row][0] == playerSign) {
                    return true
                }
            }
        }
        return false
    }

    private fun checkColumnsForWinningCombination(playerSign: Char, board: Array<CharArray>): Boolean {
        for (column in 0..2) {
            if (board[0][column] == board[1][column] && board[1][column] == board[2][column]) {
                if (board[0][column] == playerSign) {
                    return true
                }
            }
        }
        return false
    }

    private fun checkMainDiagonalForWinningCombination(playerSign: Char, board: Array<CharArray>): Boolean {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[1][1] == playerSign) {
                return true
            }
        }
        return false
    }

    private fun checkAntiDiagonalForWinningCombination(playerSign: Char, board: Array<CharArray>): Boolean {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[1][1] == playerSign) {
                return true
            }
        }
        return false
    }
}
