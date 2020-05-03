package homeworks.homework4.task2

class Argument(val value: Int) : Node() {
    override fun print() = print(value)
    override fun calculate() = value
}
