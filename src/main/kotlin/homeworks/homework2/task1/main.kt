package homeworks.homework2.task1

import java.lang.IllegalArgumentException
import java.util.Scanner

fun countXToBeDeleted(inputString: String): Int {
    require(inputString.isNotEmpty()) { "The inputString mustn't be empty" }

    var answer = 0
    var sequenceLength = 0

    for (element in inputString) {
        if (element == 'x') sequenceLength++
        else {
            answer += if (sequenceLength > 2) sequenceLength - 2 else 0
            sequenceLength = 0
        }
    }
    answer += if (sequenceLength > 2) sequenceLength - 2 else 0

    return answer
}

fun main() {
    println("Enter the string:")
    val scan = Scanner(System.`in`)
    val inputString = scan.nextLine()
    try {
        println("You need to remove ${countXToBeDeleted(inputString)} symbols " +
                "so that the string doesn't contain the substring \"xxx\"")
    } catch (exception: IllegalArgumentException) {
        println(exception)
    }
}
