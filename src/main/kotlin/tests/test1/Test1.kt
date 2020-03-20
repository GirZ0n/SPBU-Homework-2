package tests.test1

fun main() {
    val a = PriorityQueue<String> ()
    println("Queue empty? ${a.isEmpty()}")
    println("First element: ${a.peek()}")
    a.enqueue("q", 1)
    a.enqueue("b", 10)
    a.enqueue("c", 3)
    a.enqueue("a", 1)
    a.print()
    a.dequeue()
    a.dequeue()
    a.print()
    println("First element: ${a.peek()}")
    a.dequeue()
    println("Queue empty? ${a.isEmpty()}")
    a.dequeue()
    a.print()
    println("Queue empty? ${a.isEmpty()}")
}