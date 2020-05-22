package homeworks.homework2.task2

import kotlin.system.exitProcess

fun deleteAllLeftEntries(inputArray: List<Any>): List<Any> {
    return inputArray.reversed().toSet().toTypedArray().reversed()
}

fun getArray(): List<Int> {
    val array: List<Int>

    try {
        println("Enter the array:")
        array = readLine()?.split(' ')?.map { it.toInt() }
            ?: throw KotlinNullPointerException("You need to enter an array of integers")
    } catch (exception: NumberFormatException) {
        println("You need to enter an array of integers")
        exitProcess(0)
    } catch (exception: KotlinNullPointerException) {
        println(exception.message)
        exitProcess(0)
    }

    return array
}

fun main() {
    println("Attention! The program works with any type of data, but reads only integers.\n")
    var array = getArray() as List<Any>
    array = deleteAllLeftEntries(array)
    println("Answer:")
    println(array.joinToString(" "))
}
