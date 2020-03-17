import java.util.*

fun deleteAllLeftEntries(inputArray: Array<Any>): Array<Any> {
    return inputArray.reversed().toSet().toTypedArray().reversed().toTypedArray()
}

fun main() {
    val scan = Scanner(System.`in`)
    println("Enter the size of the array:")
    var array = Array<Any>(scan.nextInt()) {0}
    println("Attention! The program works with any type of data, but reads only integers.\n")
    println("Enter the array:")
    for (i in array.indices)
        array[i] = scan.nextInt()

    array = deleteAllLeftEntries(array)
    println("Answer:")
    println(array.joinToString(" "))
}