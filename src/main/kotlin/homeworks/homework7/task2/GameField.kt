package homeworks.homework7.task2

import tornadofx.View
import tornadofx.action
import tornadofx.button

class GameField : View() {
    override val root = button("Menu") {
        action {
            replaceWith<Menu>()
        }
    }
}
