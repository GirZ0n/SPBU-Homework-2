package tests.test1

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class Test1KtTest {

    @Test
    fun PriorityQueueEmpty_EmptyQueue_MustWork() {
        val queue = PriorityQueue<String> ()
        assertEquals(true, queue.isEmpty())
    }

    @Test
    fun PriorityQueueEmpty_NonEmptyQueue1_MustWork() {
        val queue = PriorityQueue<String> ()
        queue.enqueue("a", 1)
        queue.enqueue("q", 1)
        queue.enqueue("asdg", 1)
        queue.enqueue("as", 1)
        queue.enqueue("ewwqrw", 1)
        queue.enqueue("q", 1)
        queue.enqueue("aassf", 1)
        queue.enqueue("pdngs49", 1)

        assertEquals(false, queue.isEmpty())
    }

    @Test
    fun PriorityQueueEmpty_NonEmptyQueue2_MustWork() {
        val queue = PriorityQueue<Int> ()
        queue.enqueue(1, 23536)
        queue.enqueue(2, 35)
        queue.enqueue(5, 0)
        queue.enqueue(4, 234)
        queue.enqueue(1456, 2)
        queue.enqueue(1235, 3)
        queue.enqueue(2, 5)
        queue.enqueue(143, 7)
        queue.enqueue(1, 5)
        queue.enqueue(46, 1)

        assertEquals(false, queue.isEmpty())
    }

    @Test
    fun PriorityQueueEmpty_NonEmptyQueue3_MustWork() {
        val queue = PriorityQueue<Boolean> ()
        queue.enqueue(true, 1)
        queue.enqueue(false, 12)
        queue.enqueue(true, 132)
        queue.enqueue(true, 14)
        queue.enqueue(false, 1321433526)
        queue.enqueue(true, 12)

        assertEquals(false, queue.isEmpty())
    }

    @Test
    fun PriorityQueueEmpty_NonEmptyQueue4_MustWork() {
        val queue = PriorityQueue<Double> ()
        queue.enqueue(3.2352, 12)
        queue.enqueue(23552.0, 0)
        queue.enqueue(212.43, 235)
        queue.enqueue(3124.2352232, 5445)
        queue.enqueue(13243.2352, 511)
        queue.enqueue(2353255323.2352, 56564849)
        queue.enqueue(3.235235253, 61)

        assertEquals(false, queue.isEmpty())
    }

    @Test
    fun PriorityQueuePeek_NonEmptyQueue1_MustWork() {
        val queue = PriorityQueue<String> ()
        queue.enqueue("a", 1)
        queue.enqueue("q", 1)
        queue.enqueue("asdg", 1)
        queue.enqueue("as", 1)
        queue.enqueue("ewwqrw", 1)
        queue.enqueue("q", 1)
        queue.enqueue("aassf", 1)
        queue.enqueue("pdngs49", 1)

        assertEquals("a", queue.peek())
    }

    @Test
    fun PriorityQueuePeek_NonEmptyQueue2_MustWork() {
        val queue = PriorityQueue<Int> ()
        queue.enqueue(1, 23536)
        queue.enqueue(2, 35)
        queue.enqueue(5, 0)
        queue.enqueue(4, 234)
        queue.enqueue(1456, 2)
        queue.enqueue(1235, 3)
        queue.enqueue(2, 5)
        queue.enqueue(143, 7)
        queue.enqueue(1, 5)
        queue.enqueue(46, 1)

        assertEquals(5, queue.peek())
    }

    @Test
    fun PriorityQueuePeek_NonEmptyQueue3_MustWork() {
        val queue = PriorityQueue<Boolean> ()
        queue.enqueue(true, 1)
        queue.enqueue(false, 12)
        queue.enqueue(true, 132)
        queue.enqueue(true, 14)
        queue.enqueue(false, 1321433526)
        queue.enqueue(true, 12)

        assertEquals(true, queue.peek())
    }

    @Test
    fun PriorityQueuePeek_NonEmptyQueue4_MustWork() {
        val queue = PriorityQueue<Double> ()
        queue.enqueue(3.2352, 12)
        queue.enqueue(23552.0, 0)
        queue.enqueue(212.43, 235)
        queue.enqueue(3124.2352232, 5445)
        queue.enqueue(13243.2352, 511)
        queue.enqueue(2353255323.2352, 56564849)
        queue.enqueue(3.235235253, 61)

        assertEquals(23552.0, queue.peek())
    }
}