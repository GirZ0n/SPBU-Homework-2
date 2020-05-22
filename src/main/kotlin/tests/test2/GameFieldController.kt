package tests.test2

import tornadofx.*

class GameFieldController : Controller() {
    val fieldCreator = FieldCreator
    val field by lazy { fieldCreator.createField(fieldSize) }
    var fieldSize: Int = find<Menu>().size.value

    var idOfFirstButtonFromPair: String? = null
    var firstButtonText = ""
    var idOfSecondButtonFromPair: String? = null
    var secondButtonText = ""
    var isNeedToClosePair = false

    fun buttonHandling(buttonId: String) {
        if (isNeedToClosePair) {
            val firstButton = find<GameField>().root.lookup("#$idOfFirstButtonFromPair")
            val secondButton = find<GameField>().root.lookup("#$idOfSecondButtonFromPair")

            firstButton.text("")
            firstButton.isDisable = false
            secondButton.text("")
            secondButton.isDisable = false

            idOfFirstButtonFromPair = null
            firstButtonText = ""
            idOfSecondButtonFromPair = null
            secondButtonText = ""
            isNeedToClosePair = false
        }

        val currentButton = find<GameField>().root.lookup("#$buttonId")
        val i = buttonId[0].toString().toInt()
        val j = buttonId[1].toString().toInt()
        val currentButtonText = field[i][j].toString()
        currentButton.text(currentButtonText)
        currentButton.isDisable = true
        currentButton.opacity = 1.0

        idOfFirstButtonFromPair?.let {
            if (firstButtonText == currentButtonText) {
                idOfFirstButtonFromPair = null
                firstButtonText = ""
                isNeedToClosePair = false
            } else {
                idOfSecondButtonFromPair = buttonId
                secondButtonText = field[i][j].toString()
                isNeedToClosePair = true
            }
        } ?: run {
            idOfFirstButtonFromPair = buttonId
            firstButtonText = currentButtonText
        }
    }
}
