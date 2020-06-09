package homeworks.homework7.task1.model

object GameModel {
    var currentSign = 'X'

    fun changeSign() {
        currentSign = if (currentSign == 'X') '0' else 'X'
    }

    val board = arrayOf(
        arrayOf(' ', ' ', ' ').toCharArray(),
        arrayOf(' ', ' ', ' ').toCharArray(),
        arrayOf(' ', ' ', ' ').toCharArray()
    )

    fun clearBoard() {
        for (i in 0..2) {
            for (j in 0..2) {
                board[i][j] = ' '
            }
        }
    }

    var gameStatus = "Draw"
}
