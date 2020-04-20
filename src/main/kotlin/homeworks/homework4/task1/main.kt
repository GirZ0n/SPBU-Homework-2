package homeworks.homework4.task1

fun main() {
    printHelp()
    while (true) {
        return
    }
}

enum class Commands(val code: Int) {
    HELP(0),
    ADD(1),
    REMOVE(2),
    FIND(3),
    CHANGE_HASH_FUNCTION(4),
    PRINT_STATISTICS(5),
    IMPORT(6),
    EXIT(7);
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
