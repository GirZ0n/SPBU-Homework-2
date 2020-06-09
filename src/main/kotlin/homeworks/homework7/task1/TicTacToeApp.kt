package homeworks.homework7.task1

import homeworks.homework7.task1.styles.GameFieldStyle
import homeworks.homework7.task1.views.GameField
import javafx.stage.Stage
import tornadofx.App
import tornadofx.launch

class TicTacToeApp : App(GameField::class, GameFieldStyle::class) {
    companion object {
        private const val STAGE_HEIGHT = 400.0
        private const val STAGE_WIDTH = 400.0
    }

    override fun start(stage: Stage) {
        stage.height = STAGE_HEIGHT
        stage.width = STAGE_WIDTH
        stage.isResizable = false
        super.start(stage)
    }
}

fun main() {
    launch<TicTacToeApp>()
}
