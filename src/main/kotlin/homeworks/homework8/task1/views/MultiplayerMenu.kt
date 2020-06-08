package homeworks.homework8.task1.views

import homeworks.homework8.task1.model.GameModel
import homeworks.homework8.task1.styles.MenuStyle
import javafx.beans.property.SimpleObjectProperty
import javafx.collections.FXCollections
import javafx.collections.ObservableList
import tornadofx.View
import tornadofx.action
import tornadofx.addClass
import tornadofx.button
import tornadofx.combobox
import tornadofx.label
import tornadofx.vbox

class MultiplayerMenu : View() {
    private val playerSignList: ObservableList<Char> = FXCollections.observableArrayList('X', '0')
    private val selectedSign = SimpleObjectProperty<Char>()

    override val root = vbox {
        addClass(MenuStyle.mainVbox)

        label("Your sign:").addClass(MenuStyle.descriptionLabel)

        combobox(selectedSign, playerSignList) {
            addClass(MenuStyle.combobox)
            selectionModel.selectFirst()
        }

        button("Play") {
            addClass(MenuStyle.playButton)
            action {
                GameModel.playerSign = selectedSign.value
                replaceWith<GameField>()
            }
        }
    }
}
