package homeworks.homework1.task1

import java.util.Scanner
import java.util.InputMismatchException
import kotlin.NoSuchElementException
import kotlin.system.exitProcess

fun getNumber(): Int {
    val scan = Scanner(System.`in`)
    val number = scan.nextInt()
    require(number > 0) { "The number must be greater than 0" }
    return number
}

fun reverse(array: List<Int>, indexOfBegin: Int, indexOfEnd: Int): List<Int> {
    val begin = if (indexOfBegin < 0) 0 else indexOfBegin
    val end = if (indexOfEnd > array.size) array.size else indexOfEnd

    val beginSegment = array.subList(0, begin)
    val reversedSegment = array.subList(begin, end).reversed()
    val endSegment = array.subList(end, array.size)

    return beginSegment + reversedSegment + endSegment
}

fun swapStartAndEnd(array: List<Int>, beginLength: Int, endLength: Int): List<Int> {
    require(beginLength + endLength == array.size) { "The array should be long: ${beginLength + endLength}" }
    var answer = array
    answer = reverse(answer, 0, beginLength)
    answer = reverse(answer, beginLength, beginLength + endLength)
    answer = reverse(answer, 0, beginLength + endLength)
    return answer
}

fun main() {
    val beginSegmentLength: Int
    val endSegmentLength: Int
    try {
        println("Enter the value of begin segment:")
        beginSegmentLength = getNumber()
        println("Enter the value of end segment:")
        endSegmentLength = getNumber()
    } catch (exception: IllegalArgumentException) {
        println(exception.message)
        exitProcess(0)
    } catch (exception: InputMismatchException) {
        println("You must enter a number")
        exitProcess(0)
    } catch (exception: NoSuchElementException) {
        println("You must enter a number")
        exitProcess(0)
    }

    var array: List<Int>
    try {
        println("Enter the array:")
        array = readLine()!!.split(' ').map { it.toInt() }
    } catch (exception: NumberFormatException) {
        println("You need to enter an array of integers")
        exitProcess(0)
    } catch (exception: KotlinNullPointerException) {
        println("You need to enter an array of integers")
        exitProcess(0)
    }

    try {
        array = swapStartAndEnd(array, beginSegmentLength, endSegmentLength)
    } catch (exception: IllegalArgumentException) {
        println(exception.message)
        exitProcess(0)
    }

    println("Result:")
    print(array.joinToString(" "))
}
