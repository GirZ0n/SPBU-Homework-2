package homeworks.homework8.task1.model

import homeworks.homework8.task1.controllers.GameFieldController
import io.ktor.client.HttpClient
import io.ktor.client.features.websocket.WebSockets
import io.ktor.client.features.websocket.ws
import io.ktor.http.cio.websocket.Frame
import io.ktor.http.cio.websocket.WebSocketSession
import io.ktor.http.cio.websocket.close
import io.ktor.http.cio.websocket.readText
import io.ktor.util.KtorExperimentalAPI
import javafx.application.Platform
import kotlinx.coroutines.runBlocking
import java.util.concurrent.atomic.AtomicBoolean

private const val SLEEP_TIME = 1000L

class OnlineMode(private val controller: GameFieldController) : Thread() {
    private val gameModel = GameModel
    private val isNeedToSend = AtomicBoolean(false)
    private var messageToSend = "" // "move|closeSession" where 'closeSession' is Boolean
    private val isNeedToReceive = AtomicBoolean(false)

    fun sendMove(move: String, closeSession: Boolean = false) {
        messageToSend = "$move|$closeSession"
        isNeedToSend.set(true)
    }

    private suspend fun sendMoveHandling(socket: WebSocketSession) {
        if (isNeedToSend.getAndSet(false)) {
            println("Send: $messageToSend") // TODO: remove
            socket.send(Frame.Text(messageToSend))
            val closeSession = messageToSend.split("|")[1].toBoolean()
            if (closeSession) {
                socket.close()
            }
        }
    }

    private suspend fun receivedMessageHandling(socket: WebSocketSession) {
        if (isNeedToReceive.getAndSet(false)) {
            when (val frame = socket.incoming.receive()) {
                is Frame.Text -> {
                    val receivedMessage = frame.readText()
                    println("Received: $receivedMessage") // TODO: remove
                    Platform.runLater { controller.opponentMoveHandling(receivedMessage) }
                    val closeSession = receivedMessage.split("|")[1].toBoolean()
                    if (closeSession) {
                        socket.close()
                    }
                }
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
                        }
                    }
                }

                while (true) {
                    sendMoveHandling(this)

                    receivedMessageHandling(this)

                    // Pause the thread so that it waits for the player’s move
                    waitForPlayerMove()
                }
            }
        }
    }
}
