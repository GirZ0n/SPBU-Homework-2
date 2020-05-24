package homeworks.homework7.task2.views

import homeworks.homework7.task2.controllers.GameFieldController
import homeworks.homework7.task2.styles.GameFieldStyle
import tornadofx.View
import tornadofx.vbox
import tornadofx.label
import tornadofx.addClass
import tornadofx.hbox
import tornadofx.button
import tornadofx.action

class GameField : View() {
    val controller: GameFieldController by inject()

    override fun onDock() {
        controller.newGameHandling()
        super.onDock()
    }

    override val root = vbox {
        addClass(GameFieldStyle.mainVbox)

        label(controller.gameStatus) { addClass(GameFieldStyle.statusBar) }

        hbox {
            addClass(GameFieldStyle.column)

            vbox {
                addClass(GameFieldStyle.row)

                button {
                    addClass(GameFieldStyle.gameButton)
                    id = "0-0"

                    action { controller.humanMoveHandling(id) }
                }

                button {
                    addClass(GameFieldStyle.gameButton)
                    id = "0-1"

                    action { controller.humanMoveHandling(id) }
                }

                button {
                    addClass(GameFieldStyle.gameButton)
                    id = "0-2"

                    action { controller.humanMoveHandling(id) }
                }
            }

            vbox {
                addClass(GameFieldStyle.row)

                button {
                    addClass(GameFieldStyle.gameButton)
                    id = "1-0"

                    action { controller.humanMoveHandling(id) }
                }

                button {
                    addClass(GameFieldStyle.gameButton)
                    id = "1-1"

                    action { controller.humanMoveHandling(id) }
                }

                button {
                    addClass(GameFieldStyle.gameButton)
                    id = "1-2"

                    action { controller.humanMoveHandling(id) }
                }
            }

            vbox {
                addClass(GameFieldStyle.row)

                button {
                    addClass(GameFieldStyle.gameButton)
                    id = "2-0"

                    action { controller.humanMoveHandling(id) }
                }

                button {
                    addClass(GameFieldStyle.gameButton)
                    id = "2-1"

                    action { controller.humanMoveHandling(id) }
                }

                button {
                    addClass(GameFieldStyle.gameButton)
                    id = "2-2"

                    action { controller.humanMoveHandling(id) }
                }
            }
        }

        button("Back to menu") {
            addClass(GameFieldStyle.menuButton)

            action {
                replaceWith<Menu>()
            }
        }
    }
}
