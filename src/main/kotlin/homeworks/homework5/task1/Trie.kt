package homeworks.homework5.task1

import java.io.IOException
import java.io.InputStream
import java.io.OutputStream
import java.io.Serializable
import java.lang.StringBuilder
import java.util.*

class Trie : Serializable {
    private var root = Node()
    var wordCount = 0
        private set

    fun contains(element: String): Boolean {
        if (element.isEmpty()) {
            return root.isTerminal
        }

        var currentNode: Node? = root
        for (symbol in element) {
            currentNode = currentNode?.children?.get(symbol)
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
            currentNode = currentNode?.children?.get(symbol) ?: run {
                val newNode = Node()
                currentNode?.children?.put(symbol, newNode)
                newNode
            }
        }

        wordCount++
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
            currentNode = currentNode?.children?.get(symbol)
        }
        currentNode?.isTerminal = false
        currentNode?.run { howManyStartWithPrefix-- }

        currentNode = root
        for (symbol in element) {
            val nextNode = currentNode?.children?.get(symbol)
            if (nextNode?.howManyStartWithPrefix == 0) {
                currentNode?.children?.remove(symbol)
                break
            } else {
                currentNode = nextNode
            }
        }

        wordCount--
        return true
    }

    fun howManyStartWithPrefix(element: String): Int {
        var currentNode: Node? = root
        for (symbol in element) {
            currentNode = currentNode?.children?.get(symbol)
        }

        return currentNode?.howManyStartWithPrefix ?: 0
    }

    fun writeObject(output: OutputStream) {
        val words = root.getWords()
        if (root.isTerminal) {
            words.push("")
        }
        output.write((words.joinToString(" ") { "'$it'" }).toByteArray())
        output.close()
    }

    fun readObject(input: InputStream) {
        val inputString = input.bufferedReader().readLine() ?: ""
        val scan = Scanner(inputString)
        var currentWord: String
        root = Node()
        while (scan.hasNext()) {
            currentWord = scan.next()
            if (currentWord.length < 2 ||
                currentWord[0].toString() != "'" ||
                currentWord[currentWord.length - 1].toString() != "'"
            ) {
                throw IOException("The word must begin and end with single quotes")
            }
            currentWord = currentWord.substring(1, currentWord.length - 1)
            add(currentWord)
        }
        input.close()
    }

    fun equalToTrie(trieForCompare: Trie) = root.equalToNode(trieForCompare.root)

    private class Node {
        var isTerminal: Boolean = false
        var howManyStartWithPrefix: Int = 0
        val children: MutableMap<Char, Node> = mutableMapOf()

        fun equalToNode(nodeForCompare: Node): Boolean {
            var areEquals = true
            if (nodeForCompare.isTerminal == this.isTerminal && nodeForCompare.children.size == this.children.size) {
                for (pair in nodeForCompare.children) {
                    if (!(this.children[pair.key]?.equalToNode(pair.value) ?: return false)) {
                        areEquals = false
                        break
                    }
                }
            } else {
                areEquals = false
            }

            return areEquals
        }

        fun getWords(): Stack<String> {
            val result = Stack<String>()
            children.forEach {
                if (it.value.isTerminal) {
                    result.push("${it.key}")
                }
                for (word in it.value.getWords()) {
                    result.push("${it.key}$word")
                }
            }
            return result
        }
    }
}
