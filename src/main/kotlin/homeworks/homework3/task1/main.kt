package homeworks.homework3.task1

fun main() {
    val testAVL = AVLSet<Int, String>()
    for (i in 1..10) {
        testAVL.add(i, "")
    }
    testAVL.printKeys()
}
