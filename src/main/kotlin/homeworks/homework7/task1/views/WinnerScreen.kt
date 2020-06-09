package homeworks.homework7.task1.views

import homeworks.homework7.task1.model.GameModel
import homeworks.homework7.task1.styles.GameFieldStyle
import javafx.beans.property.SimpleStringProperty
import tornadofx.View
import tornadofx.addClass
import tornadofx.label
import tornadofx.vbox
import tornadofx.button
import tornadofx.action

class WinnerScreen : View() {
    private val gameResult = SimpleStringProperty("Draw")

    override fun onDock() {
        gameResult.value = GameModel.gameStatus
        super.onDock()
    }

    override val root = vbox {
        addClass(GameFieldStyle.mainVbox)

        label(gameResult) { addClass(GameFieldStyle.statusBar) }

        button("Restart") {
            addClass(GameFieldStyle.restartButton)
            action { replaceWith<GameField>() }
        }
    }
}
