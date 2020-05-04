package homeworks.homework4.task2

class Argument(val value: Int) : Node() {
    override fun toString() = value.toString()
    override fun calculate() = value
}
