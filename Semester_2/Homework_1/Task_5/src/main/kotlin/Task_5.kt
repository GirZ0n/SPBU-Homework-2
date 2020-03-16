import java.io.File
import java.util.*

fun countEmptyLines(input: File): Int {
    val scan = Scanner(input)
    var numberOfNonEmptyLines = 0
    while (scan.hasNextLine()) {
        if (!scan.nextLine().isBlank())
            numberOfNonEmptyLines++
    }
    return numberOfNonEmptyLines
}

fun main() {
    val input = File("./src/main/kotlin/input.txt")
    if (!input.exists()) {
        println("Cant open the file")
        return
    }
    else
        println("The number of non-empty lines = ${countEmptyLines(input)}")
}