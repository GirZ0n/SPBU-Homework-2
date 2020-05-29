package homeworks.homework7.task2.controllers

import homeworks.homework7.task2.model.AI
import homeworks.homework7.task2.model.GameModel
import homeworks.homework7.task2.model.WinChecker
import homeworks.homework7.task2.views.GameField
import javafx.beans.property.SimpleStringProperty
import tornadofx.Controller
import tornadofx.text

class GameFieldController : Controller() {
    private val board = GameModel.board
    var gameStatus = SimpleStringProperty("Status: draw")
    private var humanSign = GameModel.humanSign
    private var aiSign = GameModel.aiSign
    private var difficulty = GameModel.difficulty

    private fun idToInt(buttonID: String): Pair<Int, Int> {
        val splitID = buttonID.split("-").map { it.toInt() }
        return Pair(splitID[0], splitID[1])
    }

    private fun updateButton(buttonID: String, isDisable: Boolean) {
        val button = find<GameField>().root.lookup("#$buttonID")
        val id = idToInt(buttonID)
        val currentSign = board[id.first][id.second]
        button.text(currentSign.toString())
        button.isDisable = isDisable
        button.opacity = 1.0
    }

    private fun winHandling(winnerSign: Char) {
        gameStatus.value = "Status: $winnerSign won"
        for (i in 0..2) {
            for (j in 0..2) {
                updateButton("$i-$j", true)
            }
        }
    }

    private fun aiMoveHandling() {
        val winChecker = WinChecker
        val ai = AI(aiSign, humanSign, ' ', difficulty)
        val move = ai.getMove(board)
        if (move == Pair(-1, -1)) {
            return
        }
        board[move.first][move.second] = aiSign
        val buttonID = "${move.first}-${move.second}"
        updateButton(buttonID, true)

        if (winChecker.isPlayerWinning(aiSign, board)) {
            winHandling(aiSign)
        }
    }

    fun humanMoveHandling(buttonID: String) {
        val winChecker = WinChecker
        val id = idToInt(buttonID)
        board[id.first][id.second] = humanSign
        updateButton(buttonID, true)

        if (winChecker.isPlayerWinning(humanSign, board)) {
            winHandling(humanSign)
        } else {
            aiMoveHandling()
        }
    }

    fun newGameHandling() {
        gameStatus.value = "Status: draw"
        humanSign = GameModel.humanSign
        aiSign = GameModel.aiSign
        difficulty = GameModel.difficulty

        for (i in 0..2) {
            for (j in 0..2) {
                board[i][j] = ' '
                updateButton("$i-$j", false)
            }
        }

        if (aiSign == 'X') {
            aiMoveHandling()
        }
    }
}
