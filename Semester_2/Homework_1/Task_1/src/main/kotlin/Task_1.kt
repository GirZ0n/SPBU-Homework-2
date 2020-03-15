import java.util.*
import kotlin.system.exitProcess

fun getNumber(): Int {
    val scan = Scanner(System.`in`)
    val number = scan.nextInt()
    if (number < 1) {
        println("Error. The number must be greater than 0")
        exitProcess(0)
    }
    return number
}

fun getArray(size: Int): Array<Int> {
    val scan = Scanner(System.`in`)
    val array = Array(size) { 0 }
    for (i in array.indices) {
        array[i] = scan.nextInt()
    }
    return array
}

fun reverse(array: Array<Int>, indexOfBegin: Int, indexOfEnd: Int) {
    val begin = if (indexOfBegin < 0) 0 else indexOfBegin
    val end = if (indexOfEnd > array.size) array.size else indexOfEnd

    val lengthOfSegment = end - begin
    for (i in 0 until lengthOfSegment / 2) {
        val temp = array[begin + i]
        array[begin + i] = array[end - i - 1]
        array[end - i - 1] = temp
    }
}

fun main() {
    println("Enter the value of N:")
    val numberN = getNumber()
    println("Enter the value of M:")
    val numberM = getNumber()
    println("Enter the array:")
    val array = getArray(numberN + numberM)

    reverse(array, 0, numberN)
    reverse(array, numberN, numberN + numberM)
    reverse(array, 0, numberN + numberM)

    println("Result:")
    print(array.joinToString(" "))
}