package tests.test2

import javafx.beans.property.SimpleIntegerProperty
import tornadofx.View
import tornadofx.action
import tornadofx.vbox
import tornadofx.addClass
import tornadofx.button
import tornadofx.label
import tornadofx.textfield

class Menu : View() {
    var size = SimpleIntegerProperty()
    override val root = vbox {
        addClass(Styles.menuHBox)

        label("Enter size of game field")

        textfield(size)

        button("play") {
            action { replaceWith<GameField>() }
        }
    }
}
