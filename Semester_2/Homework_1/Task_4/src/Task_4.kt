import java.util.*

fun isPalindrome(inputString: String): Boolean {
    val stringLength = inputString.length
    for (i in 0 until stringLength / 2) {
        if (inputString[i] != inputString[stringLength - i - 1]) {
            return false
        }
    }
    return true
}

fun main() {
    val scan = Scanner(System.`in`)
    println("Enter the string:")
    println(if (isPalindrome(scan.nextLine())) "Palindrome!" else "Not a palindrome.")
}