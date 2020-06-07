package homeworks.homework4.task2

import java.io.IOException
import java.io.InputStream
import kotlin.IllegalStateException

class ParsingTree(input: InputStream) {
    private var root: Node

    init {
        root = parseFile(input)
    }

    fun calculate() = root.calculate()

    private fun parseFile(input: InputStream): Node {
        val inputString = input.bufferedReader().readLine() ?: throw IOException("Expression not found")
        return getNode(inputString)
    }

    fun print() = println(root.toString())

    private fun getNode(input: String): Node {
        val currentString = if (input[0] == '(') input.substring(1, input.lastIndex) else input

        if (isNumber(currentString)) {
            return Argument(input.toInt())
        }

        val firstTerm = getTermArea(currentString.substring(2))
        firstTerm.begin += 2
        firstTerm.end += 2

        val secondTerm = getTermArea(currentString.substring(firstTerm.end + 2))
        secondTerm.begin += firstTerm.end + 2
        secondTerm.end += firstTerm.end + 2

        return Operator(
            currentString[0],
            getNode(currentString.substring(IntRange(firstTerm.begin, firstTerm.end))),
            getNode(currentString.substring(IntRange(secondTerm.begin, secondTerm.end)))
        )
    }

    private fun getTermArea(input: String): Area {
        return if (input[0] == '(') {
            getBracketArea(input)
        } else {
            getNumberArea(input)
        }
    }

    private fun getNumberArea(input: String): Area {
        var indexOfEnd = 0
        while (indexOfEnd in input.indices && input[indexOfEnd].isDigit()) {
            indexOfEnd++
        }
        return Area(0, indexOfEnd - 1)
    }

    private fun getBracketArea(input: String): Area {
        var balance = 0
        var indexOfEnd = 0
        while (indexOfEnd in input.indices) {
            if (input[indexOfEnd] == '(') {
                balance++
            } else if (input[indexOfEnd] == ')') {
                balance--
            }
            if (balance == 0) {
                return Area(0, indexOfEnd)
            }
            indexOfEnd++
        }
        return Area(-1, -1)
    }

    private fun isNumber(input: String) = input.toIntOrNull() != null

    private interface Node {
        fun calculate(): Int
    }

    private class Operator(private val sign: Char, var leftChild: Node, var rightChild: Node) : Node {
        override fun toString(): String {
            val leftChildAsString = leftChild.toString()
            val rightChildAsString = rightChild.toString()
            return "($sign $leftChildAsString $rightChildAsString)"
        }

        override fun calculate(): Int {
            val leftResult = leftChild.calculate()
            val rightResult = rightChild.calculate()
            return when (sign) {
                '+' -> leftResult + rightResult
                '-' -> leftResult - rightResult
                '*' -> leftResult * rightResult
                '/' -> leftResult / rightResult
                else -> throw IllegalStateException("Operator sign cannot be recognized")
            }
        }
    }

    private class Argument(private val value: Int) : Node {
        override fun toString() = value.toString()
        override fun calculate() = value
    }
}
