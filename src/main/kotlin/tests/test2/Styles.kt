package tests.test2

import javafx.geometry.Pos
import javafx.scene.text.Font
import javafx.scene.text.FontWeight
import tornadofx.Stylesheet
import tornadofx.cssclass
import tornadofx.mm

class Styles : Stylesheet() {
    companion object {
        val menuHBox by cssclass()
        private const val MENU_HBOX_SPACING = 10

        val gameFieldButton by cssclass()
        private const val GAME_FIELD_BUTTON_HEIGHT = 15
        private const val GAME_FIELD_BUTTON_WIDTH = GAME_FIELD_BUTTON_HEIGHT
        private const val GAME_FIELD_BUTTON_FONT_SIZE = 20.0
    }

    init {
        menuHBox {
            spacing = MENU_HBOX_SPACING.mm
            alignment = Pos.CENTER
        }

        gameFieldButton {
            prefWidth = GAME_FIELD_BUTTON_WIDTH.mm
            prefHeight = GAME_FIELD_BUTTON_HEIGHT.mm
            font = Font.font(GAME_FIELD_BUTTON_FONT_SIZE)
            fontWeight = FontWeight.BOLD
        }
    }
}
