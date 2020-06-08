package homeworks.homework4.task1

class SimpleHashFunctionForString : HashFunction<String> {
    override fun calculateHash(element: String) = element.map { it.toInt() }.sum()
}
