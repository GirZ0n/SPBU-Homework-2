package homeworks.homework4.task1

import kotlin.math.pow

const val INIT_SIZE = 1024
const val PRIME_NUMBER = 1073676287.0

fun main() {
    printHelp()
    val hashTable = HashTable<String, Int>(INIT_SIZE, ::polynomialHashFunction)
    interactWithTable(hashTable)
}

enum class Commands(val code: String) {
    HELP("help"),
    ADD("add"),
    REMOVE("remove"),
    FIND("find"),
    CHANGE_HASH_FUNCTION("change"),
    PRINT_STATISTICS("stats"),
    IMPORT("import"),
    EXIT("exit");
}

fun printHelp() {
    println("Type `${Commands.HELP.code}` to see this list;")
    println("Type `${Commands.ADD.code}` to add a new pair;")
    println("Type `${Commands.REMOVE.code}` to remove a key;")
    println("Type `${Commands.FIND.code}` to find the value by key;")
    println("Type `${Commands.CHANGE_HASH_FUNCTION.code}` to change the hash function;")
    println("Type `${Commands.PRINT_STATISTICS.code}` to write statistics;")
    println("Type `${Commands.IMPORT.code}` to import a hash table from a file;")
    println("Type `${Commands.EXIT.code}` to complete the program.")
}

fun interactWithTable(hashTable: HashTable<String, Int>) {
    var input: String
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
            hashTable.changeHashFunction(::simpleHashFunction)
            println("You have selected a simple hash function")
        }
        1 -> {
            hashTable.changeHashFunction(::polynomialHashFunction)
            println("You have selected a polynomial hash function")
        }
        else -> return
    }
}

fun simpleHashFunction(inputString: String): Int {
    var hash = 0
    for (symbol in inputString) {
        hash += symbol.toInt()
    }
    return hash
}

fun polynomialHashFunction(inputString: String): Int {
    var hash = 0
    var index = 0
    for (symbol in inputString) {
        hash += (symbol.toInt() * PRIME_NUMBER.pow(index)).toInt()
        index++
    }
    return hash
}
