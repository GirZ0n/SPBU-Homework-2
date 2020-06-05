package homeworks.homework4.task1

class SimpleHashFunctionForString : HashFunction<String> {
    override fun getHash(element: String): Int {
        var hash = 0
        for (symbol in element) {
            hash += symbol.toInt()
        }
        return hash
    }
}
