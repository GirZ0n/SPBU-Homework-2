package homeworks.homework8.task1.views

import homeworks.homework8.task1.model.GameModel
import homeworks.homework8.task1.styles.MenuStyle
import javafx.beans.property.SimpleObjectProperty
import javafx.beans.property.SimpleStringProperty
import javafx.collections.FXCollections
import javafx.collections.ObservableList
import tornadofx.View
import tornadofx.vbox
import tornadofx.label
import tornadofx.addClass
import tornadofx.hbox
import tornadofx.combobox
import tornadofx.button
import tornadofx.action

class SinglePlayerMenu : View("Tic-tac-toe (v2)") {
    private val difficultyList: ObservableList<String> = FXCollections.observableArrayList("Easy", "Medium", "Hard")
    val selectedDifficulty = SimpleStringProperty()

    private val playerSignList: ObservableList<Char> = FXCollections.observableArrayList('X', '0')
    val selectedSign = SimpleObjectProperty<Char>()

    override val root = vbox {
        addClass(MenuStyle.mainVbox)

        hbox {
            addClass(MenuStyle.hboxForCombobox)

            vbox {
                addClass(MenuStyle.vboxForCombobox)

                label("Difficulty:").addClass(MenuStyle.descriptionLabel)

                combobox(selectedDifficulty, difficultyList) {
                    addClass(MenuStyle.combobox)
                    selectionModel.selectFirst()
                }
            }

            vbox {
                addClass(MenuStyle.vboxForCombobox)

                label("Your sign:").addClass(MenuStyle.descriptionLabel)

                combobox(selectedSign, playerSignList) {
                    addClass(MenuStyle.combobox)
                    selectionModel.selectFirst()
                }
            }
        }

        button("Play") {
            addClass(MenuStyle.playButton)
            action {
                GameModel.difficulty = selectedDifficulty.value
                GameModel.playerSign = selectedSign.value
                replaceWith<GameField>()
            }
        }
    }
}
