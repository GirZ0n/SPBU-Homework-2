package homeworks.homework4.task1

import kotlin.math.pow

const val PRIME_NUMBER = 1073676287.0

class PolynomialHashFunctionForString : HashFunction<String> {
    override fun getHash(element: String): Int {
        var hash = 0
        var index = 0
        for (symbol in element) {
            hash += (symbol.toInt() * PRIME_NUMBER.pow(index)).toInt()
            index++
        }
        return hash
    }
}
