package tests.test2

import javafx.stage.Stage
import tornadofx.App
import tornadofx.launch

class MyApp : App(Menu::class)

fun main(args: Array<String>) {
    launch<MyApp>(args)
}
