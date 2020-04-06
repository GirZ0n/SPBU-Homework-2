package tests.test1

fun main() {
    val queue = PriorityQueue<Char>()
    println("Queue empty? ${queue.isEmpty()}")
    queue.enqueue('q', 'q'.toInt())
    queue.enqueue('b', 'b'.toInt())
    queue.enqueue('c', 'c'.toInt())
    queue.enqueue('a', 'a'.toInt())
    queue.print()
    queue.dequeue()
    queue.dequeue()
    queue.print()
    println("First element: ${queue.peek()}")
    queue.dequeue()
    println("Queue empty? ${queue.isEmpty()}")
    queue.dequeue()
    println("Queue empty? ${queue.isEmpty()}")
}
