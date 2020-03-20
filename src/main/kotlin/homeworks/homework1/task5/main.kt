package homeworks.homework1.task5

import java.io.File
import java.util.Scanner

fun countNonEmptyLines(input: File): Int {
    val scan = Scanner(input)
    var numberOfNonEmptyLines = 0
    while (scan.hasNextLine()) {
        if (!scan.nextLine().isBlank()) numberOfNonEmptyLines++
    }
    return numberOfNonEmptyLines
}

fun main() {
    val input = File("./src/main/kotlin/homeworks/homework1/task5/input.txt")
    if (!input.exists()) {
        println("Can't open the file")
        return
    } else
        println("The number of non-empty lines = ${countNonEmptyLines(input)}")
}