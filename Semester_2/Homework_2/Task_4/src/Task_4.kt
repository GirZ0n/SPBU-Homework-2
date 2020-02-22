import java.util.*
import kotlin.system.exitProcess

fun main() {
    val scan = Scanner(System.`in`)
    println("Enter the string:")
    val string = scan.nextLine()
    val stringLength = string.length
    for (i in 0 until stringLength / 2) {
        if (string[i] != string[stringLength - i - 1]) {
            println("Not a palindrome.")
            exitProcess(0)
        }
    }
    println("Palindrome!")
}