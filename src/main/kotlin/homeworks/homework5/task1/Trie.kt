package homeworks.homework5.task1

class Trie {
    private val root = Node()
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

    private data class Node(
        var isTerminal: Boolean = false,
        var howManyStartWithPrefix: Int = 0,
        val children: MutableList<Pair<Char, Node>> = mutableListOf()
    )
}

fun main() {
    val test = Trie()
    test.add("")
    test.add("qwerty")
    test.add("qwert")
    test.add("wqf")
    test.add("wsdf")
    test.add("qw")
    test.remove("qwert")
    println(test.howManyStartWithPrefix("qwertyfg"))
}
