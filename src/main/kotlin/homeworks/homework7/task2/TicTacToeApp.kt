package homeworks.homework7.task2

import javafx.stage.Stage
import tornadofx.App
import tornadofx.launch

private const val STAGE_HEIGHT = 300.0
private const val STAGE_WIDTH = 300.0

class TicTacToeApp : App(Menu::class) {
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
