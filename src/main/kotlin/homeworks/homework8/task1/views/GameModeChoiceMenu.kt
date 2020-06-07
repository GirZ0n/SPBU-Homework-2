package homeworks.homework8.task1.views

import homeworks.homework8.task1.model.GameModel
import homeworks.homework8.task1.styles.MenuStyle
import javafx.beans.property.SimpleStringProperty
import javafx.collections.FXCollections
import javafx.collections.ObservableList
import tornadofx.View
import tornadofx.action
import tornadofx.addClass
import tornadofx.button
import tornadofx.combobox
import tornadofx.label
import tornadofx.vbox

class GameModeChoiceMenu : View() {
    private val gameModeList: ObservableList<String> =
        FXCollections.observableArrayList("Single-player", "Multiplayer")
    private val selectedGameMode = SimpleStringProperty()

    override val root = vbox {
        addClass(MenuStyle.mainVbox)

        label("Tic-tac-toe (v3)") { addClass(MenuStyle.gameName) }

        label("Game mode:").addClass(MenuStyle.descriptionLabel)

        combobox(selectedGameMode, gameModeList) {
            addClass(MenuStyle.combobox)
            selectionModel.selectFirst()
        }

        button("Next") {
            addClass(MenuStyle.playButton)
            action {
                GameModel.gameMode = selectedGameMode.value
                when (selectedGameMode.value) {
                    "Single-player" -> replaceWith<SinglePlayerMenu>()
                    else -> replaceWith<MultiplayerMenu>()
                }
            }
        }
    }
}
