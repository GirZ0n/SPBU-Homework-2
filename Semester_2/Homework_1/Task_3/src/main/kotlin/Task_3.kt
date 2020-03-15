import java.util.*

fun getNumberOfOccurrences(source: String, substring: String): Int {
    var answer = 0
    val sourceLength = source.length
    val substringLength = substring.length

    for (i in 0 until sourceLength - substringLength + 1) {
        if (source.slice(i until i + substringLength) == substring)
            answer++
    }

    return if (substringLength == 0) 0 else answer
}

fun main() {
    val scan = Scanner(System.`in`)
    println("Enter the string:")
    val inputString = scan.nextLine()
    println("Enter the substring:")
    val substring = scan.nextLine()
    println("The number of occurrences = ${getNumberOfOccurrences(inputString, substring)}")
}