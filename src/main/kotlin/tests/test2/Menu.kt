package tests.test2

import javafx.beans.property.SimpleIntegerProperty
import javafx.geometry.Pos
import tornadofx.*

class Menu : View() {
    var size = SimpleIntegerProperty()
    override val root = vbox (10, Pos.CENTER) {
        label("Enter size of game field")

        textfield(size)

        button("play") {
            action {replaceWith<GameField>()}
        }
    }
}
