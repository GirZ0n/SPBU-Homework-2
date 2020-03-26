package homeworks.homework1.task5

import java.io.File
import java.io.FileNotFoundException
import java.util.Scanner

fun countNonEmptyLines(input: File): Int {
    if (!input.exists()) throw FileNotFoundException("Can't open the file")

    val scan = Scanner(input)
    var numberOfNonEmptyLines = 0
    while (scan.hasNextLine()) {
        if (!scan.nextLine().isBlank()) numberOfNonEmptyLines++
    }
    return numberOfNonEmptyLines
}

fun main() {
    val input = File("./src/main/kotlin/homeworks/homework1/task5/input.txt")
    try {
        println("The number of non-empty lines = ${countNonEmptyLines(input)}")
    } catch (exception: FileNotFoundException) {
        println(exception)
    }
}
