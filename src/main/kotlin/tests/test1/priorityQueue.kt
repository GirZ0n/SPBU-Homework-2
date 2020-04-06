package tests.test1

class PriorityQueue<T> {
    private var list = ArrayList<Pair<Int, T>>(0)

    fun isEmpty(): Boolean {
        return list.isEmpty()
    }

    fun enqueue(elem: T, priority: Int) {
        list.add(Pair(priority, elem))
        list.sortBy { it.first }
    }

    fun dequeue() {
        if (list.isNotEmpty()) list.removeAt(0) else
            throw ArrayIndexOutOfBoundsException("Priority Queue is empty\n")
    }

    fun peek(): T {
        return if (list.isNotEmpty()) list[0].second else
            throw ArrayIndexOutOfBoundsException("Priority Queue is empty\n")
    }

    fun print() {
        println(
            if (list.isNotEmpty()) list.joinToString(" ") else throw
            ArrayIndexOutOfBoundsException("Priority Queue is empty\n")
        )
    }
}
