package homeworks.homework8.task1.styles

import javafx.geometry.Pos
import javafx.scene.text.Font
import javafx.scene.text.FontWeight
import tornadofx.Stylesheet
import tornadofx.cssclass
import tornadofx.mm

class MenuStyle : Stylesheet() {
    companion object {
        val gameName by cssclass()
        private const val GAME_NAME_FONT_SIZE = 30.0

        val playButton by cssclass()
        private const val PLAY_BUTTON_FONT_SIZE = 20.0

        val descriptionLabel by cssclass()
        private const val DESCRIPTION_LABEL_FONT_SIZE = 15.0

        val combobox by cssclass()
        private const val COMBOBOX_FONT_SIZE = 15.0

        val mainVbox by cssclass()
        private const val MAIN_VBOX_SPACING = 5

        val vboxForCombobox by cssclass()
        private const val VBOX_FOR_COMBOBOX_SPACING = 1

        val hboxForCombobox by cssclass()
        private const val HBOX_FOX_COMBOBOX_SAPCING = 5
    }

    init {
        gameName {
            font = Font.font(GAME_NAME_FONT_SIZE)
            fontWeight = FontWeight.BOLD
        }

        playButton {
            font = Font.font(PLAY_BUTTON_FONT_SIZE)
        }

        descriptionLabel {
            font = Font.font(DESCRIPTION_LABEL_FONT_SIZE)
            spacing = MAIN_VBOX_SPACING.mm
        }

        combobox {
            font = Font.font(COMBOBOX_FONT_SIZE)
        }

        mainVbox {
            spacing = MAIN_VBOX_SPACING.mm
            alignment = Pos.CENTER
        }

        vboxForCombobox {
            spacing = VBOX_FOR_COMBOBOX_SPACING.mm
            alignment = Pos.CENTER
        }

        hboxForCombobox {
            spacing = HBOX_FOX_COMBOBOX_SAPCING.mm
            alignment = Pos.CENTER
        }
    }
}
