package homeworks.homework8.task1.views

import homeworks.homework8.task1.model.GameModel
import homeworks.homework8.task1.styles.GameFieldStyle
import homeworks.homework8.task1.styles.MenuStyle
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
        gameResult.value = GameModel.winner
        super.onDock()
    }

    override val root = vbox {
        addClass(MenuStyle.mainVbox)

        label(gameResult) { addClass(GameFieldStyle.statusBar) }

        button("Back to menu") {
            addClass(GameFieldStyle.menuButton)
            action { replaceWith<GameModeChoiceMenu>() }
        }
    }
}
