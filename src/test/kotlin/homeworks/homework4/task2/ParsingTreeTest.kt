package homeworks.homework4.task2

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*
import java.io.ByteArrayInputStream

internal class ParsingTreeTest {

    @Test
    fun calculate_NumberThenNumber_MustWork() {
        val parsingTree = ParsingTree(ByteArrayInputStream("(+ 3 4)".toByteArray()))
        assertEquals(7, parsingTree.calculate())
    }

    @Test
    fun calculate_NumberThenBrackets_MustWork() {
        val parsingTree = ParsingTree(ByteArrayInputStream("(- 3 (* 4 10))".toByteArray()))
        assertEquals(-37, parsingTree.calculate())
    }

    @Test
    fun calculate_BracketsThenNumber_MustWork() {
        val parsingTree = ParsingTree(ByteArrayInputStream("(/ (* 3 13) 3)".toByteArray()))
        assertEquals(13, parsingTree.calculate())
    }

    @Test
    fun calculate_BracketsThenBrackets_MustWork() {
        val parsingTree = ParsingTree(ByteArrayInputStream("(* (+ 3 13) (/ 144 12))".toByteArray()))
        assertEquals(192, parsingTree.calculate())
    }

    @Test
    fun calculate_ComplexTreeWithAllOperations_MustWork() {
        val parsingTree =
            ParsingTree(ByteArrayInputStream("(* (+ (- 2 5) (/ 10 2)) (/ (+ 43 5) (* 2 6)))".toByteArray()))
        assertEquals(8, parsingTree.calculate())
    }

    @Test
    fun calculate_ComplexTreeWithLotsOfBrackets_MustWork() {
        val parsingTree =
            ParsingTree(ByteArrayInputStream("(* (+ 1 (+ 1 (+ (+ (+ 1 (+ (+ 1 1) 1)) 1) 1))) 10)".toByteArray()))
        assertEquals(80, parsingTree.calculate())
    }
}
