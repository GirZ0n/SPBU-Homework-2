package homeworks.homework7.task2.controllers

import homeworks.homework7.task2.model.AI
import homeworks.homework7.task2.views.Menu
import homeworks.homework7.task2.model.WinChecker
import homeworks.homework7.task2.views.GameField
import javafx.beans.property.SimpleStringProperty
import tornadofx.Controller
import tornadofx.text

class GameFieldController : Controller() {
    private val board = arrayOf(
        arrayOf('_', '_', '_').toCharArray(),
        arrayOf('_', '_', '_').toCharArray(),
        arrayOf('_', '_', '_').toCharArray()
    )
    var gameStatus = SimpleStringProperty("Status: draw")
    private var humanSign = find<Menu>().selectedSign.value ?: 'X'
    private var aiSign = if (humanSign == 'X') '0' else 'X'
    private var difficulty = find<Menu>().selectedDifficulty.value

    private fun getNumberOfFreeMoves(): Int {
        var result = 0
        for (raw in board) {
            for (elem in raw) {
                if (elem == '_') {
                    result++
                }
            }
        }
        return result
    }

    private fun idToInt(buttonID: String): Pair<Int, Int> {
        val splitID = buttonID.split("-").map { it.toInt() }
        return Pair(splitID[0], splitID[1])
    }

    private fun updateButton(buttonID: String, isDisabled: Boolean) {
        val button = find<GameField>().root.lookup("#$buttonID")
        val id = idToInt(buttonID)
        val currentSign = if (board[id.first][id.second] == '_') ' ' else board[id.first][id.second]
        button.text(currentSign.toString())
        button.isDisable = isDisabled
        button.opacity = 1.0
    }

    private fun winHandling(winner: String) {
        gameStatus.value = "Status: $winner won"
        for (i in 0..2) {
            for (j in 0..2) {
                updateButton("$i-$j", true)
            }
        }
    }

    fun aiMoveHandling() {
        val winChecker = WinChecker
        val ai = AI(aiSign, humanSign, '_', difficulty)
        val move = ai.getMove(board)
        board[move.first][move.second] = aiSign
        val buttonID = "${move.first}-${move.second}"
        updateButton(buttonID, true)

        if (winChecker.isPlayerWinning(aiSign, board)) {
            winHandling("AI")
        }
    }

    fun humanMoveHandling(buttonID: String) {
        val winChecker = WinChecker
        val id = idToInt(buttonID)
        board[id.first][id.second] = humanSign
        updateButton(buttonID, true)

        if (winChecker.isPlayerWinning(humanSign, board)) {
            winHandling("human")
        } else if (getNumberOfFreeMoves() != 0) {
            aiMoveHandling()
        }
    }

    fun newGameHandling() {
        gameStatus.value = "Status: draw"
        humanSign = find<Menu>().selectedSign.value ?: 'X'
        aiSign = if (humanSign == 'X') '0' else 'X'
        difficulty = find<Menu>().selectedDifficulty.value

        for (i in 0..2) {
            for (j in 0..2) {
                board[i][j] = ' '
                updateButton("$i-$j", false)
                board[i][j] = '_'
            }
        }

        if (aiSign == 'X') {
            aiMoveHandling()
        }
    }
}
