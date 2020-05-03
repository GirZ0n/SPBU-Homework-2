package homeworks.homework4.task2

class Operator(val sign: Char) : Node() {
    override fun print() = print(sign)
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
