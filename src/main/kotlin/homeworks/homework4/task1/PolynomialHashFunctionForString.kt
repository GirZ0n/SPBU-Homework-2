package homeworks.homework4.task1

import kotlin.math.pow

class PolynomialHashFunctionForString : HashFunction<String> {
    private companion object {
        const val PRIME_NUMBER = 1073676287.0
    }

    override fun getHash(element: String) =
        element.mapIndexed { i, it -> (it.toInt() * PRIME_NUMBER.pow(i)).toInt() }.sum()
}
