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

fun getInputData(): Pair<Int, Int> {
    val beginSegmentLength: Int
    val endSegmentLength: Int

    try {
        println("Enter the length of begin segment:")
        beginSegmentLength = getNumber()
        println("Enter the length of end segment:")
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

    return Pair(beginSegmentLength, endSegmentLength)
}

fun getArray(): List<Int> {
    val array: List<Int>

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

    return array
}

fun reverse(array: List<Int>, indexOfBegin: Int, indexOfEnd: Int): List<Int> {
    if (array.isEmpty()) return emptyList()

    require(indexOfBegin >= 0 && indexOfBegin < array.size) {
        "Index of begin mustn't go beyond the bounds of the array"
    }
    require(indexOfEnd > 0 && indexOfEnd <= array.size) {
        "Index of end mustn't go beyond the bounds of the array"
    }
    require(indexOfBegin <= indexOfEnd) { "Index of begin must not be greater than index of end" }

    val beginSegment = array.subList(0, indexOfBegin)
    val reversedSegment = array.subList(indexOfBegin, indexOfEnd).reversed()
    val endSegment = array.subList(indexOfEnd, array.size)

    return beginSegment + reversedSegment + endSegment
}

fun swapBeginAndEnd(array: List<Int>, beginLength: Int, endLength: Int): List<Int> {
    require(beginLength + endLength == array.size) { "The array should be long: ${beginLength + endLength}" }

    var answer = array
    answer = reverse(answer, 0, beginLength)
    answer = reverse(answer, beginLength, beginLength + endLength)
    answer = reverse(answer, 0, beginLength + endLength)

    return answer
}

fun main() {
    val (beginSegmentLength, endSegmentLength) = getInputData()
    var array = getArray()

    try {
        array = swapBeginAndEnd(array, beginSegmentLength, endSegmentLength)
    } catch (exception: IllegalArgumentException) {
        println(exception.message)
        exitProcess(0)
    }

    println("Result:")
    print(array.joinToString(" "))
}
