import java.io.File
import java.util.*
import kotlin.system.exitProcess

fun isSpecials(input: Char): Boolean {
    return (input == ' ') || (input == '\n') || (input == '\t')
}

fun isEmpty(string: String): Boolean {
    for (i in string.indices) {
        if (!isSpecials(string[i]))
            return false
    }
    return true
}

fun countEmptyLines(input: File): Int {
    val scan = Scanner(input)
    var line: String
    var numberOfNonEmptyLines = 0
    while (scan.hasNextLine()) {
        line = scan.nextLine()
        if (!isEmpty(line))
            numberOfNonEmptyLines++
    }
    return numberOfNonEmptyLines
}

fun main() {
    val input = File("input.txt")
    if (!input.exists()) {
        println("Cant open the file")
        exitProcess(0)
    }
    else
        println("The number of non-empty lines = ${countEmptyLines(input)}")
}