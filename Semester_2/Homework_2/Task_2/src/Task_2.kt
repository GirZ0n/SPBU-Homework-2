import java.util.*

fun recursiveFactorial(number: Int): Long {
    if (number == 0)
        return 1
    return number * recursiveFactorial(number - 1)
}

fun iterativeFactorial(number: Int): Long {
    var result = 1L
    for (i in 1..number)
        result *= i
    return result
}

fun getInt(): Int {
    var scan = Scanner(System.`in`)
    while (!scan.hasNextInt()) {
        println("Input Error. Try again:")
        scan = Scanner(System.`in`)
    }
    return scan.nextInt()
}

fun getNumber(): Int {
    var number = getInt()
    while (number < 0) {
        println("Error. Enter the number >= 0:")
        number = getInt()
    }
    return number
}

fun main() {
    println("Enter N:")
    val number = getNumber()
    println("N! = ${recursiveFactorial(number)} (Recursive), ${iterativeFactorial(number)} (Iterative)")
}