package homeworks.homework7.task2.views

import homeworks.homework7.task2.styles.MenuStyle
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

class Menu : View("Tic-tac-toe (v2)") {
    private val difficultyList: ObservableList<String> = FXCollections.observableArrayList("Easy", "Medium", "Hard")
    val selectedDifficulty = SimpleStringProperty()

    private val playerSignList: ObservableList<Char> = FXCollections.observableArrayList('X', '0')
    val selectedSign = SimpleObjectProperty<Char>()

    override fun onDock() {
        selectedSign.value = 'X'
        selectedDifficulty.value = "Easy"
        super.onDock()
    }

    override val root = vbox {
        addClass(MenuStyle.mainVbox)

        label("Tic-tac-toe (v2)") { addClass(MenuStyle.gameName) }

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
            action { replaceWith<GameField>() }
        }
    }
}
