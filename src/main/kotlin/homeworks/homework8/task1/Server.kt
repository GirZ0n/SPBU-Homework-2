package homeworks.homework8.task1

import homeworks.homework8.task1.model.WinChecker
import io.ktor.application.Application
import io.ktor.application.install
import io.ktor.http.cio.websocket.Frame
import io.ktor.http.cio.websocket.WebSocketSession
import io.ktor.http.cio.websocket.readText
import io.ktor.routing.routing
import io.ktor.server.engine.embeddedServer
import io.ktor.server.netty.Netty
import io.ktor.util.KtorExperimentalAPI
import io.ktor.websocket.WebSockets
import io.ktor.websocket.webSocket
import java.util.Collections
import java.util.concurrent.atomic.AtomicInteger
import kotlin.collections.LinkedHashSet

@KtorExperimentalAPI
fun main() {
    val server = embeddedServer(Netty, port = 8080) {
        mainModule()
    }
    server.start(wait = true)
}

@KtorExperimentalAPI
private fun Application.mainModule() {
    val gameBoard = arrayOf(
        arrayOf(' ', ' ', ' ').toCharArray(),
        arrayOf(' ', ' ', ' ').toCharArray(),
        arrayOf(' ', ' ', ' ').toCharArray()
    )
    var firstPlayerSign = ' '

    install(WebSockets)
    routing {
        val players = Collections.synchronizedSet(LinkedHashSet<Player>())
        webSocket("/") {

            // New player handling
            // Здесь происходит получение знака нового игрока, а также проверка этого знака на корректность выбора
            // Если игрок получил знак '0', то он ходит вторым, поэтому для корректной работы я отправляю ему сообщение
            // "No one won"
            val player = Player(this)
            when (val frame = incoming.receive()) {
                is Frame.Text -> {
                    val receivedSign = frame.readText()
                    if (players.isEmpty()) {
                        firstPlayerSign = receivedSign[0] // Convert String to Char
                        player.session.outgoing.send(Frame.Text(receivedSign))
                        player.sign = firstPlayerSign
                        if (receivedSign == "0") {
                            player.session.outgoing.send(Frame.Text("No one won"))
                        }
                    } else {
                        val opponentSign = if (firstPlayerSign == 'X') '0' else 'X'
                        player.session.outgoing.send(Frame.Text(opponentSign.toString()))
                        player.sign = opponentSign
                        if (opponentSign == '0') {
                            player.session.outgoing.send(Frame.Text("No one won"))
                        }
                    }
                }
            }
            players += player

            // Handles player requests
            try {
                while (true) {
                    // Получаю ход игрока
                    var playerMove = ""
                    when (val frame = incoming.receive()) {
                        is Frame.Text -> {
                            playerMove = frame.readText() // "i-j"
                        }
                    }

                    updateBoard(player, playerMove, gameBoard)

                    val gameStatus = getGameStatus(player, gameBoard)

                    // Отправляю cтатус игры и ход оппоненту
                    sendMoveAndGameStatus(player, playerMove, gameStatus, players)
                }
            } finally {
                players -= player
                firstPlayerSign = ' '
                clearBoard(gameBoard)
            }
        }
    }
}

private fun clearBoard(gameBoard: Array<CharArray>) {
    for (i in 0..2) {
        for (j in 0..2) {
            gameBoard[i][j] = ' '
        }
    }
}

private fun isFreeMoves(gameBoard: Array<CharArray>): Boolean {
    for (i in 0..2) {
        for (j in 0..2) {
            if (gameBoard[i][j] == ' ') {
                return true
            }
        }
    }
    return false
}

@KtorExperimentalAPI
private class Player(val session: WebSocketSession) {
    companion object {
        var lastId = AtomicInteger(0)
    }

    private val id = lastId.getAndIncrement()
    val name = "user$id"

    var sign = ' '
}

@KtorExperimentalAPI
private fun getGameStatus(player: Player, gameBoard: Array<CharArray>): String {
    val winChecker = WinChecker
    return when {
        winChecker.isPlayerWinning(player.sign, gameBoard) -> "${player.sign} won"
        isFreeMoves(gameBoard) -> "No one won"
        else -> "Draw"
    }
}

@KtorExperimentalAPI
private fun updateBoard(player: Player, playerMove: String, gameBoard: Array<CharArray>) {
    val splitID = playerMove.split("-").map { it.toInt() }
    gameBoard[splitID[0]][splitID[1]] = player.sign
}

@KtorExperimentalAPI
private suspend fun sendMoveAndGameStatus(
    currentPlayer: Player,
    playerMove: String,
    gameStatus: String,
    players: MutableSet<Player>
) {
    // Отправляю статус игры текущему игроку
    currentPlayer.session.outgoing.send(Frame.Text(gameStatus))
    for (other in players) {
        if (other != currentPlayer) {
            // Отправляю ход оппоненту
            other.session.outgoing.send(Frame.Text(playerMove))
            // Отправляю оппоненту статус игры
            other.session.outgoing.send(Frame.Text(gameStatus))
        }
    }
}
