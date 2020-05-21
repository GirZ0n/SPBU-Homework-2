package homeworks.homework7.task2

import javafx.beans.property.SimpleStringProperty
import javafx.collections.FXCollections
import javafx.collections.ObservableList
import javafx.geometry.Pos
import javafx.scene.text.Font
import tornadofx.View
import tornadofx.vbox
import tornadofx.hbox
import tornadofx.label
import tornadofx.combobox
import tornadofx.button
import tornadofx.action

private const val SPACING = 10
private const val FONT_SIZE = 30.0

class Menu : View() {
    val difficultyList: ObservableList<String> = FXCollections.observableArrayList("Easy", "Medium", "Hard")
    val playerSignList: ObservableList<String> = FXCollections.observableArrayList("X", "0")
    val selectedDifficulty = SimpleStringProperty()
    val selectedSign = SimpleStringProperty()

    override val root = vbox(SPACING, Pos.CENTER) {
        label("Tic-tac-toe (v2)") {
            font = Font.font(FONT_SIZE)
        }

        hbox(SPACING, Pos.CENTER) {
            vbox(SPACING) {
                label("Difficulty:")
                combobox(selectedDifficulty, difficultyList) {
                    selectionModel.selectFirst()
                }
            }

            vbox(SPACING) {
                label("Your sign:")
                combobox(selectedSign, playerSignList) {
                    selectionModel.selectFirst()
                }
            }
        }

        button("Play") {
            action {
                replaceWith<GameField>()
            }
        }
    }
}
