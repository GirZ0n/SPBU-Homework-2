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
        return getNode(inputString.substring(1, inputString.lastIndex))
    }

    fun print() = println(root.toString())

    private fun getNode(input: String): Node {
        if (isNumber(input)) {
            return Argument(input.toInt())
        }

        val currentString = input.substring(1)
        val areasOfInterest = mutableListOf<Pair<Int, Int>>()

        getBracketsIndices(currentString, areasOfInterest)

        if (areasOfInterest.size != 2) {
            getNumbersIndices(currentString, areasOfInterest)
        }

        areasOfInterest.sortWith(compareBy { it.first })

        val i1 = areasOfInterest[0].first
        val j1 = areasOfInterest[0].second
        val i2 = areasOfInterest[1].first
        val j2 = areasOfInterest[1].second

        val node = Operator(input[0])
        node.leftChild = getNode(currentString.substring(i1..j1))
        node.rightChild = getNode(currentString.substring(i2..j2))
        return node
    }

    // Здесь мы ищем первые и второе скобки (возможно не найдём)
    private fun getBracketsIndices(input: String, areasOfInterest: MutableList<Pair<Int, Int>>) {
        var bracketBeginIndex = input.indexOf("(")
        var balance = 0
        var i = bracketBeginIndex
        while (i in input.indices) {
            if (input[i] == '(') {
                balance++
            } else if (input[i] == ')') {
                balance--
            }
            if (balance == 0) {
                areasOfInterest.add(Pair(bracketBeginIndex + 1, i - 1))
                bracketBeginIndex = input.substring(i + 1).indexOf("(") + i + 1
                i = bracketBeginIndex
                balance = 0
                continue
            }
            i++
        }
    }

    // Здесь мы ищем числа (возможно одно или два)
    private fun getNumbersIndices(input: String, areasOfInterest: MutableList<Pair<Int, Int>>) {
        val forbiddenArea = if (areasOfInterest.isNotEmpty()) { // индексы, находящиеся в скобках
            val pair = areasOfInterest[0]
            (pair.first)..(pair.second)
        } else IntRange.EMPTY

        var isNumber = false
        var numberBeginIndex = input.indexOfFirst { it.isDigit() }
        var i = numberBeginIndex
        while (i in input.indices) {
            if (i in forbiddenArea) {
                i++
                continue
            }

            when (input[i].isDigit()) {
                true -> {
                    if (!isNumber) {
                        isNumber = true
                        numberBeginIndex = i
                    }
                }
                false -> {
                    if (isNumber) {
                        isNumber = false
                        areasOfInterest.add(Pair(numberBeginIndex, i - 1))
                    }
                }
            }
            i++
        }

        if (isNumber) {
            areasOfInterest.add(Pair(numberBeginIndex, i - 1))
        }
    }

    private fun isNumber(input: String): Boolean {
        for (char in input) {
            if (!char.isDigit()) {
                return false
            }
        }
        return true
    }

    private interface Node {
        var leftChild: Node?
        var rightChild: Node?
        fun calculate(): Int
        override fun toString(): String
    }

    private class Operator(private val sign: Char) : Node {
        override var leftChild: Node? = null
        override var rightChild: Node? = null

        override fun toString(): String {
            val leftChildAsString = leftChild?.toString() ?: throw IllegalStateException("The left operand is missing")
            val rightChildAsString =
                rightChild?.toString() ?: throw IllegalStateException("The right operand is missing")
            return "($sign $leftChildAsString $rightChildAsString)"
        }

        override fun calculate(): Int {
            val leftResult = leftChild?.calculate() ?: throw IllegalStateException("The left operand is missing")
            val rightResult = rightChild?.calculate() ?: throw IllegalStateException("The right operand is missing")
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
        override var leftChild: Node? = null
        override var rightChild: Node? = null

        override fun toString() = value.toString()
        override fun calculate() = value
    }
}
