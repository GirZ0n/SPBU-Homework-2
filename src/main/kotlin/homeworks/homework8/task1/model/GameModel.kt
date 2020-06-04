package homeworks.homework8.task1.model

object GameModel {
    var playerSign = 'X'

    val opponentSign
        get() = if (playerSign == 'X') '0' else 'X'

    val board = arrayOf(
        arrayOf(' ', ' ', ' ').toCharArray(),
        arrayOf(' ', ' ', ' ').toCharArray(),
        arrayOf(' ', ' ', ' ').toCharArray()
    )

    var difficulty = "Easy"

    var gameMode = "Single-player"

    var winner = "Draw"

    var isFirstOnlineGame = true
}
