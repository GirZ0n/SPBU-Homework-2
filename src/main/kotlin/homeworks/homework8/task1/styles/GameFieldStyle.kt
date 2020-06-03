package homeworks.homework8.task1.styles

import javafx.geometry.Pos
import javafx.scene.text.Font
import javafx.scene.text.FontWeight
import tornadofx.Stylesheet
import tornadofx.cssclass
import tornadofx.mm

class GameFieldStyle : Stylesheet() {
    companion object {
        val mainVbox by cssclass()
        private const val MAIN_VBOX_SPACING = 5

        val statusBar by cssclass()
        private const val STATUS_BAR_FONT_SIZE = 20.0

        val column by cssclass()
        private const val COLUMN_SPACING = 5

        val row by cssclass()
        private const val ROW_SPACING = 5

        val menuButton by cssclass()
        private const val MENU_BUTTON_FONT_SIZE = 15.0

        val gameButton by cssclass()
        private const val HEIGHT = 15
        private const val WIDTH = HEIGHT
        private const val GAME_BUTTON_FONT_SIZE = 20.0
    }

    init {
        mainVbox {
            spacing = MAIN_VBOX_SPACING.mm
            alignment = Pos.CENTER
        }

        statusBar {
            font = Font.font(STATUS_BAR_FONT_SIZE)
            fontWeight = FontWeight.BOLD
        }

        column {
            spacing = COLUMN_SPACING.mm
            alignment = Pos.CENTER
        }

        row {
            spacing = ROW_SPACING.mm
            alignment = Pos.CENTER
        }

        menuButton {
            font = Font.font(MENU_BUTTON_FONT_SIZE)
        }

        gameButton {
            prefHeight = HEIGHT.mm
            prefWidth = WIDTH.mm
            font = Font.font(GAME_BUTTON_FONT_SIZE)
            fontWeight = FontWeight.BOLD
        }
    }
}
