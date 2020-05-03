package homeworks.homework4.task2

import java.io.IOException
import java.io.InputStream
import java.util.Scanner
import java.util.regex.Pattern
import kotlin.IllegalStateException

class ParsingTree {
    private var root: Node? = null

    private fun getNode(input: String): Node {
        var scan = Scanner(input)
        val result: Node
        when {
            input.matches(Regex("[-+*/] \\(.*?\\) \\(.*?\\)")) -> { // Example: "+ (...) (...)"
                result = Operator(input[0])
                val brackets = Pattern.compile("\\(.*?\\)")
                result.leftChild = getNode(brackets.matcher(input).group().trim { it == '(' || it == ')' })
                result.rightChild = getNode(brackets.matcher(input).group().trim { it == '(' || it == ')' })
            }
            input.matches(Regex("[-+*/] \\(.*?\\) (\\d)+")) -> { // Example: "* (...) 3341"
                result = Operator(input[0])
                val brackets = Pattern.compile("\\(.*?\\)")
                val indexOfEnd = brackets.matcher(input).end()
                result.leftChild = getNode(brackets.matcher(input).group().trim { it == '(' || it == ')' })
                scan = Scanner(input.substring(indexOfEnd + 1))
                result.rightChild = Argument(scan.nextInt())
            }
            input.matches(Regex("[-+*/] (\\d)+ \\(.*?\\)")) -> { // Example: "- 2213 (...)"
                val node = Operator(input[0])
                scan.next()
                node.leftChild = Argument(scan.nextInt())
                val brackets = Pattern.compile("\\(.*?\\)")
                node.rightChild = getNode(brackets.matcher(input).group().trim { it == '(' || it == ')' })
                result = node
            }
            input.matches(Regex("[-+*/]] (\\d)* (\\d)*")) -> { // Example: "/ 12235 32235"
                val node = Operator(input[0])
                scan.next()
                node.leftChild = Argument(scan.nextInt())
                node.rightChild = Argument(scan.nextInt())
                result = node
            }
            else -> throw IOException("Invalid input")
        }
        return result
    }

    fun parseFile(input: InputStream) {
        val inputString = input.bufferedReader().readLine() ?: throw IOException("Expression not found")
        root = getNode(inputString.trim { it == '(' || it == ')' })
    }

    fun calculate() = root?.calculate() ?: throw IllegalStateException("Tree is empty")
}
