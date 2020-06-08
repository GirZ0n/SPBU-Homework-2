package homeworks.homework7.task2.model

object GameModel {
    var humanSign = 'X'

    val aiSign
        get() = if (humanSign == 'X') '0' else 'X'

    val board = arrayOf(
        arrayOf(' ', ' ', ' ').toCharArray(),
        arrayOf(' ', ' ', ' ').toCharArray(),
        arrayOf(' ', ' ', ' ').toCharArray()
    )

    var difficulty = "Easy"
}
