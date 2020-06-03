package homeworks.homework8.task1.controllers

import homeworks.homework8.task1.model.AI
import homeworks.homework8.task1.model.GameModel
import homeworks.homework8.task1.model.OnlineMode
import homeworks.homework8.task1.model.WinChecker
import homeworks.homework8.task1.views.GameField
import io.ktor.util.KtorExperimentalAPI
import javafx.beans.property.SimpleStringProperty
import tornadofx.Controller
import tornadofx.text

class GameFieldController : Controller() {
    private val gameModel = GameModel
    var gameStatus = SimpleStringProperty("Status: draw")
    var moveStatus = SimpleStringProperty("")
    private val onlineMode = OnlineMode(this)

    private fun idToInt(buttonID: String): Pair<Int, Int> {
        val splitID = buttonID.split("-").map { it.toInt() }
        return Pair(splitID[0], splitID[1])
    }

    private fun updateButton(buttonID: String, isDisable: Boolean) {
        val button = find<GameField>().root.lookup("#$buttonID")
        val id = idToInt(buttonID)
        val currentSign = gameModel.board[id.first][id.second]
        button.text(currentSign.toString())
        button.isDisable = if (currentSign.toString().isBlank()) isDisable else true
        button.opacity = 1.0
    }

    private fun updateAllButtons(isDisable: Boolean) {
        for (i in 0..2) {
            for (j in 0..2) {
                updateButton("$i-$j", isDisable)
            }
        }
    }

    private fun winHandling(winnerSign: Char) {
        gameStatus.value = "Status: $winnerSign won"
        moveStatus.value = ""
        updateAllButtons(isDisable = true)
    }

    fun opponentMoveHandling(move: String) {
        val id = idToInt(move)
        gameModel.board[id.first][id.second] = gameModel.opponentSign
        updateAllButtons(isDisable = false)
        moveStatus.value = "Your move"

        val winChecker = WinChecker
        if (winChecker.isPlayerWinning(gameModel.opponentSign, gameModel.board)) {
            winHandling(gameModel.opponentSign)
        }
    }

    private fun aiMoveHandling() {
        val winChecker = WinChecker
        val ai = AI(gameModel.opponentSign, gameModel.playerSign, ' ', gameModel.difficulty)
        val move = ai.getMove(gameModel.board)
        if (move == Pair(-1, -1)) {
            return
        }
        gameModel.board[move.first][move.second] = gameModel.opponentSign
        val buttonID = "${move.first}-${move.second}"
        updateButton(buttonID, isDisable = true)

        if (winChecker.isPlayerWinning(gameModel.opponentSign, gameModel.board)) {
            winHandling(gameModel.opponentSign)
        }
    }

    fun playerMoveHandling(buttonID: String) {
        val winChecker = WinChecker
        val id = idToInt(buttonID)
        gameModel.board[id.first][id.second] = gameModel.playerSign
        updateButton(buttonID, isDisable = true)

        when (gameModel.gameMode) {
            "Single-player" -> {
                if (winChecker.isPlayerWinning(gameModel.playerSign, gameModel.board)) {
                    winHandling(gameModel.playerSign)
                } else {
                    aiMoveHandling()
                }
            }
            "Multi-player" -> {
                onlineMode.sendMove(buttonID)
                updateAllButtons(isDisable = true)
                moveStatus.value = "Wait for opponent move"
                if (winChecker.isPlayerWinning(gameModel.playerSign, gameModel.board)) {
                    winHandling(gameModel.playerSign)
                }
            }
        }
    }

    fun newGameHandling() {
        gameStatus.value = "Status: draw"

        onlineMode.start()

        for (i in 0..2) {
            for (j in 0..2) {
                gameModel.board[i][j] = ' '
                updateButton("$i-$j", isDisable = true)
            }
        }

        if (gameModel.opponentSign == 'X') {
            aiMoveHandling()
        }
    }
}
