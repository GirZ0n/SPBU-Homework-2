package homeworks.homework4.task1

import java.io.File
import java.io.FileNotFoundException
import java.util.Scanner

const val INIT_SIZE = 1024
const val FILE_PATH = "./src/main/kotlin/homeworks/homework4/task1/input.txt"

fun main() {
    printHelp()
    val hashTable = HashTable<String, Int>(INIT_SIZE, SimpleHashFunctionForString())
    interactWithTable(hashTable)
}

enum class Commands(val code: String, val description: String) {
    HELP("help", "see this list"),
    ADD("add", "add a new pair"),
    REMOVE("remove", "remove a key"),
    FIND("find", "find the value by key"),
    CHANGE_HASH_FUNCTION("change", "change the hash function"),
    PRINT_STATISTICS("stats", "write statistics"),
    IMPORT("import", "import a hash table from a file"),
    EXIT("exit", "complete the program");
}

fun printHelp() {
    Commands.values().forEach {
        println("Type '${it.code}' to ${it.description}")
    }
}

fun interactWithTable(hashTable: HashTable<String, Int>) {
    var input: String
    val inputFile = File(FILE_PATH)
    while (true) {
        print("> ")
        input = readLine() ?: "exit"
        when (input.toLowerCase()) {
            Commands.HELP.code -> printHelp()
            Commands.ADD.code -> addCodeProcessing(hashTable)
            Commands.REMOVE.code -> removeCodeProcessing(hashTable)
            Commands.FIND.code -> findCodeProcessing(hashTable)
            Commands.CHANGE_HASH_FUNCTION.code -> changeHashFunctionCodeProcessing(hashTable)
            Commands.PRINT_STATISTICS.code -> hashTable.printStatistics()
            Commands.IMPORT.code -> importCodeProcessing(hashTable, inputFile)
            Commands.EXIT.code -> return
            else -> println("Type `${Commands.HELP.code}` to see help list")
        }
    }
}

fun addCodeProcessing(hashTable: HashTable<String, Int>) {
    println("Enter the key (string):")
    val key = readLine()
    println("Enter the value (integer):")
    val value = readLine()?.toInt()
    hashTable.add(key, value)
}

fun removeCodeProcessing(hashTable: HashTable<String, Int>) {
    println("Enter the key (string):")
    val key = readLine()
    hashTable.remove(key)
}

fun findCodeProcessing(hashTable: HashTable<String, Int>) {
    println("Enter the key (string):")
    val key = readLine()
    println("$key: ${hashTable.find(key)}")
}

fun changeHashFunctionCodeProcessing(hashTable: HashTable<String, Int>) {
    println("What hash function do you want to use?")
    println("0: simple hash function, 1: polynomial hash function")
    print("hash function > ")
    when (readLine()?.toInt()) {
        0 -> {
            hashTable.changeHashFunction(SimpleHashFunctionForString())
            println("You have selected a simple hash function")
        }
        1 -> {
            hashTable.changeHashFunction(PolynomialHashFunctionForString())
            println("You have selected a polynomial hash function")
        }
        else -> return
    }
}

fun importCodeProcessing(hashTable: HashTable<String, Int>, input: File) {
    if (!input.exists()) {
        throw FileNotFoundException("Can't open the file")
    }

    val scan = Scanner(input)
    while (scan.hasNext()) {
        val key = scan.next()
        scan.next()
        val value = scan.nextInt()
        hashTable.add(key, value)
    }
}
