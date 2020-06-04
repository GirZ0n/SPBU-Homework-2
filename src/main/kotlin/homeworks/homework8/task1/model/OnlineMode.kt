package homeworks.homework8.task1.model

import homeworks.homework8.task1.controllers.GameFieldController
import io.ktor.client.HttpClient
import io.ktor.client.features.websocket.WebSockets
import io.ktor.client.features.websocket.ws
import io.ktor.http.cio.websocket.Frame
import io.ktor.http.cio.websocket.WebSocketSession
import io.ktor.http.cio.websocket.close
import io.ktor.http.cio.websocket.readText
import io.ktor.http.websocket.websocketServerAccept
import io.ktor.util.KtorExperimentalAPI
import javafx.application.Platform
import kotlinx.coroutines.isActive
import kotlinx.coroutines.runBlocking
import java.util.concurrent.atomic.AtomicBoolean

private const val SLEEP_TIME = 1000L

class OnlineMode(private val controller: GameFieldController) : Thread() {
    private val gameModel = GameModel
    private val isNeedToSend = AtomicBoolean(false)
    private var moveToSend = ""
    private val isNeedToReceive = AtomicBoolean(false)

    fun sendMove(move: String) {
        moveToSend = move
        isNeedToSend.set(true)
    }

    private suspend fun sendMoveHandling(socket: WebSocketSession) {
        if (isNeedToSend.getAndSet(false)) {
            println("Send: $moveToSend") // TODO: remove
            socket.send(Frame.Text(moveToSend))
            isNeedToReceive.set(true)
        }
    }

    // gameStatus ("X won", "0 won", "Draw", "No one won") shows who won
    private suspend fun receiveGameStatus(socket: WebSocketSession): String {
        when (val frame = socket.incoming.receive()) {
            is Frame.Text -> {
                val gameStatus = frame.readText()
                println("Received: $gameStatus") // TODO: remove
                return gameStatus
            }
        }
        return ""
    }

    private suspend fun receivedMoveHandling(socket: WebSocketSession) {
        when (val frame = socket.incoming.receive()) {
            is Frame.Text -> {
                val receivedMessage = frame.readText()
                println("Received: $receivedMessage") // TODO: remove
                Platform.runLater { controller.opponentMoveHandling(receivedMessage) }
            }
        }
    }

    private suspend fun receivedMessagesHandling(socket: WebSocketSession) {
        if (isNeedToReceive.getAndSet(false)) {
            val firstGameStatus = receiveGameStatus(socket)
            if (firstGameStatus == "No one won") {
                // if the player did not win

                receivedMoveHandling(socket)

                val secondGameStatus = receiveGameStatus(socket)
                if (secondGameStatus != "No one won") {
                    // if the opponent won
                    println("close1") // TODO: remove
                    Platform.runLater { controller.endGameHandling(secondGameStatus) }
                    socket.close()
                }
            } else {
                // if the player won
                println("close2") // TODO: remove
                Platform.runLater { controller.endGameHandling(firstGameStatus) }
                socket.close()
            }
        }
    }

    private fun waitForPlayerMove() = Thread.sleep(SLEEP_TIME)

    @KtorExperimentalAPI
    override fun run() {
        runBlocking {
            val client = HttpClient { install(WebSockets) }
            client.ws(method = io.ktor.http.HttpMethod.Get, port = 8080, host = "127.0.0.1", path = "/") {

                // We send the sign selected by the player (X or 0)
                send(Frame.Text("${GameModel.playerSign}"))

                // We get X or 0, depending on the choice of the previous player
                when (val frame = incoming.receive()) {
                    is Frame.Text -> {
                        val sign = frame.readText()[0] // Convert string to char
                        gameModel.playerSign = sign
                        if (sign == '0') {
                            isNeedToReceive.set(true)
                        } else {
                            Platform.runLater { controller.updateAllButtons(false) }
                        }
                    }
                }

                while (isActive) {
                    sendMoveHandling(this)

                    receivedMessagesHandling(this)

                    // Pause the while loop so that it waits for the player’s move
                    waitForPlayerMove()
                }
            }
            println("123")
        }
    }
}
