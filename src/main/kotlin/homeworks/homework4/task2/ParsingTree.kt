package homeworks.homework4.task2

import java.io.ByteArrayInputStream
import java.io.IOException
import java.io.InputStream
import java.util.Scanner
import kotlin.IllegalStateException

class ParsingTree {
    private var root: Node? = null

    private fun getNode(input: String): Node {
        var scan = Scanner(input)
        val result: Node = Operator(scan.next()[0])
        if (scan.hasNextInt()) {
            result.leftChild = Argument(scan.nextInt())
            if (scan.hasNextInt()) {
                result.rightChild = Argument(scan.nextInt())
            } else {
                val operandStartIndex = input.indexOf('(')
                val operandEndIndex = input.lastIndexOf(')')
                result.rightChild = getNode(input.substring(operandStartIndex + 1 until operandEndIndex))
            }
        } else {
            scan = Scanner(input.reversed())
            if (scan.hasNextInt()) {
                val operandStartIndex = input.indexOf('(')
                val operandEndIndex = input.lastIndexOf(')')
                result.leftChild = getNode(input.substring(operandStartIndex + 1 until operandEndIndex))
                scan = Scanner(input.substring(operandEndIndex + 1))
                result.rightChild = Argument(scan.nextInt())
            } else {
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
        return result
    }

    fun parseFile(input: InputStream) {
        val inputString = input.bufferedReader().readLine() ?: throw IOException("Expression not found")
        root = getNode(inputString.substring(1, inputString.lastIndex))
    }

    fun calculate() = root?.calculate() ?: throw IllegalStateException("Tree is empty")
}

fun main() {
    val input = ByteArrayInputStream("(/ (* 3 2) (+ 1 2))".toByteArray())
    val parsingTree = ParsingTree()
    parsingTree.parseFile(input)
    println(parsingTree.calculate())
}
