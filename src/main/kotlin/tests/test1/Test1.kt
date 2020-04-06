package tests.test1

fun main() {
    val queue = PriorityQueue<String>()
    println("Queue empty? ${queue.isEmpty()}")
    queue.enqueue("q", 1)
    queue.enqueue("b", 10)
    queue.enqueue("c", 3)
    queue.enqueue("a", 1)
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
