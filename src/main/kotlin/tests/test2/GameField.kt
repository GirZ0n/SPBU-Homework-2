package tests.test2

import javafx.geometry.Pos
import javafx.scene.control.Button
import javafx.scene.layout.HBox
import javafx.scene.layout.VBox
import tornadofx.View
import tornadofx.plusAssign
import tornadofx.action
import tornadofx.addClass

class GameField : View() {
    override val root = VBox()
    private val controller: GameFieldController by inject()
    val fieldSize = find<GameFieldController>().fieldSize

    init {
        for (i in 0 until fieldSize) {
            with(root) {
                this += HBox().apply { alignment = Pos.CENTER }
            }
        }

        for (i in 0 until fieldSize) {
            for (j in 0 until fieldSize) {
                root.children[i] += Button().apply {
                    id = "$i$j"

                    addClass(Styles.gameFieldButton)

                    action { controller.buttonHandling(id) }
                }
            }
        }
    }
}
