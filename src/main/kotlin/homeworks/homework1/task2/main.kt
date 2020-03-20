package homeworks.homework1.task2

import java.util.Scanner

fun recursiveFactorial(number: Int): Long {
    if (number == 0) return 1
    return number * recursiveFactorial(number - 1)
}

fun iterativeFactorial(number: Int): Long {
    var result = 1L
    for (i in 1..number)
        result *= i
    return result
}

fun main() {
    println("Enter N:")
    val scan = Scanner(System.`in`)
    val number = scan.nextInt()
    if (number < 0) {
        println("Factorial of $number doesn't defined")
        return
    }
    println("$number! = ${recursiveFactorial(number)} (Recursive), ${iterativeFactorial(number)} (Iterative)")
}
