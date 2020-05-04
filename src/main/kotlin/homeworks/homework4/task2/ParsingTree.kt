package homeworks.homework4.task2

import java.io.IOException
import java.io.InputStream
import java.util.Scanner
import kotlin.IllegalStateException

class ParsingTree {
    private var root: Node? = null

    fun calculate() = root?.calculate() ?: throw IllegalStateException("Tree is empty")

    fun parseFile(input: InputStream) {
        val inputString = input.bufferedReader().readLine() ?: throw IOException("Expression not found")
        root = getNode(inputString.substring(1, inputString.lastIndex))
    }

    fun print() = println(root?.toString() ?: throw IllegalStateException("Tree is empty"))

    private fun getNode(input: String): Node {
        var scan = Scanner(input)
        val result: Node = Operator(scan.next()[0])
        if (scan.hasNextInt()) { // Case: "operator number ..."
            result.leftChild = Argument(scan.nextInt())
            if (scan.hasNextInt()) { // Case: "operator number number"
                result.rightChild = Argument(scan.nextInt())
            } else { // Case: "operator number (...)"
                numberThenBracketsHandling(input, result)
            }
        } else { // Case: "operator (...) ..."
            scan = Scanner(input.reversed())
            if (scan.hasNextInt()) { // Case: "operator (...) number"
                bracketsThenNumberHandling(input, result)
            } else { // Case: "operator (...) (...)"
                bracketsThenBracketsHandling(input, result)
            }
        }
        return result
    }

    private fun numberThenBracketsHandling(input: String, result: Node) { // Case: "operator number (...)"
        val operandStartIndex = input.indexOf('(')
        val operandEndIndex = input.lastIndexOf(')')
        result.rightChild = getNode(input.substring(operandStartIndex + 1 until operandEndIndex))
    }

    private fun bracketsThenNumberHandling(input: String, result: Node) { // Case: "operator (...) number"
        val operandStartIndex = input.indexOf('(')
        val operandEndIndex = input.lastIndexOf(')')
        result.leftChild = getNode(input.substring(operandStartIndex + 1 until operandEndIndex))
        val scan = Scanner(input.substring(operandEndIndex + 1))
        result.rightChild = Argument(scan.nextInt())
    }

    private fun bracketsThenBracketsHandling(input: String, result: Node) { // Case: "operator (...) (...)"
        var operandStartIndex = input.indexOf('(')
        var operandEndIndex = input.lastIndexOf(')')
        var balance = 0
        for (i in operandStartIndex until input.lastIndex - operandStartIndex) {
            if (input[i] == '(') {
                balance++
            } else if (input[i] == ')') {
                balance--
            }
            if (balance == 0) {
                operandEndIndex = i
                result.leftChild = getNode(input.substring(operandStartIndex + 1 until operandEndIndex))
                break
            }
        }
        operandStartIndex = input.substring(operandEndIndex + 1).indexOf('(') + operandEndIndex + 1
        operandEndIndex += input.substring(operandEndIndex + 1).lastIndexOf(')') + 1
        result.rightChild = getNode(input.substring(operandStartIndex + 1 until operandEndIndex))
    }
}
