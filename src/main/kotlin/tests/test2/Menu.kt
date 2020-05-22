package tests.test2

import javafx.beans.property.SimpleIntegerProperty
import tornadofx.*

class Menu : View() {
    var size = SimpleIntegerProperty()
    override val root = vbox {
        label("Enter size of game field")

        textfield(size)

        button("play") {
            action {replaceWith<GameField>()}
        }
    }
}
