package homeworks.homework5.task1

import java.io.IOException
import java.io.InputStream
import java.io.OutputStream
import java.lang.StringBuilder
import java.util.Scanner

class Trie {
    private var root = Node()
    var size = 0
        private set

    fun contains(element: String): Boolean {
        if (element.isEmpty()) {
            return root.isTerminal
        }

        var currentNode: Node? = root
        for (symbol in element) {
            currentNode = currentNode?.children?.find { it.first == symbol }?.second
        }

        return currentNode?.isTerminal ?: false
    }

    fun add(element: String): Boolean {
        if (contains(element)) {
            return false
        }

        var currentNode: Node? = root
        for (symbol in element) {
            currentNode?.run { howManyStartWithPrefix++ }
            val nextNode = currentNode?.children?.find { it.first == symbol }?.second
            currentNode = nextNode ?: run {
                val newNode = Node()
                currentNode?.children?.add(Pair(symbol, newNode))
                newNode
            }
        }

        size++
        currentNode?.isTerminal = true
        currentNode?.run { howManyStartWithPrefix++ }
        return true
    }

    fun remove(element: String): Boolean {
        if (!contains(element)) {
            return false
        }

        var currentNode: Node? = root
        for (symbol in element) {
            currentNode?.run { howManyStartWithPrefix-- }
            currentNode = currentNode?.children?.find { it.first == symbol }?.second
        }
        currentNode?.isTerminal = false
        currentNode?.run { howManyStartWithPrefix-- }

        currentNode = root
        for (symbol in element) {
            val nextNode = currentNode?.children?.find { it.first == symbol }?.second
            if (nextNode?.howManyStartWithPrefix == 0) {
                currentNode?.children?.remove(Pair(symbol, nextNode))
                break
            } else {
                currentNode = nextNode
            }
        }

        size--
        return true
    }

    fun howManyStartWithPrefix(element: String): Int {
        var currentNode: Node? = root
        for (symbol in element) {
            currentNode = currentNode?.children?.find { it.first == symbol }?.second
        }

        return currentNode?.howManyStartWithPrefix ?: 0
    }

    private fun getAllWords(root: Node, words: MutableList<String>, prefix: StringBuilder, position: Int) {
        if (root.isTerminal) {
            words.add(prefix.substring(0, position))
        }

        for (pair in root.children) {
            if (prefix.length <= position) {
                prefix.append(pair.first)
            } else {
                prefix[position] = pair.first
            }
            getAllWords(pair.second, words, prefix, position + 1)
        }
    }

    fun serialise(output: OutputStream) {
        val words = emptyList<String>().toMutableList()
        val prefix = StringBuilder()
        getAllWords(root, words, prefix, 0)
        output.write((words.joinToString(" ") { "'$it'" }).toByteArray())
        output.close()
    }

    private fun String.isWord(): Boolean {
        for (symbol in this) {
            if (!symbol.isLetterOrDigit()) {
                return false
            }
        }
        return true
    }

    fun deserialise(input: InputStream) {
        val inputString = input.bufferedReader().readLine()
        val scan = Scanner(inputString)
        var currentWord: String
        root = Node()
        try {
            while (scan.hasNext()) {
                currentWord = scan.next()
                currentWord = currentWord.substring(1, currentWord.length - 1)
                if (currentWord.isWord()) {
                    add(currentWord)
                } else {
                    throw IOException("Expected word")
                }
            }
        } catch (exception: IOException) {
            println(exception.message)
        }
    }

    private data class Node(
        var isTerminal: Boolean = false,
        var howManyStartWithPrefix: Int = 0,
        val children: MutableList<Pair<Char, Node>> = mutableListOf()
    )
}
