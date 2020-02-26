import java.util.*

fun getInt(): Int {
    var scan = Scanner(System.`in`)
    while (!scan.hasNextInt()) {
        println("Input Error. Try again:")
        scan = Scanner(System.`in`)
    }
    return scan.nextInt()
}

fun getNumber(): Int {
    var number = getInt()
    while (number < 1) {
        println("Error. Enter the number >= 1:")
        number = getInt()
    }
    return number
}

fun getArray(length: Int): Array<Int> {
    val array = Array(length) {0}
    var scan = Scanner(System.`in`)
    var i = 0
    while (i < length){
        while (!scan.hasNextInt()) {
            println("Input Error. Re-enter the array:")
            scan = Scanner(System.`in`)
            array.fill(0)
            i = 0
        }
        array[i] = scan.nextInt()
        i++
    }
    return array
}

fun reverse(array: Array<Int>, begin: Int, end: Int) {
    val lengthOfSegment = end - begin
    for (i in 0 until lengthOfSegment / 2) {
        val tmp = array[begin + i]
        array[begin + i] = array[end - i - 1]
        array[end - i - 1] = tmp
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
    println("Answer:")
    println(array.contentToString())
}