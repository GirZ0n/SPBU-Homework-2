import java.util.*

fun deleteForbiddenSubstrings(inputString: String): Int {
    var answer = 0
    var sequenceLength = 0
    for (i in inputString.indices) {
        if (inputString[i] == 'x')
            sequenceLength++
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
    println("Answer: ${deleteForbiddenSubstrings(inputString)}")
}