package homeworks.homework4.task2

class Operator(val sign: Char) : Node() {
    override fun print() = print(sign)
    override fun calculate(): Int {
        checkNotNull(leftChild) { "The left operand is missing" }
        checkNotNull(rightChild) { "The right operand is missing" }
        return when (sign) {
            '+' -> leftChild.calculate() + rightChild.calculate()
            '-' -> leftChild.calculate() - rightChild.calculate()
            '*' -> leftChild.calculate() * rightChild.calculate()
            '/' -> leftChild.calculate() / rightChild.calculate()
            else -> throw IllegalStateException("Operator sign cannot be recognized")
        }
    }
}
