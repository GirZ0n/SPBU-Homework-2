package homeworks.homework8.task1.controllers

import homeworks.homework8.task1.model.AI
import homeworks.homework8.task1.model.GameModel
import homeworks.homework8.task1.model.WinChecker
import homeworks.homework8.task1.views.GameField
import homeworks.homework8.task1.views.WinnerScreen
import tornadofx.Controller
import tornadofx.text

class GameFieldController : Controller() {
    private val gameModel = GameModel

    private fun checkFreeMoves(): Boolean {
        for (i in 0..2) {
            for (j in 0..2) {
                if (gameModel.board[i][j] == ' ') {
                    return true
                }
            }
        }
        return false
    }

    private fun idToInt(buttonID: String): Pair<Int, Int> {
        val splitID = buttonID.split("-").map { it.toInt() }
        return Pair(splitID[0], splitID[1])
    }

    private fun updateButton(buttonID: String, isDisable: Boolean) {
        val button = find<GameField>().root.lookup("#$buttonID")
        val id = idToInt(buttonID)
        val currentSign = gameModel.board[id.first][id.second]
        button.text(currentSign.toString())
        button.isDisable = isDisable
        button.opacity = 1.0
    }

    fun endGameHandling(gameStatus: String) {
        gameModel.winner = gameStatus
        find<GameField>().replaceWith<WinnerScreen>()
    }

    private fun aiMoveHandling() {
        val winChecker = WinChecker
        val ai = AI(gameModel.opponentSign, gameModel.playerSign, ' ', gameModel.difficulty)
        val move = ai.getMove(gameModel.board)

        gameModel.board[move.first][move.second] = gameModel.opponentSign
        val buttonID = "${move.first}-${move.second}"
        updateButton(buttonID, true)

        if (winChecker.isPlayerWinning(gameModel.opponentSign, gameModel.board)) {
            endGameHandling("${gameModel.opponentSign} won")
        } else if (!checkFreeMoves()) {
            endGameHandling("Draw")
        }
    }

    fun humanMoveHandling(buttonID: String) {
        val winChecker = WinChecker
        val id = idToInt(buttonID)
        gameModel.board[id.first][id.second] = gameModel.playerSign
        updateButton(buttonID, true)

        if (winChecker.isPlayerWinning(gameModel.playerSign, gameModel.board)) {
            endGameHandling("${gameModel.playerSign} won")
        } else if (checkFreeMoves()) {
            aiMoveHandling()
        } else {
            endGameHandling("Draw")
        }
    }

    fun newGameHandling() {
        gameModel.winner = "Draw"

        for (i in 0..2) {
            for (j in 0..2) {
                gameModel.board[i][j] = ' '
                updateButton("$i-$j", false)
            }
        }

        if (gameModel.opponentSign == 'X') {
            aiMoveHandling()
        }
    }
}
