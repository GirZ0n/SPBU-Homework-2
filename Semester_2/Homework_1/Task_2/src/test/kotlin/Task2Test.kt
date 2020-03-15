import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class Task2Test {

    @Test
    fun recursiveFactorial_FactorialOfTheNumber0_MustWork() {
        assertEquals(1, recursiveFactorial(0))
    }

    @Test
    fun recursiveFactorial_FactorialOfTheNumber1_MustWork() {
        assertEquals(1, recursiveFactorial(1))
    }

    @Test
    fun recursiveFactorial_FactorialOfTheNumber2_MustWork() {
        assertEquals(2, recursiveFactorial(2))
    }

    @Test
    fun recursiveFactorial_FactorialOfTheNumber3_MustWork() {
        assertEquals(6, recursiveFactorial(3))
    }

    @Test
    fun recursiveFactorial_FactorialOfTheNumber4_MustWork() {
        assertEquals(24, recursiveFactorial(4))
    }

    @Test
    fun recursiveFactorial_FactorialOfTheNumber5_MustWork() {
        assertEquals(120, recursiveFactorial(5))
    }

    @Test
    fun recursiveFactorial_FactorialOfTheNumber6_MustWork() {
        assertEquals(720, recursiveFactorial(6))
    }

    @Test
    fun recursiveFactorial_FactorialOfTheNumber7_MustWork() {
        assertEquals(5040, recursiveFactorial(7))
    }

    @Test
    fun recursiveFactorial_FactorialOfTheNumber8_MustWork() {
        assertEquals(40320, recursiveFactorial(8))
    }

    @Test
    fun recursiveFactorial_FactorialOfTheNumber9_MustWork() {
        assertEquals(362880, recursiveFactorial(9))
    }

    @Test
    fun iterativeFactorial_FactorialOfTheNumber0_MustWork() {
        assertEquals(1, iterativeFactorial(0))
    }

    @Test
    fun iterativeFactorial_FactorialOfTheNumber1_MustWork() {
        assertEquals(1, iterativeFactorial(1))
    }

    @Test
    fun iterativeFactorial_FactorialOfTheNumber2_MustWork() {
        assertEquals(2, iterativeFactorial(2))
    }

    @Test
    fun iterativeFactorial_FactorialOfTheNumber3_MustWork() {
        assertEquals(6, iterativeFactorial(3))
    }

    @Test
    fun iterativeFactorial_FactorialOfTheNumber4_MustWork() {
        assertEquals(24, iterativeFactorial(4))
    }

    @Test
    fun iterativeFactorial_FactorialOfTheNumber5_MustWork() {
        assertEquals(120, iterativeFactorial(5))
    }

    @Test
    fun iterativeFactorial_FactorialOfTheNumber6_MustWork() {
        assertEquals(720, iterativeFactorial(6))
    }

    @Test
    fun iterativeFactorial_FactorialOfTheNumber7_MustWork() {
        assertEquals(5040, iterativeFactorial(7))
    }

    @Test
    fun iterativeFactorial_FactorialOfTheNumber8_MustWork() {
        assertEquals(40320, iterativeFactorial(8))
    }

    @Test
    fun iterativeFactorial_FactorialOfTheNumber9_MustWork() {
        assertEquals(362880, iterativeFactorial(9))
    }
}