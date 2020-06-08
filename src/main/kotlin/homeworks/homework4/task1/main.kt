package homeworks.homework4.task1

import java.io.File
import java.io.FileNotFoundException
import java.util.Scanner

fun main() {
    printHelp()
    val hashTable = HashTable<String, Int>(SimpleHashFunctionForString())
    try {
        interactWithTable(hashTable)
    } catch (exception: FileNotFoundException) {
        println(exception.message)
        interactWithTable(hashTable)
    }
}

enum class Commands(val code: String, val description: String) {
    HELP("help", "see this list"),
    ADD("add", "add a new pair"),
    REMOVE("remove", "remove a key"),
    FIND("find", "find the value by key"),
    CHANGE_HASH_FUNCTION("change", "change the hash function"),
    PRINT_STATISTICS("stats", "write statistics"),
    IMPORT("import", "import a hash table from a file (./src/main/resources/homeworks/homework4/task1/input.txt)"),
    EXIT("exit", "complete the program");
}

fun printHelp() {
    Commands.values().forEach {
        println("Type '${it.code}' to ${it.description}")
    }
}

fun interactWithTable(hashTable: HashTable<String, Int>) {
    val filePath = "./src/main/resources/homeworks/homework4/task1/input.txt"
    var input: String
    val inputFile = File(filePath)
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
    var key = readLine()
    while (key.isNullOrBlank()) {
        println("Please enter a valid key")
        key = readLine()
    }
    println("Enter the value (integer):")
    var value = readLine()
    while (value.isNullOrBlank()) {
        println("Please enter a valid value")
        value = readLine()
    }

    try {
        if (hashTable.add(key, value.toInt())) {
            println("$key: $value - successfully added")
        } else {
            println("The pair is already on the table.")
        }
    } catch (exception: NumberFormatException) {
        println("Failed to add. Value must be number")
        addCodeProcessing(hashTable)
    }
}

fun removeCodeProcessing(hashTable: HashTable<String, Int>) {
    println("Enter the key (string):")
    var key = readLine()
    while (key.isNullOrBlank()) {
        println("Please enter a valid key")
        key = readLine()
    }

    if (hashTable.remove(key)) {
        println("key:$key - successfully removed")
    } else {
        println("The pair is no longer in the table")
    }
}

fun findCodeProcessing(hashTable: HashTable<String, Int>) {
    println("Enter the key (string):")
    var key = readLine()
    while (key.isNullOrBlank()) {
        println("Please enter a valid key")
        key = readLine()
    }
    println("$key: ${hashTable.find(key)}")
}

fun changeHashFunctionCodeProcessing(hashTable: HashTable<String, Int>) {
    println("What hash function do you want to use?")
    println("0: simple hash function, 1: polynomial hash function")
    print("hash function > ")
    try {
        when (readLine()?.toInt()) {
            0 -> {
                hashTable.changeHashFunction(SimpleHashFunctionForString())
                println("You have selected a simple hash function")
            }
            1 -> {
                hashTable.changeHashFunction(PolynomialHashFunctionForString())
                println("You have selected a polynomial hash function")
            }
            else -> {
                println("Something went wrong")
                changeHashFunctionCodeProcessing(hashTable)
            }
        }
    } catch (exception: NumberFormatException) {
        println("Failed to change. Input must be number")
        addCodeProcessing(hashTable)
    }
}

fun importCodeProcessing(hashTable: HashTable<String, Int>, input: File) {
    if (!input.exists()) {
        throw FileNotFoundException("Can't open the file")
    }

    val scan = Scanner(input)
    while (scan.hasNextLine()) {
        val line = scan.nextLine()
        try {
            if (line.matches(Regex("\\w* - \\w*"))) {
                val words = line.split(" - ")
                hashTable.add(words[0], words[1].toInt())
            } else {
                println("String does not match regex (\\w* - \\w)")
                println("Problem line:")
                println(line)
                return
            }
        } catch (exception: NumberFormatException) {
            println("Failed to add. Value must be number")
            println("Problem line:")
            println(line)
            return
        }
    }
    println("File successfully imported")
}
