import java.util.*

fun numberOfEntries(inputString: String, char: Char)
        = inputString.length - inputString.replace(char.toString(), "").length

fun removeDuplicateChars(inputString: String): String {
    var newString = inputString
    var index = 0
    while (index < newString.length) {
        if (numberOfEntries(newString, newString[index]) > 1) {
            val prefix = newString.slice(0..index)
            val postfix = newString.slice((index + 1) until newString.length)
            newString = prefix + postfix.replace(newString[index].toString(), "")
        }
        index++
    }
    return newString
}

fun main() {
    val scan = Scanner(System.`in`)
    println("Enter the string:")
    var inputString = scan.nextLine().reversed()
    inputString = removeDuplicateChars(inputString).reversed()
    print("Answer: $inputString")
}