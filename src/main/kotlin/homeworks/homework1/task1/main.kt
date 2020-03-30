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

fun getArray(): MutableList<Int> {
    val array: MutableList<Int>

    try {
        println("Enter the array:")
        array = readLine()!!.split(' ').map { it.toInt() }.toMutableList()
    } catch (exception: NumberFormatException) {
        println("You need to enter an array of integers")
        exitProcess(0)
    } catch (exception: KotlinNullPointerException) {
        println("You need to enter an array of integers")
        exitProcess(0)
    }

    return array
}

fun MutableList<Int>.reverse(indexOfBegin: Int, indexOfEnd: Int) {
    require(indexOfBegin in 0..(this.size)) {
        "Index of begin mustn't go beyond the bounds of the array"
    }
    require(indexOfEnd in 0..(this.size)) {
        "Index of end mustn't go beyond the bounds of the array"
    }
    require(indexOfBegin <= indexOfEnd) { "Index of begin must not be greater than index of end" }

    this.subList(indexOfBegin, indexOfEnd).reverse()
}

fun swapBeginAndEnd(array: MutableList<Int>, beginLength: Int, endLength: Int) {
    require(beginLength + endLength == array.size) { "The array should be long: ${beginLength + endLength}" }

    array.reverse(0, beginLength)
    array.reverse(beginLength, beginLength + endLength)
    array.reverse(0, beginLength + endLength)
}

fun main() {
    val (beginSegmentLength, endSegmentLength) = getInputData()
    val array = getArray()

    try {
        swapBeginAndEnd(array, beginSegmentLength, endSegmentLength)
    } catch (exception: IllegalArgumentException) {
        println(exception.message)
        exitProcess(0)
    }

    println("Result:")
    print(array.joinToString(" "))
}
