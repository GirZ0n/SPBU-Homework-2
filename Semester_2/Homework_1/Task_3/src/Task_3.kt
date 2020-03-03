import java.util.*

fun areEqual(source: String, substring: String, index: Int): Boolean {
    for (i in substring.indices) {
        if (source[index + i] != substring[i])
            return false
    }
    return true
}

fun getNumberOfOccurrences(source: String, substring: String): Int {
    var answer = 0
    val sourceLength = source.length
    val substringLength = substring.length

    for (i in 0 until sourceLength - substringLength + 1) {
        if (areEqual(source, substring, i))
            answer++
    }

    return answer
}

fun main() {
    val scan = Scanner(System.`in`)
    println("Enter the string:")
    val inputString = scan.nextLine()
    println("Enter the substring:")
    val substring = scan.nextLine()
    println("The number of occurrences = ${getNumberOfOccurrences(inputString, substring)}")
}