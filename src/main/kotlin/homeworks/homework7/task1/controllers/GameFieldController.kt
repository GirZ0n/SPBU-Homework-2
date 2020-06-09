package homeworks.homework7.task1.controllers

import homeworks.homework7.task1.model.GameModel
import homeworks.homework7.task1.model.WinChecker
import homeworks.homework7.task1.views.GameField
import homeworks.homework7.task1.views.WinnerScreen
import tornadofx.Controller
import tornadofx.text

class GameFieldController : Controller() {
    private val gameModel = GameModel

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

    private fun updateAllButtons(isDisable: Boolean) {
        for (i in 0..2) {
            for (j in 0..2) {
                updateButton("$i-$j", isDisable)
            }
        }
    }

    private fun winHandling(message: String) {
        gameModel.gameStatus = message
        find<GameField>().replaceWith<WinnerScreen>()
    }

    fun moveHandling(buttonID: String) {
        val id = idToInt(buttonID)
        gameModel.board[id.first][id.second] = gameModel.currentSign
        updateButton(buttonID, true)

        val winChecker = WinChecker
        if (winChecker.isPlayerWinning(gameModel.currentSign, gameModel.board)) {
            winHandling("${gameModel.currentSign} won")
        } else if (!areMovesLeft(gameModel.board)) {
            winHandling("Draw")
        }

        gameModel.changeSign()
    }

    private fun areMovesLeft(board: Array<CharArray>): Boolean {
        for (row in board) {
            for (cell in row) {
                if (cell == ' ') {
                    return true
                }
            }
        }
        return false
    }

    fun newGameHandling() {
        gameModel.gameStatus = "Draw"
        gameModel.currentSign = 'X'
        gameModel.clearBoard()
        updateAllButtons(false)
    }
}
