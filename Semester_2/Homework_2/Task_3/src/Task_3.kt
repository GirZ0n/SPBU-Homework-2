import java.util.*

fun main() {
    val scan = Scanner(System.`in`)
    println("Enter the string:")
    val inputString = scan.nextLine()
    println("Enter the substring:")
    val substring = scan.nextLine()
    println("The number of occurrences = ${inputString.length - inputString.replace(substring, "").length}")
}