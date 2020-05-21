package homeworks.homework7.task2

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
        private val MAIN_VBOX_SPACING_VALUE = 5.mm

        val vboxForCombobox by cssclass()
        private val VBOX_FOR_COMBOBOX_SPACING_VALUE = 1.mm

        val hboxForCombobox by cssclass()
        private val HBOX_FOX_COMBOBOX_SAPCING_VALUE = 5.mm
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
            spacing = MAIN_VBOX_SPACING_VALUE
        }

        combobox {
            font = Font.font(COMBOBOX_FONT_SIZE)
        }

        mainVbox {
            spacing = MAIN_VBOX_SPACING_VALUE
            alignment = Pos.CENTER
        }

        vboxForCombobox {
            spacing = VBOX_FOR_COMBOBOX_SPACING_VALUE
            alignment = Pos.CENTER
        }

        hboxForCombobox {
            spacing = HBOX_FOX_COMBOBOX_SAPCING_VALUE
            alignment = Pos.CENTER
        }
    }
}
