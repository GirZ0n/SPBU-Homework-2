package tests.test2

import tornadofx.App
import tornadofx.launch

class MyApp : App(Menu::class, Styles::class)

fun main(args: Array<String>) {
    launch<MyApp>(args)
}
