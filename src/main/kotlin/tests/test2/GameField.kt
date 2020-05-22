package tests.test2

import javafx.geometry.Pos
import javafx.scene.layout.VBox
import javafx.scene.text.FontWeight
import tornadofx.*

class GameField : View() {
    override val root = VBox()
    private val controller: GameFieldController by inject()
    val fieldSize = find<GameFieldController>().fieldSize

    init {
        for (i in 0 until fieldSize) {
            with(root) {
                this += hbox(alignment = Pos.CENTER)
            }
        }

        for (i in 0 until fieldSize) {
            for (j in 0 until fieldSize) {
                root.children[i] += button {
                    id = "$i$j"

                    style {
                        setPrefHeight(55.0)
                        setPrefWidth(55.0)
                        fontWeight = FontWeight.BOLD
                        fontSize = 5.mm
                    }

                    action { controller.buttonHandling(id) }
                }
            }
        }
    }
}
