package homeworks.homework7.task2.controllers

import homeworks.homework7.task2.views.Menu
import homeworks.homework7.task2.model.WinChecker
import homeworks.homework7.task2.views.GameField
import tornadofx.Controller
import tornadofx.lookup
import tornadofx.text

class GameFieldController : Controller() {
    private val board = arrayOf(
        arrayOf('_', '_', '_').toCharArray(),
        arrayOf('_', '_', '_').toCharArray(),
        arrayOf('_', '_', '_').toCharArray()
    )
    val winChecker = WinChecker
    var gameStatus = "draw"
    private val humanSign = find<Menu>().selectedSign.value ?: 'X'
    private val aiSign = if (humanSign == 'X') '0' else 'X'
    private val difficulty = when (find<Menu>().selectedDifficulty.value) {
        "Easy" -> 0
        "Medium" -> 1
        "Hard" -> 2
        else -> 0
    }

    private fun updateAndBlockButton(buttonId: String) {
        val button = find<GameField>().root.lookup("#$buttonId")
        button.text()
    }

    fun humanMoveHandling(rowIndex: Int, columnIndex: Int) {
        board[rowIndex][columnIndex] = humanSign
        updateAndBlockButton("${rowIndex}-${columnIndex}")
        if (winChecker.isPlayerWinning(humanSign, board)) {

        }
    }
}
