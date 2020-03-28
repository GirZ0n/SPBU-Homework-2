package homeworks.homework1.task3

import java.lang.IllegalArgumentException
import java.util.Scanner

fun getNumberOfOccurrences(source: String, substring: String): Int {
    require(source.isNotEmpty()) {"The source string mustn't be empty"}
    require(substring.isNotEmpty()) {"The substring mustn't be empty"}

    var answer = 0
    val sourceLength = source.length
    val substringLength = substring.length

    for (i in 0 until sourceLength - substringLength + 1) {
        if (source.slice(i until i + substringLength) == substring) answer++
    }

    return answer
}

fun main() {
    val scan = Scanner(System.`in`)
    println("Enter the string:")
    val inputString = scan.nextLine()
    println("Enter the substring:")
    val substring = scan.nextLine()
    try {
        println("The number of occurrences = ${getNumberOfOccurrences(inputString, substring)}")
    } catch (exception: IllegalArgumentException) {
        println(exception)
    }
}
