package homeworks.homework1.task4

import java.lang.IllegalArgumentException
import java.util.Scanner

fun isPalindrome(inputString: String): Boolean {
    require(inputString.isNotEmpty()) { "The inputString mustn't be empty" }

    val stringLength = inputString.length
    for (i in 0 until stringLength / 2) {
        if (inputString[i] != inputString[stringLength - i - 1]) return false
    }
    return true
}

fun main() {
    val scan = Scanner(System.`in`)
    println("Enter the string:")
    try {
        println(if (isPalindrome(scan.nextLine())) "Palindrome!" else "Not a palindrome.")
    } catch (exception: IllegalArgumentException) {
        println(exception)
    }
}
